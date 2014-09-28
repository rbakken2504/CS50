<?php

    //configuration
    require("../includes/config.php");
    
    if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        //user cash balance
        $balance = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        $balance = $balance[0];
        
        //check for non-empty values
        if(empty($_POST["symbol"]) || empty($_POST["shares"]))
        {
            apologize("You must enter a symbol and number of shares to buy.");
        }
        
        //check for non-negative whole number
        else if(preg_match("/^\d+$/", $_POST["shares"]) == "false")
        {
            apologize("You must enter a whole, non-negative integer number of shares");
        }
        
        //price per share of stock to buy
        $priceOfShare = lookup($_POST["symbol"]);
        
        //check that a valid stock was returned by lookup.
        if(empty($priceOfShare))
        {
            apologize("The symbol you have entered is invalid.");
        }
        else
        {
        
            //cost of transaction
            $cost = $priceOfShare["price"] * $_POST["shares"];
            
            //make sure user has enough cash to make purchase.
            if($balance["cash"] < $cost)
            {
                apologize("You do not have enough funds to make this purchase.");
            }
            //insert/update in db and adjust cash balance.
            else
            {
                $symbol = strtoupper($_POST["symbol"]);
                query("INSERT INTO companies (user_id, symbol, shares) VALUES ( ?, ?, ? ) ON DUPLICATE KEY UPDATE shares = shares + ?", 
                      $_SESSION["id"], $symbol, $_POST["shares"], $_POST["shares"]);
                query("UPDATE users SET cash = cash - ? WHERE id = ?", $cost, $_SESSION["id"]);
                query("INSERT INTO history (transaction, time, symbol, shares, price, user_id) VALUES ( 'BUY', NOW(), ?, ?, ?, ? )",
                      $symbol, $_POST["shares"], $priceOfShare["price"], $_SESSION["id"]);
                redirect("/");
            }
        }
    
    }
    else
    {
        render("buy_form.php", ["title" => "Buy"]);
    }  
?>
