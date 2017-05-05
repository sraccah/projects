<?php

function verify($token) {
    include_once 'setup/database.php';
    try {
        $db = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
        $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        $query= $db->prepare("SELECT id FROM users WHERE token=:token");
        $query->execute(array(':token' => $token));
        $user = $query->fetch();
        if ($user == null) {
            return (-1);
        }
        $query->closeCursor();
        $query= $db->prepare("UPDATE users SET verified='y' WHERE id=:id");
        $query->execute(array('id' => $user['id']));
        $query->closeCursor();
        return (0);
    } catch (PDOException $e) {
        return (-2);
    }
}

?>
