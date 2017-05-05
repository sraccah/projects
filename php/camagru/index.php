<?php session_start(); ?>
<!DOCTYPE html>
<html lang="fr">
<!-- HEADER -->
	<head>
		<?php include("includes/header.html"); ?>
		<title>Index - Camagru</title>
	</head>
	<body>
	<!-- HEADER -->
		<div id="header">
			<h1 class="center">CAMAGRU</h1>
			<div class="right">
				<?php if(isset($_SESSION['login'])) { ?>
					<p>Hello <span style="color: red;"><?php print_r(htmlspecialchars($_SESSION['login'])) ?></span></p>
					<button><a href="connexion/logout.php">Logout</a></button>
				<?php } else { ?>
					<p>You are not connected !</p>
					<button><a href="login.php">Login</a></button>
					 -
					<button><a href="signup.php">Sign Up</a></button>
				<?php } ?>
				<?php if(isset($_SESSION['error'])) {?>
					<p class="red"><?php echo $_SESSION['error'] ?></p>
					<?php $_SESSION['error'] = null; ?>
				<?php } ?>
				<?php if(isset($_SESSION['forgot_success'])) {?>
					<p class="green">A new password as been send to your email</p>
					<?php $_SESSION['forgot_success'] = null; ?>
				<?php } ?>
			</div>
		</div>
	<!-- MAIN -->
		<div id="main">
			<div id="gallery">
				<div class="red">Nothing to see here yet !</div>
			</div>
		</div>
	<!-- FOOTER -->
		<?php include("includes/footer.php"); ?>
	</body>
</html>