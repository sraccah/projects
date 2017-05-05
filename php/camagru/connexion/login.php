<?php
session_start();

function login($username, $pass) {
	include_once '../setup/database.php';
	try {
		$db = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$query = $db->prepare("SELECT id, username FROM users WHERE username=:username AND password=:password AND verified='y'");
		$pass = hash("whirlpool", $pass);
		$query->execute(array(':username' => $username, ':password' => $pass));
		$user = $query->fetch();
		if ($user == null) {
			$query->closeCursor();
			return (1);
		}
		$query->closeCursor();
		return ($user);
	} catch (PDOException $e) {
		$err = $e->getMessage();
		return ($err);
	}
}

$username = $_POST['username'];
$pass = $_POST['password'];

if (($user = login($username, $pass)) == 1) {
	$_SESSION['error'] = "ERROR: User not found !";
	header("Location: ../login.php");
  	return ;
}
else if (isset($err)) {
	$_SESSION['error'] = $err;
	header("Location: ../login.php");
  	return ;
}
else {
	$_SESSION['login'] = $user['username'];
}

header("Location: ../montage.php");

?>