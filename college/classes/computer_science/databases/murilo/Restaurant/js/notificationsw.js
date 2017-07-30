/* This will keep checking for notifications once a second */
var notifications = setInterval(function(){
	$.ajax({url: "waiternotifications.php",
			type: "GET", 
			success: function(data){
				if(data!="Nothing"){
					console.log(data);
					// If there are notifications, append them to the notifications div
					if(data[0]=="1"){
						$(".notifications").append("<div class='notification'>"+data.slice(1)+"</div><button class='removenot'>Remove</button><br>");
					}
					else if(data[0]=="2"){
						$(".notifications").append("<div class='notification'>"+data.slice(1)+"</div><button class='removenot'>Remove</button><br>");
					}
					else if(data[0]=="3"){
						$(".notifications").append("<div class='notification'>"+data.slice(1)+"</div><button class='removenot'>Remove</button><br>")
					}
					else if(data[0]=="4"){
						$(".notifications").append("<div class='notification'>"+data.slice(1)+"</div><button class='removenot'>Remove</button><br>")
					}
					else if(data[0]=="5"){
						$(".notifications").append("<div class='notification'>"+data.slice(1)+"</div><button class='removenot'>Remove</button><br>")
					}
				}
			}
	});

},1000);

$(document).ready(notifications);