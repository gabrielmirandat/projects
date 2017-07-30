/* Handler to remove the items when a refill notification arrives */
$(document).on("click",".removenot",function(){
	$(this).next().remove();
	$(this).prev().remove();
	$(this).remove();
});