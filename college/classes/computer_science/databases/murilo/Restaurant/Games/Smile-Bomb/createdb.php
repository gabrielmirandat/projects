<?php

include "DBIMysqli.class.php";

	$host = 'localhost';
	$user = 'root';
	$pass = '';
	$db = 'Scores';
	$connection = new my_sqli($host,$user,$pass,$db);
	if($connection->connect_error){
		die('Error: ('. $connection->connect_errno.')'. $connection->connect_error);
	}
	$query = "SELECT * FROM `High Scores`";
	if($connection->query($query)){
		echo "Table exists!";
	}else{

		$sql = "CREATE DATABASE `Scores`";
		$connection = new my_sqli($host,$user,$pass,$db);
		$returncreate = $connection->query($sql);
		if(!returncreate){
			die("Could not create database!");
		}
	
		$query = "CREATE TABLE `High Scores`(Score int)";
		$result = $connection->query($query);
		if($result == TRUE){
			echo "Table created successfully";
		}else{
			echo "Database error";
		}

	}

	$connection->close();
	exit();

?>