var kitchenstaff = setInterval(function(){
	/* Get the ordered items at an interval of 10 seconds */
	$.ajax({url: "kitchenstaffitems.php", 
		type: "GET", success: function(data){
			/* Append the order to the page */
			var element = document.getElementById("order"+data[0]);
			if(element==null){
				$(".ordersK").append("<div id='order"+data[0]+"'>");
				for(var i=1;i<data.length-1;i+=3){
					$("#order"+data[0]).append(data[i]['Name']+" Quantity: "+data[i+1]+" Sides: "+data[i+2]);
					$("#order"+data[0]).append("<br>");
				}
	
				/* Append the status and the status button to the page */
				$("#order"+data[0]).append("<div id='orderstatus"+data[0]+"'>Status: "+data[data.length-1][0]['OStatus'].toString()+"</div><br>");
				$("#order"+data[0]).append("<button name='s"+data[data.length-1][0]['OStatus'].toString()+"' class='status-button' id='changestatus"+data[0]+"'> Update Order Status </button><br>");
				$("#order"+data[0]).append("</div>");
			}

	},dataType: "json"})}, 10000);

$(document).ready(kitchenstaff);