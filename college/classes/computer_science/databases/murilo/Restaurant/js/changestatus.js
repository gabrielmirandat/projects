$(document).on("click",".status-button",function(){
	/* Convert the order id to a number */
	var orderidS = $(this).attr('id');
	var orderid = orderidS.slice(12);
	/* Convert the status to a number */
	var status = $(this).attr('name').slice(1);

	/* Make AJAX request to update the status */
	$.ajax({
		type: "POST",
		url: "js/statuschange.php",
		data: {'status':status,'orderid':orderid},
		/* Analyze data returned by the php */
		success: function(data){
			/* If status is In Progress, change the name attribute of the button */
			if(data=='In Progress'){
				$('#changestatus'+orderid).attr('name','s'+data);
				$('#orderstatus'+orderid).text("Status: "+data);
			} else if(data=='Complete'){
				/* If status is completed, remove the order from the view because it is completed. We could put a timer here. Change the text of the button, show status for some seconds, then remove automatically */
				$('#changestatus'+orderid).attr('name','s'+data);
				$('#orderstatus'+orderid).text("Status: "+data);
				$("#orderstatus"+orderid).append("<button class='removebutton' id='b"+orderid+"'>Remove</button>");
			}
		}
	});
});