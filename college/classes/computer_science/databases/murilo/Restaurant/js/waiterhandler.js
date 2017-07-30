var func = function(){

	// If the user clicks the button to call the waiter, handle this notification
	$("#waiterbutton").click(function(){
		$.ajax({type: "GET",
				url: "notifywaiter.php",
				data: {'type':2,'drink':"NoDrink"},
				success: function(data){
					if(data=="ok"){
						alert("The waiter has been called to assist you.");
					}
				}	
		});
	});

	// If the customer asks for the wait staff to sing
	$(".sing").click(function(){
		$.ajax({type: "GET",
				url: "notifywaiter.php",
				data: {'type':3,'drink':"NoDrink"},
				success: function(data){
					if(data=="ok"){
						alert("The waiters have been called to sing for you.");
					}
				}
		});
	});

	// If the customer clicks the 50% off discount
	$(".discount").click(function(){
		$.ajax({type: "POST",
				url: "js/discountbirthday.php",
				success: function(data){
					if(data=="ok"){
						alert("Now your entire meal will be 50% off.");
					}
				}
		});
	})

	// When the customer clicks the birthday button, notify the wait staff to check the id
	$(".birthday").click(function(event){
		event.preventDefault();
		$.ajax({type: "GET",
				url: "notifywaiter.php",
				data: {'type':4,'drink':"NoDrink"},
				success: function(data){
					if(data=="ok"){
						alert("The waiter has been called to check your id.");
						window.location.href = "Birthday.html";
					}
				}
		});
	});

	// When the customer clicks the birthday button, notify the wait staff to check the id
	$(".birthdaygame").click(function(event){
		event.preventDefault();
		$.ajax({type: "GET",
				url: "notifywaiter.php",
				data: {'type':4,'drink':"NoDrink"},
				success: function(data){
					if(data=="ok"){
						alert("The waiter has been called to check your id.");
						window.location.href = "../../Birthday.html";
					}
				}
		});
	});
}

$(document).ready(func);