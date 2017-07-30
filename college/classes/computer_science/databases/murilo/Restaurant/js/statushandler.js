/* Handler to monitor the status of an order */
var statushandler = setInterval(function(){
	var status = $("#table1").children(".statuses").text().slice(8);
	var orderid = $("")
	if(status!='Complete'){
		$.ajax({url: "statushandler.php", data:{idtable: '1'}, 
			type: "GET", 
			success: function(data){
				/* Convert returned strings to arrays */
				var statusarray = data[0].split(", ");
				var orderarray = data[1].split(", ");
				var ids = $('.statuses').map(function(){
    				return this.id;
				}).get();

				/* Modify the status of each element */
				for(var i=0;i<ids.length;i++){
					var idsliced = ids[i].slice(11);
					for(var j=0;j<orderarray.length;j++){
						var statustext;
						if(statusarray[j]=='1'){
							statustext = "Not Started";
						}else if(statusarray[j]=='2'){
							statustext = "In Progress";
						}else if(statusarray[j]=='3'){
							statustext = "Complete";
						}
						if(orderarray[j]==idsliced){
							$("#orderstatus"+orderarray[j]).text("Status: "+statustext);
						}
					}
				}
			},
		dataType: "json"});
	}

},1000);
	

$(document).ready(statushandler);