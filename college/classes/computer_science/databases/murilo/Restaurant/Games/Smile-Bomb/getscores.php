<?php

	/* Function to receive AJAX request from client and connect to database, returning an array containing the high scores */
	$user = 'root';
	$pass = '';
	$db = 'Scores';
	/* Create connection to database */
	$conn = new mysqli('localhost',$user,$pass,$db) or die("Database error");

	$retrieve = "SELECT * FROM `High scores` ORDER BY `High scores`.`Score` DESC";
	$result = mysqli_query($conn,$retrieve);
	$arrayscores = array();
	$arrayscores = mysqli_fetch_all($result,MYSQLI_NUM);
	/* Show only the 10 highest scores */
	$finalarray = array_slice($arrayscores,0,10,true);
	echo json_encode($finalarray);
	$conn->close();
	exit();
?>