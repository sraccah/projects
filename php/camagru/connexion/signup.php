<?php
session_start();

function signup($user, $email, $pass, $url) {
	include_once '../setup/database.php';
	include_once 'mail.php';
	$email = strtolower($email);
	try {
		$db = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$query = $db->prepare("SELECT id FROM users WHERE username=:username OR email=:email");
		$query->execute(array(':username' => $user, ':email' => $email));	
		if ($ret = $query->fetch()) {
			$_SESSION['error'] = "ERROR: User ".$user." already exists !";
			$query->closeCursor();
			return (1);
		}
		$query->closeCursor();
		$pass = hash("whirlpool", $pass);
		$query = $db->prepare("INSERT INTO users (username, email, password, token) VALUES (:username, :email, :password, :token)");
		$token = uniqid(rand(), true);
		$query->execute(array(':username' => $user, ':email' => $email, ':password' => $pass, ':token' => $token));
		send_verif_email($email, $user, $token, $url);
		$_SESSION['signup_success'] = true;
		return (0);
	} catch (PDOException $e) {
		$err = $e->getMessage();
		return ($err);
	}
}

$email = $_POST['email'];
$username = $_POST['username'];
$password = $_POST['password'];

// FINIR LA VALIDATION !!!

if ($email == "" || $email == null || $username == "" || $username == null || $password == "" || $password == null) {
	$_SESSION['error'] = "You need to fill all fields";
	header("Location: ../signup.php");
	return ;
}
if(!filter_var($email, FILTER_VALIDATE_EMAIL)) {
	$_SESSION['error'] = "You need to enter a valid email";
	header("Location: ../signup.php");
	return ;
}
if (strlen($username) > 50 || strlen($username) < 3) {
	$_SESSION['error'] = "Username should be beetween 3 and 50 characters";
	header("Location: ../signup.php");
	return ;
}
if (strlen($password) < 3) {
	$_SESSION['error'] = "Password should be beetween 3 and 255 characters";
	header("Location: ../signup.php");
	return ;
}

$url = $_SERVER['HTTP_HOST'].str_replace("/signupinout/signup.php", "", $_SERVER['REQUEST_URI']);

signup($username, $email, $password, $url);

header("Location: ../login.php");

?>