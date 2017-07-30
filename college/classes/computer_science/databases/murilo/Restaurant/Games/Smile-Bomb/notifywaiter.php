<?php
	session_start();
	$ntype = $_GET['type'];
	$refill = $_GET['drink'];
	$_SESSION['ntype'] = $ntype;
	$_SESSION['drinkrefill'] = $refill;
	echo "ok";
?>