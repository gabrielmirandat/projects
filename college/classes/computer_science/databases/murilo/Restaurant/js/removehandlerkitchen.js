// Remove the order once the remove button is clicked
$(document).on("click",".removebutton",function(){
	var orderid = $(this).attr('id').slice(1);
	$("#order"+orderid).remove();
	$(this).remove();
});