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
	array_push($returnarray,$_SESSION['tableid']);

	for ($i=0; $i < count($_SESSION['items']);$i++){ 
		array_push($returnarray,$_SESSION['items'][$i]);
		array_push($returnarray,$_SESSION['quantities'][$i]);
		array_push($returnarray,$_SESSION['sides'][$i]);
	}

	/*$query = "SELECT `Order_idOrder` FROM `diningtabletrack` WHERE `Table_idTable`='1';";
	$result = mysql_query($query);
	while ($row = mysql_fetch_assoc($result)){
		$orderid[] = $row['Order_idOrder'];
	}

	$orderids = implode(", ",$orderid);*/

	/* Get status from database */
	$query = "SELECT `OrderStatus` FROM `diningtabletrack` WHERE `Order_idOrder`='{$_SESSION['orderid']}';";
	$result = mysql_query($query);

	/* Convert status to PHP array */
	while ($row = mysql_fetch_assoc($result)){
		$status[] = $row['OrderStatus'];
	}

	$statusimp = implode(", ",$status);

	/* Get the string representation of the status from the database */
	$query = "SELECT `OStatus` FROM `orderstatus` WHERE `idOrderStatus` IN ($statusimp);";
	$result = mysql_query($query);
	while($row = mysql_fetch_assoc($result)){
		$statusstring[] = $row['OStatus'];
	}

	$statusstringimp = implode(", ",$statusstring);

	/* Send data back to the view and close the connection */
	array_push($returnarray,$statusstringimp);
	array_push($returnarray,$_SESSION['orderid']);
	echo json_encode($returnarray);
	mysql_close($dbhandle);
?>