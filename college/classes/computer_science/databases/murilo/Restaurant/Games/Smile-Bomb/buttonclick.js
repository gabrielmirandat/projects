/* Function to handle clicks in the buttons */
function handleclicks(){
	
	$('#buttontweet').click(function(){
		window.location = $(this).location.href;
	});

	$('#buttonend').click(function(){
		window.location = $(this).location.href;
	});

	$('#resetbutton').click(function(){
		window.location.replace('index.html');
	});
}

$(document).ready(handleclicks);