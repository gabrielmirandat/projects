<?php
	/* Code to insert score in database */
	$score = $_POST['dataString'];
	$user = 'root';
	$pass = '';
	$db = 'Scores';
	/* Connect to database and insert score in table */
	$conn = new mysqli('localhost',$user,$pass,$db) or die("Database error");
	$sql = "INSERT INTO `High scores` (`Score`) VALUES ('{$score}')";
	if($conn->query($sql)===TRUE){
		echo "Record inserted successfully";
	}else{
		echo "Error ".$sql."<br>".$conn->error;
	}

	$conn->close();

	exit();
?>