<?php session_start(); include_once 'montage/montage.php'; $montages = getMontages(); ?>
<!DOCTYPE html>
<html lang="fr">
<!-- HEADER -->
	<head>
		<?php include("includes/header.html"); ?>
		<title>Montage - Camagru</title>
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
			<?php if(isset($_SESSION['login'])) { ?>
				<div id="options">
					<img class="imgo" src="../style/img/tf.png" alt="tf">
					<input type="radio" id="tfimg" name="img" value="../style/img/tf.png" onclick="checkIn(this)">
					<img class="imgo" src="../style/img/atom.png" alt="atom">
					<input type="radio" id="atomimg" class="atom" name="img" value="../style/img/atom.png" onclick="checkIn(this)">
					<img class="imgo" src="../style/img/fh.png" alt="fh">
					<input type="radio" id="fhimg" class="fh" name="img" value="../style/img/fh.png" onclick="checkIn(this)">
					<img class="imgo" src="../style/img/will.png" alt="will">
					<input type="radio" id="willimg" class="will" name="img" value="../style/img/will.png" onclick="checkIn(this)">
				</div>
				<div id="webcam">
					<div id="nocam" class="red center">No camera !</div>
					<video id="video" width="400" height="300"></video>
					<img id="tf" src="../style/img/tf.png" alt="tf" style="display: none;">
					<img id="atom" src="../style/img/atom.png" alt="atom" style="display: none;">
					<img id="fh" src="../style/img/fh.png" alt="fh" style="display: none;">
					<img id="will" src="../style/img/will.png" alt="will" style="display: none;">
					<a href="#" id="capture" class="video-capture-button">Take the picture !</a>
					<canvas id="canvas" width="400" height="300"></canvas>
					<img src="http://placekitten.com/g/400/300" alt="kitten" id="kitten">
				</div>
				<div id="side">
					<?php
						if ($montages) {
							$display = "";
							for ($i = 0; $montages[$i]; $i++) {
								$class = "montage";
								$display .= "<img class=\"".$class."\" src=\"".$montages[$i]['img']."\">";
							}
							echo $display;
						} else { ?>
						<div class="red">Il n'y a rien a voir ici !</div>
						<?php } ?>
				</div>
			<?php } ?>
		</div>
	<!-- FOOTER -->
		<?php include("includes/footer.php"); ?>
	</body>
</html>