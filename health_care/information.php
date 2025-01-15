<?php
include 'database.php';

class infomation {

    public function getUsers($pdo, $user_id){
        $stmt = $pdo->prepare(
            "SELECT * FROM users WHERE user_id=?"
        );
        $stmt -> execute([$user_id]); 
        return $stmt->fetch();
    }

    public function getAppoitment($pdo, $user_id){
        $stmt = $pdo->prepare(
            "SELECT 
                users.name AS name, 
                appoitments.datetime AS datetime, 
                appoitments.purpose AS purpose,
                appoitments.fees AS fees
            FROM appoitments
            JOIN users ON appoitments.user_id = users.user_id  
            WHERE appoitments.user_id = ?"
        );
        $stmt->execute([$user_id]);
        return $stmt->fetchAll(PDO::FETCH_ASSOC);
    }
    public function getDoctors($pdo){
        $stmt = $pdo->query(
            "SELECT * FROM users WHERE role='doctor'"
        );
        return $stmt->fetchAll(PDO::FETCH_ASSOC);
    }
}

?>