<!DOCTYPE html>
<html lang="en">
     <head>
     <title>Refill</title>
     <meta charset="utf-8">
     <link rel="icon" href="images/favicon.ico">
     <link rel="shortcut icon" href="images/favicon.ico" />
     <link rel="stylesheet" href="css/touchTouch.css">
     <link rel="stylesheet" href="css/style.css">
     <link rel="stylesheet" type="text/css" href="slick-1.5.0/slick/slick.css">
     <link rel="stylesheet" type="text/css" href="slick-1.5.0/slick/slick-theme.css">
     <script src="js/jquery.js"></script>
     <script src="js/jquery-migrate-1.1.1.js"></script>
     <script src="js/jquery.equalheights.js"></script>
     <script src="js/jquery.ui.totop.js"></script>
     <script src="js/jquery.tabs.min.js"></script>
     <script src="js/touchTouch.jquery.js"></script>
     <script src="js/jquery.easing.1.3.js"></script>
     <script src="js/menuitems.js"></script>
     <script src="js/waiterhandler.js"></script>
     <script src="js/refillhandler.js"></script>
     <script src="js/payhandler.js"></script>
     <script src="js/adshandler.js"></script>
     <script src="js/happyhr.js"></script>
     <script src="slick-1.5.0/slick/slick.min.js"></script>
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
         <li class="bt-icon"><a href="#" class="payorder">Pay</a></li>
         <li class="bt-icon"><a href="Games.html">Games</a></li>
         <li class="bt-icon" id="waiterbutton"><a href="#">Waiter</a></li>
         <li class="current bt-icon"><a href="Refill.php">Refill</a></li>
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

<div class="content"><div class="ic"></div>
  <div class="container_12">
    <div class="grid_12">
      <h3 class="head2">Choose your drink</h3>
    </div>  
             <div class="div-tabs">
              <div  id="tab-1" class="tab-content gallery1">
              	<?php

					$username = "root";
					$password = "";
					$hostname = "localhost"; 
					
					//connection to the database
					$dbhandle = mysql_connect($hostname, $username, $password) 
					  or die("Unable to connect to MySQL");

					//select a database to work with
					$selected = mysql_select_db("restaurant",$dbhandle) or die("Could not select examples");

					//execute the SQL query and return records
					$result = mysql_query("SELECT * FROM `menuitem` WHERE `Category_idCategory`=4");
					//fetch the data from the database
					while ($row = mysql_fetch_array($result)) {

						echo  "<div class='grid_3'> 
								<a href='#'"." class='gal refill' id='refill{$row{'Name'}}'> 
									<img src='images/Drinks/".$row{'Name'}.".jpg'"." alt=''><span></span>
								</a>
								<div class='col2'>
									<span class='col3'>
										<a href='#' class='refill' id='refill{$row{'Name'}}'>".$row{'Name'}."</a>
									</span><br>".$row{'Description'}.
									"<div class='infobutton'>i</div>".
									"<div><span class='calories-inactive{$row{'idMenuItem'}}'>Calories: ".$row{'Nutritional_Info'}."</span></div>"."$".$row{'Price'}.
								"</div>
							</div>";

					}

					mysql_close($dbhandle);
				?>
                  
              </div>

             </div>
        </div>
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