<?php 
	
	/* Connect to the database */
	$username = "root";
	$password = "";
	$hostname = "localhost"; 
							
	//connection to the database
	$dbhandle = mysql_connect($hostname, $username, $password) or die("Unable to connect to MySQL");

	//select a database to work with
	$selected = mysql_select_db("restaurant",$dbhandle) or die("Could not select examples");
	
	/* Get the data sent by the AJAX request. Get the status and the order id */
	$status = $_POST['status'];
	$orderid = $_POST['orderid'];
	/* Update the tables in the database according to the value of the status variable */
	if (strcmp($status,'Not Started')==0){
		$query = "UPDATE `diningtabletrack` SET `OrderStatus`='2' WHERE `Order_idOrder`='".$orderid."';";
		mysql_query($query);
		$status = 2;
		$query = "SELECT `OStatus` FROM `orderstatus` WHERE `idOrderStatus`='".$status."';";
		$result = mysql_query($query);
		while($row = mysql_fetch_assoc($result)){
			$statusstring[] = $row;
		}
	}else{
		$query = "UPDATE `diningtabletrack` SET `OrderStatus`='3' WHERE `Order_idOrder`='".$orderid."';";
		mysql_query($query);
		$status = 3;
		$query = "SELECT `OStatus` FROM `orderstatus` WHERE `idOrderStatus`='".$status."';";
		$result = mysql_query($query);
		while($row = mysql_fetch_assoc($result)){
			$statusstring[] = $row;
		}
	}

	echo implode(",",$statusstring[0]);

	mysql_close($dbhandle);
?>