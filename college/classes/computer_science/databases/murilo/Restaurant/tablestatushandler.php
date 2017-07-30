<?php
	
	session_start();

	/* Connect to the database */
	$username = "root";
	$password = "";
	$hostname = "localhost"; 
	
	//connection to the database
	$dbhandle = mysql_connect($hostname, $username, $password) or die("Unable to connect to MySQL");

	//select a database to work with
	$selected = mysql_select_db("restaurant",$dbhandle) or die("Could not select examples");

	// Get the current table status from the database and echo this to the waiter
	$query = "SELECT `TableStatus_idTableStatus` FROM `diningtable` WHERE `idTable`='{$_SESSION['tableid']}';";
	$result = mysql_query($query);
	while ($row=mysql_fetch_assoc($result)){
		$statusnum[] = $row['TableStatus_idTableStatus'];
	}

	$statusnumimp = implode(", ",$statusnum);

	$query = "SELECT `TStatus` FROM `tablestatus` WHERE `idTableStatus` IN ($statusnumimp);";
	$result = mysql_query($query);

	while($row=mysql_fetch_assoc($result)){
		$statusstring[] = $row['TStatus'];
	}

	$statusstringimp = implode(", ",$statusstring);

	echo json_encode($statusstringimp);

	mysql_close($dbhandle);

 ?>