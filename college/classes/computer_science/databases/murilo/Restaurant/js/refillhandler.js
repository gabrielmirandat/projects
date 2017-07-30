/* Handler to call the waiter when the user wants a refill */
var refillhandler = function(){
	$(".refill").click(function(){

		if($(this).hasClass("gal")){
			var iditem = [$(this).next().find(":nth-child(4)").children("span").attr("class").slice(17)];
		}else{
			var iditem = [$(this).parent().next().next().next().children("span").attr("class").slice(17)];
		}

		// Set the price of the drink to 0 because it's a refill
		var price = ["0.00"];
		var quantity = ['1'];
		var side = [0];

		// Submit the order so that the waiter and the kitchen are properly notified
		$.ajax({type: "POST",
				url: "js/submitorder.php",
				data: {'itemid':iditem,'price':price,'quantity':quantity,'side':side}
		});

		var drinkname = $(this).attr('id').slice(6);
		console.log(drinkname);
		// Notify the waiter about the refill
		$.ajax({type: "GET",
				url: "notifywaiter.php",
				data: {'type':1,'drink':drinkname},
				success: function(data){
					if(data=="ok"){
						alert("The waiter has been called to refill your drink.");
					}
				}
		});
	});
}

$(document).ready(refillhandler);