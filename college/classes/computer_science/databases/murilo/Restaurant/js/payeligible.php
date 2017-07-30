<?php 
	// If there is an order id, the user is eligible to pay
	session_start();
	if(isset($_SESSION['orderid'])){
		echo "eligible";
	}else{
		echo "not elibigle";
	}

?>