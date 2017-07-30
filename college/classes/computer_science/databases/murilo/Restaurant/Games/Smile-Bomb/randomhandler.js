

	var weights = [0.2, 0.2, 0.2, 0.2, 0.2];
	var results = [1, 2, 3, 4, 5];
	
	function getRandom (){
	    var num = Math.random(),
	        s = 0,
	        lastIndex = weights.length - 1;
	
	    for (var i = 0; i < lastIndex; ++i) {
	        s += weights[i];
	        if (num < s) {
	            return results[i];
	        }
	    }
	
	    return results[lastIndex];
	};

	a = getRandom();
	console.log(a);


$(document).ready(rand);