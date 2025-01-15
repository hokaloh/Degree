<?php
session_start();
require 'database.php';

if($_SERVER['REQUEST_METHOD'] === 'POST' && !empty($_POST)) {
    $email = filter_input(INPUT_POST, 'email', FILTER_SANITIZE_STRING);
    $name = filter_input(INPUT_POST, 'name', FILTER_SANITIZE_STRING);
    $password = filter_input(INPUT_POST, 'password', FILTER_SANITIZE_STRING);
    $contact = filter_input(INPUT_POST, 'contact', FILTER_SANITIZE_STRING);
    $gender = filter_input(INPUT_POST, 'gender', FILTER_SANITIZE_STRING);
    $role = filter_input(INPUT_POST, 'role', FILTER_SANITIZE_STRING); 
    try {
        // check if email already exist 
        $stmt = $pdo->prepare("SELECT COUNT(*) FROM users WHERE email = ?");
        $stmt->execute([$email]);
        if ($stmt->fetchColumn() > 0) {
            throw new Exception("Email is already taken. Please choose another.");
        }

        // Insert user into the database
        $stmt = $pdo->prepare("INSERT INTO users (email, name, password, contact_info, gender, role) VALUES (?, ?, ?, ?, ?, ?)");
        $stmt->execute([$email, $name, $password, $contact, $gender, $role]);

        $_SESSION['message'] = "Registration successful!";
        header("Location: register.php");
        exit();
    } catch (Exception $e) {
        $_SESSION['error'] = $e->getMessage();
        header("Location: register.php");
        exit();
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <title>Registration</title>
</head>
<body>
    <!-- Success/Error Messages -->
    <?php if (isset($_SESSION['message'])): ?>
        <p><?= htmlspecialchars($_SESSION['message']) ?></p>
        <?php unset($_SESSION['message']); // clear the message after display!?>
    <?php endif; ?>
    <?php if (isset($_SESSION['error'])): ?>
        <p><?= htmlspecialchars($_SESSION['error']) ?></p>
        <?php unset($_SESSION['error']); // clear the message after display!?>
    <?php endif; ?>

    <h1>Registration Page</h1>
    <form method="POST" action="register.php">
        <label>Email:</label>
        <input type="text" name="email" required><br>
        <label>Name:</label>
        <input type="text" name="name" required><br>
        <label>Password:</label>
        <input type="text" name="password" required><br>
        <label>Contact:</label>
        <input type="text" name="contact" required><br>
        <label>Gender:</label>
        <select name="gender" id="gender" required>
            <option value="male">Male</option>
            <option value="female">Female</option>
        </select><br>
        <label>Role:</label>
        <select name="role" id="role">
            <option value="patient">Patient</option>
            <option value="staff">Staff</option>
            <option value="medicine">Medicine</option>
            <option value="doctor">Doctor</option>
        </select><br>
        <input type="submit" value="Submit">
        <a href="login.php">Login</a>
    </form>
</body>
</html>