<?php
session_start();

function reset_password($email) {
	include_once '../setup/database.php';
	include_once 'mail.php';
	try {
		$db = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$query= $db->prepare("SELECT id, username FROM users WHERE email=:email AND verified='Y'");
		$email = strtolower($email);
		$query->execute(array(':email' => $email));
		$user = $query->fetch();
		if ($user == null) {
				$query->closeCursor();
				return (1);
		}
		$query->closeCursor();

		$pass = uniqid('');
		$newpass = hash("whirlpool", $pass);

		$query= $db->prepare("UPDATE users SET password=:password WHERE email=:email");
		$query->execute(array(':password' => $newpass, ':email' => $email));
		$query->closeCursor();

		send_newpass_mail($email, $user['username'], $pass);
		return (0);
	} catch (PDOException $e) {
		return ($e->getMessage());
	}
}

$email = $_POST['email'];
$_SESSION['error'] = null;

if (($ret = reset_password($email)) !== 0) {
	if ($ret == 1) {
			$_SESSION['error'] = "ERROR: User not found";
	} else {
			$_SESSION['error'] = "ERROR: internal error";
	}
} else {
	$_SESSION['forgot_success'] = true;
}

header("Location: ../index.php");
?>
