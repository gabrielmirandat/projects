<?php
	if(session_id() == ''){
		ini_set('session.gc_maxlifetime',10800);
		session_set_cookie_params(10800);
  		session_start();
  		/* Connect to the database */
  		/*if(!isset($_SESSION['tableid'])){
			$username = "root";
			$password = "";
			$hostname = "localhost"; 
			
			//connection to the database
			$dbhandle = mysql_connect($hostname, $username, $password) or die("Unable to connect to MySQL");
		
			//select a database to work with
			$selected = mysql_select_db("restaurant",$dbhandle) or die("Could not select examples");
	
  			$query = "INSERT INTO `diningtable` (`idTable`, `Payees`, `TableStatus_idTableStatus`) VALUES ('1', '1', '1');";
			mysql_query($query);
			$_SESSION['tableid'] = mysql_insert_id();
			mysql_close($dbhandle);
		}*/

  		/* Make query to generate a dining table */
  		/* Connect to the database */
		/*$username = "root";
		$password = "";
		$hostname = "localhost";
		//connection to the database
		$dbhandle = mysql_connect($hostname, $username, $password) or die("Unable to connect to MySQL");
		//select a database to work with
		$selected = mysql_select_db("restaurant",$dbhandle) or die("Could not select examples");

		$query = "INSERT INTO `diningtable` (`idTable`, `Payees`, `TableStatus_idTableStatus`) VALUES ('1', '1', '1');";
		mysql_query($query);
		$tableid = mysql_insert_id();
		$_SESSION['tableid']=$tableid;
		mysql_close($dbhandle);*/
	 }
?>

<!DOCTYPE html>
<html lang="en">
     <head>
     <title>Home</title>
     <meta charset="utf-8">
     <link rel="icon" href="images/favicon.ico">
     <link rel="shortcut icon" href="images/favicon.ico" />
     <link rel="stylesheet" href="css/style.css">
     <link rel="stylesheet" type="text/css" href="slick-1.5.0/slick/slick.css">
     <link rel="stylesheet" type="text/css" href="slick-1.5.0/slick/slick-theme.css">
     <script src="js/jquery.js"></script>
     <script src="js/jquery-migrate-1.1.1.js"></script>
     <script src="js/jquery.equalheights.js"></script>
     <script src="js/jquery.ui.totop.js"></script>
     <script src="js/jquery.easing.1.3.js"></script>
     <script src="js/waiterhandler.js"></script>
     <script src="js/payhandler.js"></script>
     <script src="js/adshandler.js"></script>
     <script src="js/happyhr.js"></script>
     <script src="slick-1.5.0/slick/slick.min.js"></script>
     <!-- <script src="js/linkhandler.js"></script> -->
     <script>
        $(document).ready(function(){
          $( ".block1" ).mouseover(function() {
            $(this).addClass( "blur" );
          });
          $( ".block1" ).mouseout(function() {
            $(this).removeClass( "blur" );
          });
          $().UItoTop({ easingType: 'easeOutQuart' });
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
      <link rel="stylesheet" media="screen" href="css/ie1.css">
    <![endif]-->
    
     </head>
     <body class="page1">
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
         <li class="current bt-icon"><a href="index.php">Home</a></li>
         <li class="bt-icon"><a href="index-2.php">Menu</a></li>
         <li class="bt-icon"><a href="#" class="payorder">Pay</a></li>
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

<div class="content"><div class="ic"></div>
<a href="index-2.php" class="block1">
  <img src="images/blur_img1.jpg" alt="">
  <span class="price"><span>California Roll</span><span><small>$</small>8.99</span><strong></strong></span>
</a>
<a href="index-2.php" class="block1">
  <img src="images/blur_img2.jpg" alt="">
  <span class="price"><span>Salmon Skin Salad</span><span><small>$</small>5.99</span><strong></strong></span>
</a>
<a href="index-2.php" class="block1">
  <img src="images/blur_img3.jpg" alt="">
  <span class="price"><span>Maccha Ice Cream</span>
<span><small>$</small>4.99</span><strong></strong></span>
</a>

  <!-- <div class="container_12">
    <div class="grid_12">
      <h3>New in Menu</h3>
    </div>
    <div class="grid_3">
      <div class="box maxheight">
        <img src="images/box_img1.jpg" alt="">
        <div class="title">Lorem Ipsum</div>
        Integer convallis orci vel mi nelaoreet, at ornare lorem consequat. Phasellus era nisl auctor vel veliterol. 
        <br>
        <a href="#">More Info</a>
      </div>
    </div>
    <div class="grid_3">
      <div class="box maxheight">
        <img src="images/box_img2.jpg" alt="">
        <div class="title">Aliquamh ante</div>
        Benteger convallis orci veli elaoreet, at ornare loremo konsequat. Phasellus era nisl auctor vel veliterut. 
        <br>
        <a href="#">More Info</a>
      </div>
    </div>
    <div class="grid_3">
      <div class="box maxheight">
        <img src="images/box_img3.jpg" alt="">
        <div class="title">Ulum volutpat</div>
        Hrtolieger convallis omi tem aore, at ornare loren coate. Pasellus era nisl auctor vel veliterolsed pharetra. 
        <br>
        <a href="#">More Info</a>
      </div>
    </div>
    <div class="grid_3">
      <div class="box maxheight">
        <img src="images/box_img4.jpg" alt="">
        <div class="title">Vestibulum volu</div>
        Convallis orci vel mi oreet, at kotornare lorem consequat. Sellus era nisl auctor vel veliterolvenenatis nulla. 
        <br>
        <a href="#">More Info</a>
      </div>
    </div>
  </div>
</div> -->

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