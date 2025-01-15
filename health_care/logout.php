<?php
session_start(); // Start the session

// Unset all session variables
session_unset();

// Destroy the session
session_destroy();

// Regenerate the session ID for security
session_regenerate_id(true);

// Redirect the user to the login page
header("Location: index.php");
exit();
?>