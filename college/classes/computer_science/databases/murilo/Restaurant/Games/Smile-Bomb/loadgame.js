/* Function to load the initial configuration of the game. Clones the enemy character 14 times. */
var main = function(){

	var increment;
	/* This will clone the enemy characters and put 28 of them in the DOM */
	for(i=1;i<14;i++){
		var offset = i*70;
		increment = i+1;
		$('.enemy:last').clone().attr('id','e'+increment).css({'left':offset}).insertAfter('.enemy:last');
	}
	var offsettop = 70;
	/* If 14 have already been cloned, the next 14 will be placed right under the previously created enemies */
	for(i=0;i<14;i++){
		var offset = i*70;
		increment++;
		$('.enemy:last').clone().attr('id','e'+increment).css({'top':offsettop,'left':offset}).insertAfter('.enemy:last');
	}
};

$(document).ready(main);