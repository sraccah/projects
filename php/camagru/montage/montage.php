<?php

function addMontage($userid, $img) {
    include_once 'setup/database.php';
	try {
		$db = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$query = $db->prepare("INSERT INTO montages (userid, img) VALUES (:userid, :img)");
		$query->execute(array(':userid' => $userid, ':img' => $img));
		return (0);
	} catch (PDOException $e) {
		$err = $e->getMessage();
		return ($err);
	}
}

function getMontages() {
    include_once 'setup/database.php';
	try {
		$db = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$query = $db->prepare("SELECT userid, img FROM montages");
		$query->execute();
		$i = 0;
		$tab = null;
		while ($ret = $query->fetch()) {
			$tab[$i] = $ret;
			$i++;
		}
		$query->closeCursor();
		return ($tab);
	} catch (PDOException $e) {
		$err = $e->getMessage();
		return ($err);
	}
}

?>