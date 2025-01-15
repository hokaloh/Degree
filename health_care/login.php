<?php
session_start();
require 'database.php';

if($_SERVER['REQUEST_METHOD'] === 'POST' && !empty($_POST)) {
    $email = filter_input(INPUT_POST, 'email', FILTER_SANITIZE_STRING);
    $password = filter_input(INPUT_POST, 'password', FILTER_SANITIZE_STRING);
    
    try{
        // Check if the user exists
        $stmt = $pdo->prepare("SELECT * FROM users WHERE email = ?");
        $stmt->execute([$email]);
        $user = $stmt->fetch();

        if (!$user) {
            throw new Exception("Invalid email or password.");
        }

        // Set Session
        $_SESSION['user_id'] = $user['user_id'];
        $_SESSION['role'] = $user['role'];

        // Redirect based on role
        switch ($user['role']) {
            case 'patient':
                header('Location: patient.php');
                break;
            case 'staff':
                header('Location: staff.php');
                break;
            case 'doctor':
                header('Location: doctor.php');
                break;
            default:
                throw new Exception("Invalid role. Please contact the administrator.");
        }
        exit();


    } catch (Exception $e) {
        $_SESSION['error'] = $e->getMessage();
        header("Location: login.php");
        exit();
    }
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <title>Login</title>
</head>
<body>
    <h1>Login Page</h1>

    <!-- Success/Error Messages -->
    <?php if (isset($_SESSION['message'])): ?>
        <p class="message"><?= htmlspecialchars($_SESSION['message']) ?></p>
        <?php unset($_SESSION['message']); // clear the message after display!?>
    <?php endif; ?>

    <?php if (isset($_SESSION['error'])): ?>
        <p class="error"><?= htmlspecialchars($_SESSION['error']) ?></p>
        <?php unset($_SESSION['error']); ?>
    <?php endif; ?>

    <form method="POST" action="login.php">
        <label>Name:</label>
        <input type="text" name="email" required><br>
        <label>Password:</label>
        <input type="text" name="password" required><br>
        <input type="submit" value="Login">
    </form> <br>
    <p><a href="register.php">Register</a> here if you have not.</p>
</body>
</html>