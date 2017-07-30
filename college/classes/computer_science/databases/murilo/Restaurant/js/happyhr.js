
var checktime = setInterval(function()
{
	
	$.ajax
		({
			type:"GET",
			url:"js/HH.php",
			data:{'cdate':new Date().toString()}
		});
},5000);

$(document).ready(checktime);
