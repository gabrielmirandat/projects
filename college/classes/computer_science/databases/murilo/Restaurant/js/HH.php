<?php
//session_start();
	header('Content-Type: application/json');

	$ctdate = $_GET['cdate'];

	/* Connect to the database */
	$username = "root";
	$password = "";
	$hostname = "localhost"; 

	//connection to the database
	$dbhandle = mysql_connect($hostname, $username, $password) or die("Unable to connect to MySQL");

	//select a database to work with
	$selected = mysql_select_db("restaurant",$dbhandle) or die("Could not select examples");
	
	$ctdate = explode(" ",$ctdate);
	$day = $ctdate[0];
    $time = $ctdate[4];
    $time = str_replace("   CDT","",$time);
    $time = str_replace(":","",$time);

    //Check if it is currently Monday
    if ($day == "Thu")
    {
    	$setfreemeal = "UPDATE `menuitem` 
    					SET `Kids Eat Free` = 1 
    					WHERE `Category_idCategory` = 2 AND `Kids Eat Free` = 0";
    	mysql_query($setfreemeal);	
    	//check current orders to see if quantinty = kids 			
    }
    else
    {
    	$setfreemeal = "UPDATE `menuitem` 
    					SET `Kids Eat Free` = 0 
    					WHERE `Category_idCategory` = 2 AND `Kids Eat Free` = 1";
    	mysql_query($setfreemeal);	
    }	

    //Check if it is HH time 3:59:59 - 6:59:59
    HH("125959", "145959", $time) ? $hhtime = "1/2 off drinks" : $hhtime = "Sorry not Happy Hour"; 


    if($hhtime == "1/2 off drinks")
    { 
    	$changeprice = "UPDATE `menuitem` 
    					SET `Price` = `Price` / 2 ,`HappyHour` = 1 
    					WHERE `Category_idCategory` = 4 AND `HappyHour` = 0";

		mysql_query($changeprice);
    }
    else
    { 
    	$changeprice = "UPDATE `menuitem` 
    					SET `Price` = 1.99,`HappyHour` = 0 
    					WHERE `Category_idCategory` = 4 AND `HappyHour` = 1";
		mysql_query($changeprice);
    }
	
    function HH($t1,$t2,$tn)
    {
		if ($t2 >= $t1) return $t1 <= $tn && $tn < $t2;
     	else return ! ($t2 <= $tn && $tn < $t1);
    }

	mysql_close($dbhandle);
?>