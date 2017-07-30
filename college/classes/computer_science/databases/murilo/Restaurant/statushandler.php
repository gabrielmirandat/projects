<?php 
		/* Connect to the database */
		$username = "root";
		$password = "";
		$hostname = "localhost"; 
								
		//connection to the database
		$dbhandle = mysql_connect($hostname, $username, $password) or die("Unable to connect to MySQL");
	
		//select a database to work with
		$selected = mysql_select_db("restaurant",$dbhandle) or die("Could not select examples");
		
		$tableid = $_GET['idtable'];

		// Get table id
		$query = "SELECT `OrderStatus` FROM `diningtabletrack` WHERE `Table_idTable`='".$tableid."';";
		$result = mysql_query($query);

		/* Convert statuses to PHP array */
		while ($row = mysql_fetch_assoc($result)){
			$status[] = $row['OrderStatus'];
		}

		// Get status of the order
		$statusimp = implode(", ",$status);

		$query = "SELECT `OStatus` FROM `orderstatus` WHERE `idOrderStatus` IN ($statusimp);";
		$result = mysql_query($query);
		while($row = mysql_fetch_assoc($result)){
			$statusstring[] = $row['OStatus'];
		}

		$statusstringimp = implode(", ",$statusstring);

		// Get order ids
		$query = "SELECT `Order_idOrder` FROM `diningtabletrack` WHERE `OrderStatus` IN ($statusimp);";
		$result = mysql_query($query);

		while ($row = mysql_fetch_assoc($result)){
			$orderids[] = $row['Order_idOrder'];
		}

		$orderidsimp = implode(", ",$orderids);

		$returnarray = array();

		// Put information in array and return the array to javascript
		array_push($returnarray,$statusimp);
		array_push($returnarray,$orderidsimp);

		echo json_encode($returnarray);
	
		mysql_close($dbhandle);
?>