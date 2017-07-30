// Make AJAX request to display ads in page
var ads = function(){
	$.ajax({type:"GET",
			url:"getads.php",
			success: function(data){
				var ad = data.split("|");
				for(var i=0;i<ad.length-1;i++){
					$(".advertisements").append("<div id='ad"+i+"'>"+ad[i]+"</div>");
				}
				$(".advertisements").slick({
					slidesToShow: 1,
					slidesToScroll: 1,
					autoplay: true,
					autoplaySpeed: 3000,
				});
			}
	});
}

$(document).ready(ads);