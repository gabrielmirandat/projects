// Check if the user has already ordered something, so he would be eligible to pay
var payhandler = function(){

	$(".payorder").click(function(){

		$.ajax({url:"js/payeligible.php",
				type: "GET",
				success: function(data){
					if(data=="eligible"){
						window.location.href = "pay.php";
					}else{
						alert("Please order before paying.");
					}
				}
		});

	});
}

$(document).ready(payhandler);