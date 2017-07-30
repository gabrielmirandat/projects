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

	// Insert discount into table
	if(!isset($_SESSION['tableid'])){
		$query = "INSERT INTO `diningtable` (`idTable`, `Payees`, `TableStatus_idTableStatus`, `discount`) VALUES ('1', '1', '1','0');";
		mysql_query($query);
		$tableid = mysql_insert_id();
		$_SESSION['tableid'] = $tableid;
	}

	// Put the discount in the order
	$query = "UPDATE `diningtable` SET `discount`='1' WHERE `idTable`='{$_SESSION['tableid']}';";
	mysql_query($query);
	mysql_close($dbhandle);

	echo "ok";
?>