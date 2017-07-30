<?php

	/* Get the name and the ID sent in the AJAX request */
	$requestname = $_POST['name'];
	$requestid = $_POST['id'];

	/* Connect to the database and retrieve the item that was clicked */
	$username = "root";
	$password = "";
	$hostname = "localhost"; 
	
	/* Perform connection to the database */
	$dbhandle = mysql_connect($hostname, $username, $password) or die("Unable to connect to MySQL");
	/* Choose the Restaurant database */
	$selected = mysql_select_db("Restaurant",$dbhandle) or die("Could not select examples");
	/* Query the database to return the product */
	$result = mysql_query("SELECT * FROM `Product` WHERE `name`=".'"'.$requestname.'"');
	if(!$result){
		die("Invalid Query".mysql_error());
	}
	/* Encapsulate the results in a JSON array and echo to the client */
	while ($row = mysql_fetch_assoc($result)){
		$arr = ["Name" => $requestname,"Id" => $requestid,"Cal" => $row['nutritional_info']];
		echo json_encode($arr);
	}	

	mysql_close($dbhandle);
?>