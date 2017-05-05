<?php session_start(); ?>
<!DOCTYPE html>
<html lang="fr">
<!-- HEADER -->
	<head>
		<?php include("includes/header.html"); ?>
		<title>Login - Camagru</title>
	</head>
	<body>
	<!-- HEADER -->
		<div id="header">
			<h1 class="center">CAMAGRU</h1>
			<div class="right">
				<?php if(isset($_SESSION['login'])) {?>
					<p>Hello <span style="color: red;"><?php print_r(htmlspecialchars($_SESSION['login'])) ?></span></p>
				<?php } else { ?>
					<p>LOGIN</p>
				<?php require_once("includes/login.html"); } ?>
				<?php if(isset($_SESSION['error'])) {?>
					<p class="red"><?php echo $_SESSION['error'] ?></p>
					<?php $_SESSION['error'] = null; ?>
				<?php } ?>
				<?php if(isset($_SESSION['signup_success'])) {?>
					<p class="green">Check your mail to activate your account ;)</p>
					<?php $_SESSION['signup_success'] = null; ?>
				<?php } ?>
			</div>
		</div>
	<!-- MAIN -->
		<div id="main">
		</div>
	<!-- FOOTER -->
		<?php include("includes/footer.php"); ?>
	</body>
</html>