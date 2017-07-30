var formhandler = function(){
	$(".tips").keyup(function(event){
		if(event.which==13){
			var tipval = $(this).val();
			var idtip = $(this).attr('id').slice(8);
			if(!$.isNumeric(tipval)){
				alert("This is not a number. Please type a valid number");
			} else if(tipval.length>2){
				alert("Please, type a 2 digit number.");
			}else{
				var array_items = [];
				var elements = $(".customers .oneitem");
				if(elements.length!=0){
					$(".customers .oneitem").each(function(index){
						array_items[index] = $(this).attr('id');
					});
					var totalprice=0;
					for(var i=0;i<array_items.length;i++){
						totalprice+=parseFloat(array_items[i]);
					}
	
					var finaltip = Math.round((tipval/100*totalprice)*100)/100;
					$(this).text(finaltip);
					var totalindex = $(".total"+idtip).text().indexOf("$");
					var totalstring = $(".total"+idtip).text().substr(totalindex+1);
					var total = parseFloat(totalstring)+finaltip;
					$(".total"+idtip).text("Total: $"+total);
				}
			}
		}
	});
}

$(document).ready(formhandler);