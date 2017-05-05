<?php session_start(); require_once 'connexion/verify.php'; ?>
<!DOCTYPE html>
<html lang="fr">
<!-- HEADER -->
	<head>
		<?php include("includes/header.html"); ?>
		<title>Verify - Camagru</title>
	</head>
	<body>
	<!-- HEADER -->
		<div id="header">
			<h1 class="center">CAMAGRU</h1>
		</div>
	<!-- MAIN -->
		<div id="main">
			<?php if (verify($_GET['token']) == 0) {?>
				<p>You account has been verified !</p>
				<button><a href="login.php">Login</a></button>
			<?php } else { ?>
				<p>You account does not exists !</p>
				<button><a href="signup.php">Sign up</a></button>
			<?php } ?>
		</div>
	<!-- FOOTER -->
		<?php include("includes/footer.php"); ?>
	</body>
</html>