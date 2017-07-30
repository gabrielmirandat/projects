<?php
	session_start();
	/* This will display the notifications for the waiter according to the type */
	if(isset($_SESSION['ntype'])){
		$type = $_SESSION['ntype'];
		if($type==1){
			echo "1The table {$_SESSION['tableid']} is requesting {$_SESSION['drinkrefill']} refill.";
			unset($_SESSION['ntype']);
			unset($_SESSION['drinkrefill']);
		}
		else if($type==2){
			echo "2The table {$_SESSION['tableid']} is asking for help.";
			unset($_SESSION['ntype']);
			unset($_SESSION['drinkrefill']);
		}
		else if($type==3){
			echo "3The table {$_SESSION['tableid']} is requesting to sing for the birthday.";
			unset($_SESSION['ntype']);
			unset($_SESSION['drinkrefill']);
		}
		else if($type==4){
			echo "4The table {$_SESSION['tableid']} is requesting pay by cash.";
			unset($_SESSION['ntype']);
			unset($_SESSION['drinkrefill']);
		}
		else if($type==5){
			echo "5The table {$_SESSION['tableid']} is requesting TO GO. Their order id is {$_SESSION['orderid']}.";
			unset($_SESSION['ntype']);
			unset($_SESSION['drinkrefill']);
		}

	}else{
		echo "Nothing";
	}
 ?>