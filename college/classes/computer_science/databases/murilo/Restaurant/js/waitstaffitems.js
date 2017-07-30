var waitstaff = setInterval(function(){
	/* Get the ordered items at an interval of 10 seconds */
	$.ajax({url: "waitstaffitems.php", type: "GET", success: function(data){
			var elementtable = $("#table1");
			console.log(elementtable);
			var ids = $('.statuses').map(function(){
    			return this.id;
			}).get();
			console.log(ids);
			/*var elementchildattr = $(".statuses").attr('id');
			console.log(elementchildattr);*/
			var flag = 0;
			if(elementtable.length!=0){
				/*$('.statuses').each(function(i, obj) {
					console.log(obj.attr('id'));
    				elementchild.push(obj);
				});*/
				// console.log(elementchild);
				//console.log(elementchild[0].attr('id'));
				//console.log(elementchild[1]);
				// console.log(elementchild.length);
				var idsliced;
				for (var i=0;i<ids.length && flag==0;i++){
					idsliced = ids[i].slice(11);
					console.log(idsliced);
					if(data[data.length-1]==parseInt(idsliced)){
						flag=1;
					}
				}
			} 
			if(flag==0 && elementtable.length==0){
				/* Append the order to the page */
				$(".orders").append("<div id='table"+data[0]+"'>Table "+data[0]+"<br></div><br>");
				$("#table"+data[0]).append("<div class='tablestatus'>Table Status: Not Paid</div><br>");
				$("#table"+data[0]).append("<div class='ordernumber'>Order ID: "+data[data.length-1]+"</div>");
				for(var i=1;i<data.length-2;i+=3){
					if(data[i]!=undefined){
						$("#table"+data[0]).append(data[i]['Name']+" Quantity: "+data[i+1]+" Sides: "+data[i+2]);
						$("#table"+data[0]).append("<br>");
					}
				}
				/* Append the status to the page */
				$("#table"+data[0]).append("<div class='statuses' id='orderstatus"+data[data.length-1]+"'>Status: "+data[data.length-2]+"</div><br>");
				$("#table"+data[0]).append("<button class='removebutton' id='t"+data[0]+"'>Remove</button><br>");
			}
			else if(flag==0 && elementtable.length!=0){
				for(var i=1;i<data.length-2;i+=3){
					if(data[i]!=undefined){
						$("#table"+data[0]).append(data[i]['Name']+" Quantity: "+data[i+1]+" Sides: "+data[i+2]);
						$("#table"+data[0]).append("<br>");
					}
				}
				/* Append the status to the page */
				$("#table"+data[0]).append("<div class='statuses' id='orderstatus"+data[data.length-1]+"'>Status: "+data[data.length-2]+"</div><br>");
				$("#table"+data[0]).append("<button class='removebutton' id='t"+data[0]+"'>Remove</button><br>");
			}

	},dataType: "json"})}, 15000);

$(document).ready(waitstaff);