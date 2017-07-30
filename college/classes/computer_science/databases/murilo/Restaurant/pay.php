<!DOCTYPE html>
<html lang="en">
     <head>
     <title>Pay</title>
     <meta charset="utf-8">
     <link rel="icon" href="images/favicon.ico">
     <link rel="shortcut icon" href="images/favicon.ico" />
     <link rel="stylesheet" href="css/touchTouch.css">
     <link rel="stylesheet" href="css/style.css">
     <script src="js/jquery.js"></script>
     <script src="js/jquery-migrate-1.1.1.js"></script>
     <script src="js/jquery.equalheights.js"></script>
     <script src="js/jquery.ui.totop.js"></script>
     <script src="js/jquery.tabs.min.js"></script>
     <script src="js/touchTouch.jquery.js"></script>
     <script src="js/jquery.easing.1.3.js"></script>
     <script src="js/waiterhandler.js"></script>
     <script src="js/selecthandler.js"></script>
    <!-- <script src="js/tiphandler.js"></script> -->
   	
     <script>
        $(document).ready(function(){

          $().UItoTop({ easingType: 'easeOutQuart' });
         $('.gallery a.gal').touchTouch();
         
       }) 
     </script>
     <!--[if lt IE 8]>
       <div style=' clear: both; text-align:center; position: relative;'>
         <a href="http://windows.microsoft.com/en-US/internet-explorer/products/ie/home?ocid=ie6_countdown_bannercode">
           <img src="http://storage.ie6countdown.com/assets/100/images/banners/warning_bar_0000_us.jpg" border="0" height="42" width="820" alt="You are using an outdated browser. For a faster, safer browsing experience, upgrade for free today." />
         </a>

    <![endif]-->
    <!--[if lt IE 9]>
      <script src="js/html5shiv.js"></script>
      <link rel="stylesheet" media="screen" href="css/ie.css">
    <![endif]-->
    <!--[if lt IE 10]>
      <script src="js/html5shiv.js"></script>
      <link rel="stylesheet" media="screen" href="css/ie1.css">
    <![endif]-->
    
     </head>
     <body class="">
     	<?php 
     		session_start();
     	?>
		<html itemscope itemtype="http://schema.org/Blog">
     	<script>
			!function(d,s,id){
				var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?'http':'https';
				if(!d.getElementById(id)){
				js=d.createElement(s);
				js.id=id;js.src=p+'://platform.twitter.com/widgets.js';
				fjs.parentNode.insertBefore(js,fjs);
				}
			}(document, 'script', 'twitter-wjs');
		</script>
		<div id="fb-root"></div>
			<script>(function(d, s, id) {
			  var js, fjs = d.getElementsByTagName(s)[0];
			  if (d.getElementById(id)) return;
			  js = d.createElement(s); js.id = id;
			  js.src = "//connect.facebook.net/en_US/sdk.js#xfbml=1&version=v2.3&appId=818689564876201";
			  fjs.parentNode.insertBefore(js, fjs);
			}(document, 'script', 'facebook-jssdk'));
		</script>


<!--==============================header=================================-->
 <header> 
  <div class="container_12">
   <div class="grid_12"> 
    <div class="socials">
      <a href="https://twitter.com/intent/tweet?screen_name=duytran_d&text=%23sushimi%20is%20the%20best.%20I%20love%20that" data-related="duytran_d">

    </a>
      <a href='http://www.facebook.com/share.php?u=https://facebook.com/untsushimi'></a>
      <a href="https://plus.google.com/share?url={https://www.facebook.com/untsushimi}" onclick="javascript:window.open(this.href,
  '', 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes,height=600,width=600');return false;"></a>
      
    </div>
    <h1><a href="index.php"><img src="images/logo.png" alt="Boo House"></a> </h1>
    <div class="menu_block">
        <ul>
         <li class="bt-icon"><a href="index.php">Home</a></li>
         <li class="bt-icon"><a href="index-2.php">Menu</a></li>
         <li class="current bt-icon"><a href="#" class="payorder">Pay</a></li>
         <li class="bt-icon"><a href="Games.html">Games</a></li>
         <li class="bt-icon" id="waiterbutton"><a href="#">Waiter</a></li>
         <li class="bt-icon"><a href="Refill.php">Refill</a></li>
         <li class="bt-icon"><a href="Birthday.html" class="birthday">My Birthday</a></li>
         <li class="bt-icon"><a href="Map.html">Map</a></li>
         <li class="bt-icon"><a href="Feedback.html">Feedback</a></li>
        </ul>
    
 	<div class="clear"></div>
	</div>

	<div class="advertisements"></div>


<div class="clear"></div>
          </div>
      </div>
</header>

<!--==============================Content=================================-->

<div class="content">
                <?php
					$username = "root";
					$password = "";
					$hostname = "localhost"; 
					
					//connection to the database
					$dbhandle = mysql_connect($hostname, $username, $password) or die("Unable to connect to MySQL");

					//select a database to work with
					$selected = mysql_select_db("restaurant",$dbhandle) or die("Could not select examples");

					//execute the SQL query and return records
					$result = mysql_query("SELECT `Order_idOrder` FROM `diningtabletrack` WHERE `Table_idTable`='1'");
					//fetch the data from the database
					while ($row = mysql_fetch_assoc($result)){
						$orderid[] = $row['Order_idOrder'];
					}

					$orderidimp = implode(", ",$orderid);

					$result = mysql_query("SELECT `ItemQtn` FROM `orderinfo` WHERE `Order_idOrder` IN ($orderidimp);");
					while ($row = mysql_fetch_assoc($result)){
						$quantity[] = $row;
					}

					$result = mysql_query("SELECT `MenuItem_idMenuItem` FROM `orderinfo` WHERE `Order_idOrder` IN ($orderidimp);");

					while($row = mysql_fetch_assoc($result)){
						$menuitemid[] = $row;
					}

					$menuids = array();

					foreach ($menuitemid as $key => $value) {
						foreach ($value as $k => $v) {
							array_push($menuids,$v);
						}
					}

					$newmenuids = implode(", ", $menuids);

					$result = mysql_query("SELECT `Name` FROM `menuitem` WHERE `idMenuItem` IN ($newmenuids);");

					while($row = mysql_fetch_assoc($result)){
						$names[] = $row['Name'];
					}

					$query = "SELECT `discount` FROM `diningtable` WHERE `idTable`='{$_SESSION['tableid']}'";
					$result = mysql_query($query);

					while($row = mysql_fetch_assoc($result)){
						$discount[] = $row['discount'];
					}

					$query = "SELECT `PriceTotal` FROM `orderinfo` WHERE `Order_idOrder` IN ($orderidimp);";
					$result = mysql_query($query);

					while($row = mysql_fetch_assoc($result)){
						if($discount[0]=='1'){
							$prices[] = round(floatval($row['PriceTotal']/2),2);
						}else{
							$prices[] = round(floatval($row['PriceTotal']),2);
						}
					}

					echo "<div class='ordereditems'> Ordered Items <br><br>";
					for ($i=0; $i < count($names); $i++) { 
						echo "<div class='oneitem'>Name: ".$names[$i]." - Total Price: $".number_format($prices[$i],2)." - Quantity: ".$quantity[$i]['ItemQtn']."</div>";
						echo "<button class='customer1_pay' id='select".$menuids[$i]."'>Cus 1</button>";
						echo "<button class='customer2_pay' id='select2".$menuids[$i]."'>Cus 2</button>";
						echo "<button class='customer3_pay' id='select3".$menuids[$i]."'>Cus 3</button>";
						echo "<button class='customer4_pay' id='select4".$menuids[$i]."'>Cus 4</button>";
					}

					echo "</div>";

					/*foreach ($names as $index){
							echo "<div>Name: ".$names[$index]." Price: ".$prices[$index]." Quantity: ".$quantity."</div>";
							echo "<br>";
					}*/


					mysql_close($dbhandle);
				?>  


			<div class="customers1">
				<div id="customer1">Customer 1</div>
					<br> <br> 
					<div>
						<h2>Tip Calculator</h2>
						<div class ="10_tip">10% Tip:</div>
						<div class ="15_tip">15% Tip:</div>
						<div class ="20_tip">20% Tip:</div>
						Your Tip Amount in Dollar:<input type="text">
						<button class = "enter_button" id="tip1">Enter</button>
					</div>
					<br>
					<div class="taxes1">Taxes: $0</div>
					<div class="total1" >Total: $0</div>
					<div class="total1_after_tip">Total after tip: $0</div>
					<button class="pay_button">Pay Now</button>
					<button class="cash_button">Cash</button>
					<button class="credit_button">Credit</button>
					<button class="receipt_print">Print Receipt</button>
					<button class="receipt_email">Send Receipt to Email</button> 
					<form class="receipt_email_box" ><strong>Customer Email:</strong>
						<input type="text" name="Email">
					</form>
					<button class="submit_email">Email</button> 
					<button class="pickup_order">Order To Go</button> 
					<br>
					<br>
					<div class="order_number"></div>
			</div>
			
			
			
			
			
			<div class="customers2">
				<div id="customer2">Customer 2</div>
					<br> <br> 
					<div>
						<h2>Tip Calculator</h2>
							<div class ="10_tip2">10% Tip:</div>
							<div class ="15_tip2">15% Tip:</div>
							<div class ="20_tip2">20% Tip:</div>
							Your Tip Amount in Dollar:<input type="text">
							<button class = "enter_button" id="tip2">Enter</button>
					</div>
					<br>
					<div class="taxes2">Taxes: $0</div>
					<div class="total2" >Total: $0</div>
					<div class="total2_after_tip">Total after tip: $0</div>
					<button class="pay_button">Pay Now</button>
					<button class="cash_button">Cash</button>
					<button class="credit_button">Credit</button>
					<button class="receipt_print">Print Receipt</button>
					<button class="receipt_email">Send Receipt to Email</button> 
					<form class="receipt_email_box" ><strong>Customer Email:</strong>
						<input type="text" name="Email">
					</form>
					<button class="submit_email">Email</button> 
					<button class="pickup_order">Order To Go</button> 
					<br>
					<br>
					<div class="order_number"></div>
			</div>
			
			
			
			
			<div class="customers3">
				<div id="customer3">Customer 3</div>
				<br> <br> 
				<div>
					<h2>Tip Calculator</h2>
					<div class ="10_tip3">10% Tip:</div>
					<div class ="15_tip3">15% Tip:</div>
					<div class ="20_tip3">20% Tip:</div>
					Your Tip Amount in Dollar:<input type="text">
					<button class = "enter_button" id="tip3">Enter</button>
				</div>
				<br>
				<div class="taxes3">Taxes: $0</div>
				<div class="total3" >Total: $0</div>
				<div class="total3_after_tip">Total after tip: $0</div>
				<button class="pay_button">Pay Now</button>
				<button class="cash_button">Cash</button>
				<button class="credit_button">Credit</button>
				<button class="receipt_print">Print Receipt</button>
				<button class="receipt_email">Send Receipt to Email</button> 
				<form class="receipt_email_box" ><strong>Customer Email:</strong>
				<input type="text" name="Email">
				</form>
				<button class="submit_email">Email</button> 
				<button class="pickup_order">Order To Go</button> 
					<br>
					<br>
					<div class="order_number"></div>
			</div>
			
			
			
			<div class="customers4">
				<div id="customer4">Customer 4</div>
				<br> <br> 
				<div>
					<h2>Tip Calculator</h2>
					<div class ="10_tip4">10% Tip:</div>
					<div class ="15_tip4">15% Tip:</div>
					<div class ="20_tip4">20% Tip:</div>
					Your Tip Amount in Dollar:<input type="text">
					<button class = "enter_button" id="tip4">Enter</button>
				</div>		
				<br> 
				<div class="taxes4">Taxes: $0</div>
				<div class="total4">Total: $0</div>
				<div class="total4_after_tip">Total after tip: $0</div>
				<button class="pay_button">Pay Now</button>
				<button class="cash_button">Cash</button>
				<button class="credit_button">Credit</button>
				<button class="receipt_print">Print Receipt</button>
				<button class="receipt_email">Send Receipt to Email</button> 
				<form class="receipt_email_box" ><strong>Customer Email:</strong>
				<input type="text" name="Email">
				</form>
				<button class="submit_email">Email</button> 
				<button class="pickup_order">Order To Go</button> 
					<br>
					<br>
					<div class="order_number"></div>
			</div>
</div>


<!--==============================footer=================================-->

<footer>    
  <div class="container_12">
    <div class="grid_6 prefix_3">
      <a href="index.html" class="f_logo"><img src="images/f_logo.png" alt=""></a>
      <div class="copy">
      &copy; 2013 | <a href="#">Privacy Policy</a> <br> Website   designed by <a href="http://www.templatemonster.com/" rel="nofollow">TemplateMonster.com</a>
      </div>
    </div>
  </div>
</footer>
     <script>
      $(document).ready(function(){ 
         $(".bt-menu-trigger").toggle(
          function(){
            $('.bt-menu').addClass('bt-menu-open'); 
          }, 
          function(){
            $('.bt-menu').removeClass('bt-menu-open'); 
          } 
        ); 
      }) 
    </script>
			<script type="text/javascript">
		  (function() {
			var po = document.createElement('script'); po.type = 'text/javascript'; po.async = true;
			po.src = 'https://apis.google.com/js/platform.js';
			var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(po, s);
		  })();
		</script>
</body>
</html>