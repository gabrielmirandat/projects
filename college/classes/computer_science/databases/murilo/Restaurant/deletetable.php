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


	// Queries to delete all the tables associated with the current table id
	$query = "SELECT `Order_idOrder` FROM `diningtabletrack` WHERE `Table_idTable`='{$_SESSION['tableid']}';";
	$result = mysql_query($query);
	while($row=mysql_fetch_assoc($result)){
		$orderids[] = $row['Order_idOrder'];
	}

	$orderidimp = implode(", ",$orderids);

	$query = "DELETE FROM `diningtabletrack` WHERE `Table_idTable`='{$_SESSION['tableid']}';";
	mysql_query($query);

	$query = "DELETE FROM `diningtable` WHERE `idTable`='{$_SESSION['tableid']}';";
	mysql_query($query);

	$query = "DELETE FROM `orderinfo` WHERE `Order_idOrder` IN ($orderidimp);";
	mysql_query($query);

	$query = "DELETE FROM `order` WHERE `idOrder` IN ($orderidimp);";
	mysql_query($query);

	// Finish the user session
	$_SESSION = array();
	if (isset($_COOKIE[session_name()])) { 
    	$params = session_get_cookie_params();
    	setcookie(session_name(), '', 1, $params['path'], $params['domain'], $params['secure'], isset($params['httponly']));
	}
	session_destroy();

	mysql_close($dbhandle);

	echo "OVER";

 ?>