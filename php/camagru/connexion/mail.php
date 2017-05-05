<?php

function send_verif_email($to, $username, $token, $url) {
  $subject = "[CAMAGRU] - Email verification";
  $headers = 'MIME-Version: 1.0'."\r\n";
  $headers .= 'Content-type: text/html; charset=utf-8'."\r\n";
  $headers .= 'From: <sraccah.perso@gmail.com>'."\r\n";
  $message = '
  <html>
    <head>
      <title>'.$subject.'</title>
    </head>
    <body>
      <h1>Hello '.htmlspecialchars($username).'</h1>
      <p>To enable your account please click on the link below</p>
      <a href="http://'.$url.'/verify.php?token='.$token.'">Enable my account</a>
    </body>
  </html>
  ';
  mail($to, $subject, $message, $headers);
}

function send_newpass_mail($to, $username, $password) {
  $subject = "[CAMAGRU] - Reset your password";
  $headers = 'MIME-Version: 1.0'."\r\n";
  $headers .= 'Content-type: text/html; charset=utf-8'."\r\n";
  $headers .= 'From: <sraccah.perso@gmail.com>'."\r\n";
  $message = '
  <html>
    <head>
      <title>'.$subject.'</title>
    </head>
    <body>
      <h1>Hello '.htmlspecialchars($username).'</h1>
      <p>There is your new password : '.$password.'</p>
      <p>Change it as soon as you can to be safe !</p>
    </body>
  </html>
  ';
  mail($to, $subject, $message, $headers);
}

function send_com_mail($to, $username, $comment, $from, $img, $url) {
  $subject = "[CAMAGRU] - New comment";
  $headers = 'MIME-Version: 1.0'."\r\n";
  $headers .= 'Content-type: text/html; charset=utf-8'."\r\n";
  $headers .= 'From: <sraccah.perso@gmail.com>'."\r\n";
  $message = '
  <html>
    <head>
      <title>'.$subject.'</title>
    </head>
    <body>
      <h1>Hello '.htmlspecialchars($username).'</h1>
      <p>A user just commented one of your montage</p>
      <img src="http://'.$url.'/montage/'.$img.'" style="width: 400px;height: 300px;display: block;margin: 20px;"></img>
      <p>'.htmlspecialchars($from).': '.htmlspecialchars($comment).'</p>
    </body>
  </html>
  ';
  mail($to, $subject, $message, $headers);
}

function send_like_mail($to, $username, $from, $img, $url) {
  $subject = "[CAMAGRU] - New comment";
  $headers = 'MIME-Version: 1.0'."\r\n";
  $headers .= 'Content-type: text/html; charset=utf-8'."\r\n";
  $headers .= 'From: <sraccah.perso@gmail.com>'."\r\n";
  $message = '
  <html>
    <head>
      <title>'.$subject.'</title>
    </head>
    <body>
      <h1>Hello '.htmlspecialchars($username).'</h1>
      <p>A user just liked one of your montage</p>
      <img src="http://'.$url.'/montage/'.$img.'" style="width: 400px;height: 300px;display: block;margin: 20px;"></img>
      <p>'.htmlspecialchars($from).'</p>
    </body>
  </html>
  ';
  mail($to, $subject, $message, $headers);
}

?>