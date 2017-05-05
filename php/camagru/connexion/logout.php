<?php

session_start();

$_SESSION['login'] = null;
unset($_SESSION);

header("Location: ../index.php");

?>