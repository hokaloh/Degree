<?php
session_start();
require 'database.php';

include 'information.php';

// Ensure only staff can access this page
if (!isset($_SESSION['role']) || $_SESSION['role'] !== 'patient') {
    header('Location: index.php');
    exit();
}

// list/delete/update booking appoitment
try{
    $infomation = new infomation(); 
    //get user infomation
    $user = $infomation->getUsers($pdo, $_SESSION['user_id']);  

    // get appoiment information 
    $getAppoiment = $infomation->getAppoitment($pdo, $_SESSION['user_id']); 

    // get information doctor
    $getDoctors = $infomation->getDoctors($pdo); 
} catch (Exception $e) {
    $_SESSION['error'] = $e->getMessage();
}

if($_SERVER['REQUEST_METHOD'] === 'POST' && !empty($_POST)){
    $user_id = filter_input(INPUT_POST, 'user_id', FILTER_SANITIZE_NUMBER_INT);
    $doctor_id = filter_input(INPUT_POST, 'doctor', FILTER_SANITIZE_STRING);
    $fee = filter_input(INPUT_POST, 'fee', FILTER_SANITIZE_STRING);
    $datetime = filter_input(INPUT_POST, 'datetime', FILTER_SANITIZE_STRING);

    try {
        $stmt = $pdo->prepare (
            "INSERT INTO appoiments (datetime, user_id, fees, doctor_id) VALUES (?,?,?,?)"
        );
        $stmt->execute([$datetime, $user_id, $fees, $doctor_id]);
        $_SESSION['message'] = "Booking Appoitment Successful!";
        header("Location: patient.php");
        exit();
    } catch (Exception $e) {
        $_SESSION['error'] = $e->getMessage();
        header("Location: patient.php");
        exit();
    }
}

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Patient Pages</title>
</head>
<body>
    <!-- Success/Error Messages -->
    <?php if (isset($_SESSION['message'])): ?>
    <p class="message"><?= htmlspecialchars($_SESSION['message']) ?></p>
        <?php unset($_SESSION['message']); // clear the message after display!?>
    <?php endif; ?>

    <?php if (isset($_SESSION['error'])): ?>
        <p class="error"><?= htmlspecialchars($_SESSION['error']) ?></p>
        <?php unset($_SESSION['error']); ?>
    <?php endif; ?>

    <h1>Welcome <?php echo $user['name']?></h1>
    <h1>List Your Booked</h1>
    
    <table>
        <tr>
            <th>Name</th>
            <th>Datetime</th>
            <th>Purpose</th>
            <th>Fees</th>
        </tr>
        <?php foreach($getAppoiment as $booked): ?>
            <tr>
                <td><?php echo $booked['name']?></td>
                <td><?php echo $booked['datetime']?></td>
                <td><?php echo $booked['purpose']?></td>
                <td><?php echo $booked['fees']?></td>
            </tr>
        <?php endforeach; ?>
    </table>
    
    <h1>Create an appoiment</h1>
    
    <form action="patient.php">
        <label>Doctors</label>
        <?php foreach($getDoctors as $doctor): ?>
            <select name="doctor">
                <option value="<?php $doctor['user_id']?>"><?php echo $doctor['name']?></option>
            </select><br>
        <?php endforeach;?>
        <label>Consultancy Fees: RM</label>
        <input type="text" name="fee" value="550" readonly><br>
        <label>Datetime</label>
        <input type="datetime-local", name="datetime", value="2025-01-01T12:00"><br>
        <input type="hidden" name="user_id" value="<?php echo $_SESSION['user_id']?>">
        <input type="submit" value="Submit">
    </form>
    

    
</body>
</html>