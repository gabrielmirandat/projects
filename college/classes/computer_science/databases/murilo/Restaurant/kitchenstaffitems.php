<?php 

	session_start();
	$username = "root";
	$password = "";
	$hostname = "localhost"; 
	
	//connection to the database
	$dbhandle = mysql_connect($hostname, $username, $password) or die("Unable to connect to MySQL");
	//select a database to work with
	$selected = mysql_select_db("restaurant",$dbhandle) or die("Could not select examples");

	$returnarray = array();

	array_push($returnarray,$_SESSION['orderid']);

	for ($i=0; $i < count($_SESSION['items']);$i++){ 
		array_push($returnarray,$_SESSION['items'][$i]);
		array_push($returnarray,$_SESSION['quantities'][$i]);
		array_push($returnarray,$_SESSION['sides'][$i]);
	}

	// Get status of order
	$query = "SELECT `OrderStatus` FROM `diningtabletrack` WHERE `Order_idOrder`='".$_SESSION['orderid']."' AND `OrderStatus`='1' OR `OrderStatus`='2';";
	$result = mysql_query($query);

	/* Convert status to PHP array */
	while ($row = mysql_fetch_assoc($result)){
		$statusid[] = $row;
	}

	$query = "SELECT `OStatus` FROM `orderstatus` WHERE `idOrderStatus`='".$statusid[0]['OrderStatus']."';";
	$result = mysql_query($query);

	while ($row = mysql_fetch_assoc($result)){
		$status[] = $row;
	}

	array_push($returnarray,$status);
	echo json_encode($returnarray);
	mysql_close($dbhandle);
?>