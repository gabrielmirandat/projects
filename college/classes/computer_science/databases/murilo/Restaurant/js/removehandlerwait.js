// If the table has been paid and the order has been completed, the wait staff can remove the table from his view
$(document).on("click",".removebutton",function(){
	var tableid = $(this).attr('id').slice(1);
	var status = $(this).prev().prev().text().slice(8);
	var tablestatus = $(".tablestatus").text().slice(14);
	if(status=="Complete" && tablestatus=='"Paid"'){
		console.log($(this).parent());
		$(this).parent().remove();
	}
});