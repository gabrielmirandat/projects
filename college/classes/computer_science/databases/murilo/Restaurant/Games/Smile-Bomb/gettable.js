/* Function to get the high scores and put them in an unordered list in the DOM */

var get = function(){
	
	var tablescores = $.getJSON('getscores.php',function(data){
		$.each(data,function(key,val){
			$('ul').append("<li>"+val+"</li>");
		});
	});
}

$(document).ready(get);