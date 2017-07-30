<?php
//session_start();
	$M_id = $_POST['menuid'];
	$aod = $_POST['option'];
	
	/* Connect to the database */
	$username = "root";
	$password = "";
	$hostname = "localhost"; 

	//connection to the database
	$dbhandle = mysql_connect($hostname, $username, $password) or die("Unable to connect to MySQL");

	//select a database to work with
	$selected = mysql_select_db("restaurant",$dbhandle) or die("Could not select examples");
	if($aod == "deleteitem")
	{	
		$removeitem = "UPDATE `menuitem` SET `Available` = 0 WHERE `idMenuitem` = $M_id";
		mysql_query($removeitem);
	}
	else
	{	
		$additem = "UPDATE `menuitem` SET `Available` = 1 WHERE `idMenuitem` = $M_id";
		mysql_query($additem);
	}	
	mysql_close($dbhandle);
?>