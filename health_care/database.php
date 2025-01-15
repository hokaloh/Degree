<?php

$hostname='localhost';
$port = 33066; 
$user ='root';
$password = '';
$db = 'healthcare';

try {
    $pdo = new PDO("mysql:host=$hostname;port=$port;dbname=$db", $user, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); // Enable error reporting
    //echo "Database connected successfully!"; // TEMPORARY: For testing purposes
} catch (PDOException $e) {
    die("Database connection failed: " . $e->getMessage());
}
?>