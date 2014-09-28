<?php

    //configuration
    require("../includes/config.php");
    
    $rows = query("SELECT * FROM history WHERE user_id = ?", $_SESSION["id"]);
    
    render("history.php", ["title" => "History", "rows" => $rows]);

?>
