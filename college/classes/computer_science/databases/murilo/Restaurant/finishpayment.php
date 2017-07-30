<?php 
	
	/* Start the session */
	session_start();

	/* Connect to the database */
	$username = "root";
	$password = "";
	$hostname = "localhost"; 
	
	//connection to the database
	$dbhandle = mysql_connect($hostname, $username, $password) or die("Unable to connect to MySQL");

	//select a database to work with
	$selected = mysql_select_db("restaurant",$dbhandle) or die("Could not select examples");

	// Update the table status to paid, after all the items have been paid
	$query = "UPDATE `diningtable` SET `TableStatus_idTableStatus`='2' WHERE `idTable` = '{$_SESSION['tableid']}';";
	mysql_query($query);

	mysql_close($dbhandle);

	echo("DONE");
?>