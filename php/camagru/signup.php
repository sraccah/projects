<?php session_start(); ?>
<!DOCTYPE html>
<html lang="fr">
<!-- HEADER -->
	<head>
		<?php include("includes/header.html"); ?>
		<title>Signup - Camagru</title>
	</head>
	<body>
	<!-- HEADER -->
		<div id="header">
			<h1 class="center">CAMAGRU</h1>
			<div class="right">
				<?php if(isset($_SESSION['login'])) {?>
					<p>Hello <span style="color: red;"><?php print_r(htmlspecialchars($_SESSION['login'])) ?></span></p>
				<?php } else { ?>
					<p>SIGNUP</p>
				<?php require_once("includes/signup.html"); } ?>
				<?php if(isset($_SESSION['error'])) {?>
					<p class="red"><?php echo $_SESSION['error'] ?></p>
					<?php $_SESSION['error'] = null; ?>
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