<?php

	/* Connect to the database */
	$username = "root";
	$password = "";
	$hostname = "localhost"; 
	
	//connection to the database
	$dbhandle = mysql_connect($hostname, $username, $password) or die("Unable to connect to MySQL");

	//select a database to work with
	$selected = mysql_select_db("restaurant",$dbhandle) or die("Could not select examples");

	// Get advertisements from database
	$query = "SELECT * FROM `advertisements`;";
	$result = mysql_query($query);

	while($row = mysql_fetch_assoc($result)){
		$ads[] = $row['advertisement'];
	}

	// Return advertisements to javascript
	foreach ($ads as $a){
		echo $a."|";
	}

	mysql_close($dbhandle);
?>