<?php

    // configuration
    require("../includes/config.php"); 
    
    $positions = [];
    $rows = query("SELECT * FROM companies WHERE user_id = ?", $_SESSION["id"]);
    $user = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    
    //grab each row from companies table, and store into positions associative array.
    foreach($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"]
                
            ];
        }
    }

    // render portfolio
    render("portfolio.php", ["title" => "Portfolio", "positions" => $positions, "user" => $user[0]]);

?>
