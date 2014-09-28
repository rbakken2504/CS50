<?php
    //configuration
    require("../includes/config.php");
   
    $rows = query("SELECT * FROM companies WHERE user_id = ?", $_SESSION["id"]);
    
    if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        //for each row in companies table
        foreach($rows as $row)
        {
            $share = lookup($row["symbol"]);
            $sale = $share["price"] * $row["shares"];
            
            //if share does not exist, the user does not own it.
            if($share !== false)
            {
                //sell all shares of stocks checked.
                if(isset($_POST[$row["symbol"]]))
                {
                    $symbol = strtoupper($row["symbol"]);
                    query("UPDATE users SET cash = cash + ? WHERE id = ?", $sale, $_SESSION["id"]);
                    query("DELETE FROM companies WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $row["symbol"]);
                    query("INSERT INTO history (transaction, time, symbol, shares, price, user_id) VALUES ( 'SELL', NOW(), ?, ?, ?, ? )",
                          $symbol, $row["shares"], $share["price"], $_SESSION["id"]); 
                }
            }
        }
        redirect("/");
    }
    else
    {  
        render("sell_form.php", ["title" => "Sell", "stocks" => $rows]);
    }
?>
