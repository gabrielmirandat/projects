// Make AJAX request every 5 seconds to get the table status and update the status in the waiter view
var tablehandler = setInterval(function(){
	$.ajax({url:"tablestatushandler.php",
			type: "GET",
			success: function(data){
				console.log(data);
				if(data=='"Paid"'){
					$(".tablestatus").text("Table Status: "+data);
				}
			}
	});

},5000);