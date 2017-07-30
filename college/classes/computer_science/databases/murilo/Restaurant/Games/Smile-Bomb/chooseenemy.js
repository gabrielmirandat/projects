/* Variables to keep track of the score */
var score = 0;
var counter = 0;

/* Function that will be run once the document is ready */
function func(){
	/* Game won't start until user clicks start button */
	$('.startbutton').click(function(){
		/* Once the button is clicked, hide it */
		$(this).hide();
		var exists = []; // array is initialized as undefined
		var num;
		var execution = new Array();
		var max = 28;
		var interval = setInterval(choose,300);
		/* This function will be executed repeatedly at each 300 milliseconds */
		function choose(){
			/* If all enemies have "fallen", the game has reached its end */
			if(counter++>=max){
				/* Call function endGame after 1000 ms */
				clearInterval(interval);
				setTimeout(endGame,1000);
			}else{
				/* Generate random numbers from 1 to 14. Once the number is generated, it will never be used again. */
				/* Keep generating the number until it's a new number */
				/* Generate the number and check if the number was already generated. This is done by evaluating the number in its corresponding position in the exists array */
				/* When the number is first generated, the value true is assigned to its position in the exists array */
				do{
					num = Math.floor((Math.random()*28)+1);
				}while(exists[num-1]);
				/* Assign true to the position related to the generated number */
				exists[num-1] = true;
				/* Move the enemy related to the generated number */
				moveEnemy(num);
			}
		}
		
		function moveEnemy(n){
			var a = n;
			if(a===1){
				/* If it is the enemy 1, there is no number after its id */
				$('#e').animate({'top':'+=620px'},1000,"linear",collision).effect("explode",function(){$(this).hide();});
			}else if(a>14){
				/* If it is enemy+number, animate this enemy. If number is bigger than 14, the enemy is in the lower row, so it will fall less pixels than those in the upper row */
				$('#e'+a).animate({'top':'+=570px'},1000,"linear",collision).effect("explode",function(){$(this).hide();});
			}else{
				$('#e'+a).animate({'top':'+=620px'},1000,"linear",collision).effect("explode",function(){$(this).hide();});
			}
		}
	});
}

// The three next functions were adapted from a publicly available code in JSFiddle. Check Readme for details.
function getPositions(box){
	var $box = $(box);
	var pos = $box.position();
	var width = $box.width();
	var height = $box.height();
	return [[pos.left,pos.left+width],[pos.top,pos.top+height]];
}

// Function to compare two positions
function comparePositions(pos1,pos2){
	var x1 = pos1[0] < pos2[0] ? pos1:pos2; // x1 will get the smaller value
	var x2 = pos1[0] < pos2[0] ? pos2:pos1; // x2 will get the bigger value
	return x1[1] > x2[0] || x1[0] === x2[0] ? true:false;
}

/* Function to detect if 2 elements have collided */
function collision(){
	var box = $(".player")[0]; // get player
	var positionplayer = getPositions(box); // get player position and offset
	var positionenemy = getPositions(this); // get position of current enemy
	var horizontalMatch = comparePositions(positionplayer[0],positionenemy[0]); // compare positions horizontally
	var verticalMatch = comparePositions(positionplayer[1],positionenemy[1]); // compare positions vertically
	var match = horizontalMatch && verticalMatch; // check if position is the same. If it is, there's a collision.
	if(match){
		endGame();
	}

	// If positions don't match, this means that the div's haven't collided, so the score is incremented.
	if(!match){
		score+=1;
	}
}

function chanceWinning(){
	var weights = [0.2, 0.2, 0.2, 0.2, 0.2];
	var results = [1, 2, 3, 4, 5];
	var num = Math.random();
	var s = 0;
	var lastIndex = weights.length - 1;
	
	for (var i = 0; i < lastIndex;i++){
		s += weights[i];
	 	if (num < s) {
	    	return results[i];
	    }
	}
	
	return results[lastIndex];
}

/* Function that's called when the game ends */
function endGame(){
	// Display alert with score
	alert("Congratulations! Your score is "+score);
	// Stop all animations
	$(".round").remove();
	$("*").stop();
	// Fade in the button to restart the game
	$("#resetbutton").fadeIn(1000);
	won = chanceWinning();
	if(won==1){
		alert("Congratulations! You won a free dessert or appetizer!");
		window.open("../../dessertappetizer.php","_self");
	}
}

$(document).ready(func);