<?php 
	
	/* Start the session and get the variables sent by the request */
	session_start();
	$items = $_POST['itemid'];
	$prices = $_POST['price'];
	$quantities = $_POST['quantity'];
	$sides = $_POST['side'];

	/* Connect to the database */
	$username = "root";
	$password = "";
	$hostname = "localhost"; 
	
	//connection to the database
	$dbhandle = mysql_connect($hostname, $username, $password) or die("Unable to connect to MySQL");

	//select a database to work with
	$selected = mysql_select_db("restaurant",$dbhandle) or die("Could not select examples");

	if(!isset($_SESSION['tableid'])){
		$query = "INSERT INTO `diningtable` (`idTable`, `Payees`, `TableStatus_idTableStatus`, `discount`) VALUES ('1', '1', '1','0');";
		mysql_query($query);
		$tableid = mysql_insert_id();
		$_SESSION['tableid'] = $tableid;
	}

	$tableid = 1;
	/* Make the query to generate an order */	
	$query = "INSERT INTO `order` (`idOrder`) VALUES (NULL);";
	mysql_query($query);
	/* Store order ID in a variable */
	$orderid = mysql_insert_id();
	/* Make query to generate a diningtabletrack, which will "bind" a tableID with an Order ID. Also, this will contain the status of the order. */
	$query = "INSERT INTO `diningtabletrack` (`idDiningTableTrack`, `Table_idTable`, `Order_idOrder`,`OrderStatus`) VALUES (NULL, '{$tableid}', '{$orderid}','1');";
	mysql_query($query);
	/* Get the ID of the tracker */
	$diningtrackid = mysql_insert_id();

	/* Insert the ordered items in the table */
	for($i=0; $i<count($items); $i++) {
		$total = $prices[$i]*$quantities[$i];
  		$query = "INSERT INTO `orderinfo` (`idSerial`, `ItemQtn`, `PriceTotal`, `Order_idOrder`, `MenuItem_idMenuItem`) VALUES (NULL, '".$quantities[$i]."', "."'".$total."', "."'".$orderid."', "."'".$items[$i]."');";
  		mysql_query($query);
	}

	/* Get the names of the ordered items */
	$itemsimp = implode(", ",$items);
	$query = "SELECT `Name` FROM `menuitem` WHERE `idMenuItem` IN ($itemsimp);";
	$result = mysql_query($query);

	/* Convert names to PHP array */
	while ($row = mysql_fetch_assoc($result)){
		$itemnames[] = $row;
	}

	/* Store name of the items and ID of the order in session variables */
	if(isset($_SESSION['items']) && isset($_SESSION['quantities']) && isset($_SESSION['sides']) && isset($_SESSION['orderid']) && isset($_SESSION['tableid'])){
   		unset($_SESSION['items']);
   		unset($_SESSION['quantities']);
   		unset($_SESSION['sides']);
   		unset($_SESSION['orderid']);
   		unset($_SESSION['tableid']);
	}

	$_SESSION['items'] = $itemnames;
	$_SESSION['orderid'] = $orderid;
	$_SESSION['quantities'] = $quantities;
	$_SESSION['sides'] = $sides;
	$_SESSION['tableid'] = $tableid;

	mysql_close($dbhandle);

 ?>