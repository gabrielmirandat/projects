var func = function(){
	/* Function to handle the player */
	$(document).keydown(function(event){
		/* If the key pressed is the right arrow, the player will move 50 pixels to the right */
		if(event.which == 39){
			$('.player').animate({left:"+=50px"},100,"linear");
			if(860<=$('.player').offset()['left']){
				$('.player').animate({left:"-=50px"},100,"linear");
			}
		}
		/* If the key pressed is the left arrow, the player will move 50 pixels to the left */
		if(event.which == 37){
			$('.player').animate({left:"-=50px"},100,"linear");
			if(70>=$('.player').offset()['left']){
				$('.player').animate({left:"+=50px"},100,"linear");
			}
		}
	});	
};

$(document).ready(func);