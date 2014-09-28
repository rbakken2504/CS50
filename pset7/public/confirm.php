<?php


    //This controller just redirects to portfolio after confirming that user's password was changed.
    require("../includes/config.php");
    
    if($_SERVER["REQUEST_METHOD"] == "GET")
    {
        redirect("/");
    }

?>
