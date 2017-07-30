// If the kitchen staff chooses to go to the menu to edit or if he wants to go back to the orders page, display the requested page
var goToMenu = function(){
	$("a").click(function(){
		var h = $(this).text();
		console.log(h);
		if(h=="Menu"){
			window.location.href = "kitchenmenu.php";
		}
		else if(h=="Orders"){
			window.location.href = "kitchenview.php";
		}
	});
}

$(document).ready(goToMenu);