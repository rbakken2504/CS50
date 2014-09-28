<?php

    //configuration
    require("../includes/config.php");
    
    if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        //verify no fields are empty
        if(empty($_POST["oldPass"]) || empty($_POST["newPass"]) || empty($_POST["confirmPass"]))
        {
            apologize("All fields must be filled.");
        }
        //verify newPass and confirmPAss match
        else if($_POST["newPass"] != $_POST["confirmPass"])
        {
            apologize("new password and confirmation fields do not match.");
        }
        //grab old hashed password from table
        $hash = query("SELECT hash FROM users WHERE id = ?", $_SESSION["id"]);
        $hash = $hash[0];
        //check old password entered is correct.
        if($hash["hash"] != crypt($_POST["oldPass"], $hash["hash"]))
        {
            apologize("Your old password is not correct.");
        }
        //update new hash in users table
        else
        {
            query("UPDATE users SET hash = ? WHERE id = ?", crypt($_POST["newPass"]), $_SESSION["id"]);
            render("confirm.php");
        }
    }
    else
    {
        render("password.php", ["title" => "Change Password");
    }

?>
