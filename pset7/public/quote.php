<?php

    //configuration
    require("../includes/config.php");
    
    //if form was submitted
    if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if(empty($_POST["symbol"]))
        {
            apologize("Symbol must not be blank.");
        }
        else
        {
            $quote = lookup($_POST["symbol"]);
            if(empty($_POST["symbol"]))
            {
                apologize("The symbol you entered was not valid.");
            }
            else
            {
                render("quote_result.php", ["title" => "Quote", 
                                            "price" => $quote["price"],
                                            "name" => $quote["name"],
                                            "symbol" => $quote["symbol"]]);
            }
                                        
        }
    }
    else
    {
        render("quote_form.php", ["title" => "Quote"]);
    }

?>
