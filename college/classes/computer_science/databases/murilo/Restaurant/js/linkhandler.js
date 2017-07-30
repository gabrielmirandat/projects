var func = function(){
	$('.block1').click(function(){
		var link = $(this).attr("href");
		var section = link.slice(11,17);
		document.location.href = "index-2.php";
		$('.selected').toggleClass('selected');
		var newlink = $('a').each(function(section){
			var newref = $(this).attr('href');
			if (section==newref){
				$(this).toggleClass("selected");
			}
		});
	});
}

$(document).ready(func);