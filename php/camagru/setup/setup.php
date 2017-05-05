#!/usr/bin/php
<?php
include("database.php");

// DATABASE
try {
	$db = new PDO($DB_DSN_DC, $DB_USER, $DB_PASSWORD);
	$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$sql = "CREATE DATABASE IF NOT EXISTS `camagru`";
	$db->exec($sql);
	echo "SUCCESS: Database 'camagru' created !\n";
} catch (PDOException $e) {
	echo "ERROR: Database creation failed with error ->\n".$e->getMessage()."\n";
	exit(1);
}

// USER TABLE
try {
	$db = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$sql = "CREATE TABLE IF NOT EXISTS `users` (
		`id` INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
		`username` VARCHAR(50) NOT NULL,
		`email` VARCHAR(100) NOT NULL,
		`password` VARCHAR(255) NOT NULL,
		`token` VARCHAR(50) NOT NULL,
		`verified` VARCHAR(1) NOT NULL DEFAULT 'n'
	)";
	$db->exec($sql);
	echo "SUCCESS: Table 'users' created !\n";
} catch (PDOException $e) {
	echo "ERROR: 'Users' table creation failed with error -> \n".$e->getMessage()."\n";
	exit(1);
}

// TEST USER
try {
	$db = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$pass = hash("whirlpool", "test");
	$token = uniqid(rand(), true);
	$sql = "INSERT INTO `camagru`.`users` (`username`, `email`, `password`, `token`, `verified`) VALUES ('test', 'test@test.com', '$pass', '$token', 'y')";
	$db->exec($sql);
	echo "SUCCESS: Admin user created !\n";
} catch (PDOException $e) {
	echo "ERROR: Admin user creation failed with error -> \n".$e->getMessage()."\n";
	exit(1);
}

// MONTAGE TABLE
try {
	$db = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$sql = "CREATE TABLE IF NOT EXISTS `montages` (
		`id` INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
		`userid` INT(11) NOT NULL,
		`img` VARCHAR(100) NOT NULL,
		FOREIGN KEY (userid) REFERENCES users(id)
	)";
	$db->exec($sql);
	echo "SUCCESS: Table 'montages' created !\n";
} catch (PDOException $e) {
	echo "ERROR: 'Montages' table creation failed with error -> \n".$e->getMessage()."\n";
	exit(1);
}

// TEST MONTAGE
try {
	$db = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$userid = 1;
	$img = "../style/img/girafe.png";
	$sql = "INSERT INTO `camagru`.`montages` (`userid`, `img`) VALUES ('$userid', '$img')";
	$db->exec($sql);
	$img = "../style/img/ovni3.png";
	$sql = "INSERT INTO `camagru`.`montages` (`userid`, `img`) VALUES ('$userid', '$img')";
	$db->exec($sql);
	echo "SUCCESS: Montage for user id:1 created !\n";
} catch (PDOException $e) {
	echo "ERROR: Montage for user id:1 creation failed with error -> \n".$e->getMessage()."\n";
	exit(1);
}

// COMMENT TABLE
try {
	$db = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$sql = "CREATE TABLE IF NOT EXISTS `comments` (
		`id` INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
		`userid` INT(11) NOT NULL,
		`montageid` INT(11) NOT NULL,
		`comment` VARCHAR(255) NOT NULL,
		FOREIGN KEY (userid) REFERENCES users(id),
		FOREIGN KEY (montageid) REFERENCES montages(id)
	)";
	$db->exec($sql);
	echo "SUCCESS: Table 'comments' created !\n";
} catch (PDOException $e) {
	echo "ERROR: 'Comments' table creation failed with error -> \n".$e->getMessage()."\n";
	exit(1);
}

// LIKE TABLE
try {
	$db = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$sql = "CREATE TABLE IF NOT EXISTS `likes` (
		`id` INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
		`userid` INT(11) NOT NULL,
		`montageid` INT(11) NOT NULL,
		`type` VARCHAR(1) NOT NULL,
		FOREIGN KEY (userid) REFERENCES users(id),
		FOREIGN KEY (montageid) REFERENCES montages(id)
	)";
	$db->exec($sql);
	echo "SUCCESS: Table 'likes' created !\n";
} catch (PDOException $e) {
	echo "ERROR: 'Likes' table creation failed with error -> \n".$e->getMessage()."\n";
	exit(1);
}

?>