var totalitem1 = 0;
var totalitem2 = 0;
var totalitem3 = 0;
var totalitem4 = 0;
var totalprices1 = 0;
var totalprices2 = 0;
var totalprices3 = 0;
var totalprices4 = 0;
var flag = 0;
var totalfinal1 = 0;
var totalfinal2 = 0;
var totalfinal3 = 0;
var totalfinal4 = 0;
var all_items = [];
var paid_items = [];

// Function to get all of the ordered items and put them in an array
var getItems = function(){
	$(".ordereditems .oneitem").each(function(index){
		all_items[index] = $(this).text();
	});
}

// Function to check if all of the items have been paid
var getPaidItems = function(idnum){
	// Put the paid items in an array
	$(".customers"+idnum+" .oneitem").each(function(index){
		paid_items[index] = $(this).text();
	});

	// Remove the paid items from the array containing all the items
	for (var i=paid_items.length;i>=0;i--){
		for (var j=all_items.length;j>=0;j--){
			if (paid_items[i]==all_items[j]){
				all_items.splice(j,1);
			}
		}
	}

	paid_items = [];

	console.log(all_items);

	// If all the items have been paid, finalize table
	if(all_items.length==0){
		$.ajax({url:"finishpayment.php",
				type:"POST",
				success: function(data){
					console.log(data);
				}
		});

		// Wait 10 seconds before deleting the information from the database because the wait staff needs to be notified.
		setTimeout(function(){
			$.ajax({url:"deletetable.php",
					type:"POST",
					success: function(data){
						console.log(data);
						window.location.href="index.php";
					}
			});
		},10000);

	// If there are items to be paid, ask the user to continue the payment
	}else{
		alert("Please, continue to pay for the items");
	}
}

/*var selecthandler = function(){
	$(".customer1_pay").click(function(){

		var item = $(this).prev();
		if(flag==0){
			item.insertAfter($("#customer1"));
			$("<button class='undoselection' id='undo1'>Undo</button>").insertAfter(item);
		}else{
			item.insertAfter($(".customers1 .oneitem"));
			$("<button class='undoselection' id='undo1'>Undo</button>").insertAfter(item);
		}	
 		
		
		var textdiv = item.text();
		var pricestart = textdiv.indexOf("$");
		var pricevalue = textdiv.substr(pricestart+1,textdiv.indexOf(' '));
		var quantitystart = textdiv.indexOf("Quantity: ");
		var quantitysplit = textdiv.split(":");
		var quantity = quantitysplit[quantitysplit.length-1].substr(1);
		totalitem1=parseFloat(pricevalue);		
		totalprices = totalprices+totalitem1;
 		var taxesindex = $(".taxes1").text().indexOf("$");
		var taxestext = $(".taxes1").text().substr(taxesindex+1);
		var taxes = Math.round((parseFloat(taxestext)+(0.0825*totalitem1))*100)/100;
		$(".taxes1").text("Taxes: $"+taxes);
		var tip = calculateTip(1);
		totalfinal = parseFloat(totalprices+taxes+tip).toFixed(2);
		$(".total1").text("Total: $"+totalfinal.toString());
	//	flag=1;  
		

		
		$(this).next().next().next().remove();
		$(this).next().next().remove();
		$(this).next().remove();
		$(this).remove();
		
	});
	
	
	$(".customer2_pay").click(function(){

		var item = $(this).prev().prev();
		if(flag==0){
			item.insertAfter($("#customer2"));
			$("<button class='undoselection' id='undo2'>Undo</button>").insertAfter(item);
		}else{
			item.insertAfter($(".customers2 .oneitem"));
			$("<button class='undoselection' id='undo2'>Undo</button>").insertAfter(item);
		}
		
 		var textdiv = item.text();
		var pricestart = textdiv.indexOf("$");
		var pricevalue = textdiv.substr(pricestart+1,textdiv.indexOf(' '));
		var quantitystart = textdiv.indexOf("Quantity: ");
		var quantitysplit = textdiv.split(":");
		var quantity = quantitysplit[quantitysplit.length-1].substr(1);
		totalitem2=parseFloat(pricevalue);
		totalprices2 = totalprices2+totalitem2;

		var taxesindex = $(".taxes2").text().indexOf("$");
		var taxestext = $(".taxes2").text().substr(taxesindex+1);
		var taxes = Math.round((parseFloat(taxestext)+(0.0825*totalitem2))*100)/100;
		$(".taxes2").text("Taxes: $"+taxes);
		var tip = calculateTip(2);
		totalfinal2 = parseFloat(totalprices2+taxes+tip).toFixed(2);
		$(".total2").text("Total: $"+totalfinal2.toString());
		//flag=1;  
		
		$(this).next().next().remove();
		$(this).next().remove();
		$(this).prev().remove();
		$(this).remove();
	});
	
	
		$(".customer3_pay").click(function(){
			$(this).next().hide();
			$(this).prev().prev().hide();
			$(this).prev().hide();
			var item3 = $(this).prev().prev().prev();
			if(flag==0){
				item3.insertAfter($("#customer3"));
				$("<button class='undoselection' id='undo3'>Undo</button>").insertAfter(item);
			}else{
				item3.insertAfter($(".customers3 .oneitem"));
				$("<button class='undoselection' id='undo3'>Undo</button>").insertAfter(item);
			}
			$(this).remove();
	
			var textdiv = item3.text();
			var pricestart = textdiv.indexOf("$");
			var pricevalue = textdiv.substr(pricestart+1,textdiv.indexOf(' '));
			var quantitystart = textdiv.indexOf("Quantity: ");
			var quantitysplit = textdiv.split(":");
			var quantity = quantitysplit[quantitysplit.length-1].substr(1);
	
			totalitem3=parseFloat(pricevalue);
			totalprices3 = totalprices3+totalitem3;
	
			var taxesindex = $(".taxes3").text().indexOf("$");
			var taxestext = $(".taxes3").text().substr(taxesindex+1);
			var taxes = Math.round((parseFloat(taxestext)+(0.0825*totalitem3))*100)/100;
			$(".taxes3").text("Taxes: $"+taxes);
			var tip = calculateTip(3);
			totalfinal3 = parseFloat(totalprices3+taxes+tip).toFixed(2);
			$(".total3").text("Total: $"+totalfinal3.toString());
			//	flag=1; 
		});

		$(".customer4_pay").click(function(){
			$(this).prev().hide();
			$(this).prev().prev().hide();
			$(this).prev().prev().prev().hide();
			var item4 = $(this).prev().prev().prev().prev();
			if(flag==0){
				item4.insertAfter($("#customer4"));
				$("<button class='undoselection' id='undo4'>Undo</button>").insertAfter(item);
			}else{
				item4.insertAfter($(".customers4 .oneitem"));
				$("<button class='undoselection' id='undo4'>Undo</button>").insertAfter(item);
			}
			$(this).remove();
 			var textdiv = item4.text();
			var pricestart = textdiv.indexOf("$");
			var pricevalue = textdiv.substr(pricestart+1,textdiv.indexOf(' '));
			var quantitystart = textdiv.indexOf("Quantity: ");
			var quantitysplit = textdiv.split(":");
			var quantity = quantitysplit[quantitysplit.length-1].substr(1);
	
			totalitem4=parseFloat(pricevalue);
			totalprices4 = totalprices4+totalitem4;
	
			var taxesindex = $(".taxes4").text().indexOf("$");
			var taxestext = $(".taxes4").text().substr(taxesindex+1);
			var taxes = Math.round((parseFloat(taxestext)+(0.0825*totalitem4))*100)/100;
			$(".taxes4").text("Taxes: $"+taxes);
			var tip = calculateTip(4);
			totalfinal4 = parseFloat(totalprices4+taxes+tip).toFixed(2);
			$(".total4").text("Total: $"+totalfinal4.toString());
			//flag=1; 
		});
}*/

/*var calculateTip = function(idnum){
	var array_items = [];
	var tipval = $("#tipinput"+idnum).val();
	if(tipval!=0){
		$(".customers .oneitem").each(function(index){
			array_items[index] = $(this).attr('id');
		});
		var totalprice=0;
		for(var i=0;i<array_items.length;i++){
			totalprice+=parseFloat(array_items[i]);
		}
		
		var finaltip = Math.round((tipval/100*totalprice)*100)/100;
		$("#tipinput"+idnum).text(finaltip);
		return (finaltip);
	}else{
		return 0;
	}
}*/

// Function to display the option for credit or cash
 var PayButton = function(){
	$(".pay_button").click(function(){
		$(this).last().hide();
		$(this).parent().find('.pickup_order').hide();
		//display cash or credit?
		$(this).hide();
		$(this).next().show();
		$(this).next().next().show();
		
	});
}

/*var enterButton= function(){
	$(".enter_button").click(function(){
		// Get the id of the button
		var identer = $(this).attr("id").slice(3);
		// Get the value of the input
		var tip = $(this).prev().val();
		if(identer=='1'){
			var totalval = totalprices1;
		}
		else if(identer=='2'){
			var totalval = totalprices2;
		}
		else if(identer=='3'){
			var totalval = totalprices3;
		}
		else if(identer=='4'){
			var totalval = totalprices4;
		}
		var totalfinal= Number(totalval)+Number(tip);
		$(".total"+identer+"_after_tip").text("Total after tip: $"+totalfinal.toFixed(2));
		$(this).parent().next().next().next().next().text("Total after tip: $"+totalfinal.toFixed(2));
	});

}*/

// Function to handle the tip input
var enterButton= function(){
	$(".enter_button").click(function(){
		var tip = $(this).prev().val();
		var totalval = $(this).parent().next().next().next().text().slice(8);
		var totalfinal= Number(totalval)+ Number(tip);
		$(this).parent().next().next().next().next().text("Total after tip: $"+totalfinal.toFixed(2));
	});
}

// Function to handle the cash payment. Notify the waiter about the cash payment
var cashButton= function(){
	$('.cash_button').click(function(){
		$(this).hide();
		$(this).next().hide();
		$(this).next().next().show();
		$(this).next().next().next().show();
		$.ajax({type: "GET",
				url: "notifywaiter.php",
				data: {'type':4,'drink':"NoDrink"},
				success: function(data){
					if(data=="ok"){
						alert("Waiter is coming to take your cash amount");
					}
				}	
		});
	});
}

// Function to display the credit option if the user chooses the order to go
var toGo = function(){
	$('.pickup_order').click(function(){
		$(this).parent().find('.pay_button').hide();
		$(this).hide();
		$(this).parent().find('.credit_button').show();
	});

}

// Function to handle payment using credit card
var creditButton= function(){
	$('.credit_button').click(function(){
		if($(this).prev().is(":visible")){
		alert("Your card payment is successful");
		$(this).hide();
		$(this).prev().hide();
		$(this).next().show();
		$(this).next().next().show();
		}
		// If the order is to go
		else{
			alert("Your card payment is successful");
			$(this).hide();
			$(this).prev().hide();
			$(this).next().show();
			$(this).next().next().show();
			$.ajax({type: "GET",
					url: "notifywaiter.php",
					data: {'type':5,'drink':"NoDrink"},
					success: function(data){
						if(data=="ok"){
							alert("Please wait, we have alerted the waiter about your to go order");
						}
					}	
			});

			// Display order id to customer so customer knows what is the number
			var elem = $(this).siblings(".order_number");
			// Get id from database
			$.ajax({url:"getidorder.php",
					type: "GET",
					success: function(data){
						console.log(data);
						elem.text("Your order number: "+data);
					}
			});
		}
	});
}

// Hide elements from the webpage when it's loaded
var cash_credit_hide = function(){
	$('.cash_button').hide();
	$('.credit_button').hide();
	$('.receipt_print').hide();
	$('.receipt_email').hide();
	$('.receipt_email_box').hide();
	$('.submit_email').hide();
	$(".customers1").hide();
	$(".customers2").hide();
	$(".customers3").hide();
	$(".customers4").hide();
}

// Function to handle the printing the receipt
var PrintReceipt = function(){
	$('.receipt_print').click(function(){
			$(this).hide();
			$(this).next().hide();
		alert("Receipt is being printed");
		getPaidItems($(this).parent().attr('class').slice(9));
		$(this).parent().remove();
	});
}

// Function to display a box asking the user for his email
var PrintEmail = function (){
	$('.receipt_email').click(function(){
			$(this).hide();
			$(this).prev().hide();
			$(this).next().show();
			$(this).next().next().show();
	});
}

// Fnction to send the email to the user
var SubmitEmail = function(){
	$('.submit_email').click(function(){
			alert("Your Receipt Email has been sent");
			$(this).hide();
			$(this).prev().hide();
			getPaidItems($(this).parent().attr('class').slice(9));
			$(this).parent().remove();

	});
}

// Function to handle payment for customer 1
$(document).on("click",".customer1_pay",function(){
	var item = $(this).prev();
	if($(".customers1").length!=0){
		$(".customers1").show();
			// Append items to customer div
			if(flag==0){
				item.insertAfter($("#customer1"));
				$("<button class='undoselection' id='undo1'>Undo</button>").insertAfter(item);
			}/*else{
				item.insertAfter($(".customers1 .oneitem"));
				$("<button class='undoselection' id='undo1'>Undo</button>").insertAfter(item);
			}	*/
 			
			// Get information about the item and calculate the total price and taxes
			var textdiv = item.text();
			var pricestart = textdiv.indexOf("$");
			var pricevalue = textdiv.substr(pricestart+1,textdiv.indexOf(' '));
			var quantitystart = textdiv.indexOf("Quantity: ");
			var quantitysplit = textdiv.split(":");
			var quantity = quantitysplit[quantitysplit.length-1].substr(1);
			totalitem1=parseFloat(pricevalue);		
			totalprices1 = totalprices1+totalitem1;
			
			// Calculate the taxes
 			var taxesindex = $(".taxes1").text().indexOf("$");
			var taxestext = $(".taxes1").text().substr(taxesindex+1);
			var taxes = Math.round((parseFloat(taxestext)+(0.0825*totalitem1))*100)/100;
			$(".taxes1").text("Taxes: $"+taxes);
		
			// Display tip information and calculate the total with the tip
			//var tip = calculateTip(1);
			$(".10_tip").text("10% Tip: $"+(totalprices1*10/100).toFixed(2));
			$(".15_tip").text("15% Tip: $"+(totalprices1*15/100).toFixed(2));
			$(".20_tip").text("20% Tip: $"+(totalprices1*20/100).toFixed(2));
			totalfinal = parseFloat(totalprices1+taxes).toFixed(2);
			$(".total1").text("Total: $"+totalfinal.toString());
			$("#tip1").click();
			//	flag=1;  
			$(this).next().next().next().remove();
			$(this).next().next().remove();
			$(this).next().remove();
			$(this).remove();
		}
		// If customer 1 has already paid, display this information for the customer in case customer 1 is selected again
		else{
			alert("Customer 1 has already paid");
		}
});

// Function to handle payment by customer 2
$(document).on("click",".customer2_pay",function(){
	var item = $(this).prev().prev();
	if($(".customers2").length!=0){
		$(".customers2").show();
			// Append item to customer 2 div
			if(flag==0){
				item.insertAfter($("#customer2"));
				$("<button class='undoselection' id='undo2'>Undo</button>").insertAfter(item);
			}/*else{
				item.insertAfter($(".customers2 .oneitem"));
				$("<button class='undoselection' id='undo2'>Undo</button>").insertAfter(item);
			}*/
			
			// Get information about the item
 			var textdiv = item.text();
			var pricestart = textdiv.indexOf("$");
			var pricevalue = textdiv.substr(pricestart+1,textdiv.indexOf(' '));
			var quantitystart = textdiv.indexOf("Quantity: ");
			var quantitysplit = textdiv.split(":");
			var quantity = quantitysplit[quantitysplit.length-1].substr(1);
			totalitem2=parseFloat(pricevalue);
			totalprices2 = totalprices2+totalitem2;
		
			// Calculate the taxes
			var taxesindex = $(".taxes2").text().indexOf("$");
			var taxestext = $(".taxes2").text().substr(taxesindex+1);
			var taxes = Math.round((parseFloat(taxestext)+(0.0825*totalitem2))*100)/100;
			$(".taxes2").text("Taxes: $"+taxes);
	
			// Calculate the tip
			//var tip = calculateTip(2);
			$(".10_tip2").text("10% Tip: $"+(totalprices2*10/100).toFixed(2));
			$(".15_tip2").text("15% Tip: $"+(totalprices2*15/100).toFixed(2));
			$(".20_tip2").text("20% Tip: $"+(totalprices2*20/100).toFixed(2));
			totalfinal2 = parseFloat(totalprices2+taxes).toFixed(2);
			$(".total2").text("Total: $"+totalfinal2.toString());
			//flag=1;  
			$("#tip2").click();
			$(this).next().next().remove();
			$(this).next().remove();
			$(this).prev().remove();
			$(this).remove();
	}
	// Function to alert the customer that the customer 2 has already paid in case he is selected again
	else{
		alert("Customer 2 has already paid");
	}
});

// Function to handle payment by customer 3
$(document).on("click",".customer3_pay",function(){

	/*$(this).next().hide();
	$(this).prev().prev().hide();
	$(this).prev().hide();*/
	if($(".customers3").length!=0){
		$(".customers3").show();
		// Insert item in customer 3 div
		var item = $(this).prev().prev().prev();
		if(flag==0){
			item.insertAfter($("#customer3"));
			$("<button class='undoselection' id='undo3'>Undo</button>").insertAfter(item);
		}else{
			item.insertAfter($(".customers3 .oneitem"));
			$("<button class='undoselection' id='undo3'>Undo</button>").insertAfter(item);
		}
		$(this).remove();
		
		// Get information about the item
		var textdiv = item.text();
		var pricestart = textdiv.indexOf("$");
		var pricevalue = textdiv.substr(pricestart+1,textdiv.indexOf(' '));
		var quantitystart = textdiv.indexOf("Quantity: ");
		var quantitysplit = textdiv.split(":");
		var quantity = quantitysplit[quantitysplit.length-1].substr(1);
		totalitem3=parseFloat(pricevalue);
		totalprices3 = totalprices3+totalitem3;
		
		// Calculate the taxes
		var taxesindex = $(".taxes3").text().indexOf("$");
		var taxestext = $(".taxes3").text().substr(taxesindex+1);
		var taxes = Math.round((parseFloat(taxestext)+(0.0825*totalitem3))*100)/100;
		$(".taxes3").text("Taxes: $"+taxes);
	
		// Calculate the tip
		$(".10_tip3").text("10% Tip: $"+(totalprices3*10/100).toFixed(2));
		$(".15_tip3").text("15% Tip: $"+(totalprices3*15/100).toFixed(2));
		$(".20_tip3").text("20% Tip: $"+(totalprices3*20/100).toFixed(2));
		//var tip = calculateTip(3);
		totalfinal3 = parseFloat(totalprices3+taxes).toFixed(2);
		$(".total3").text("Total: $"+totalfinal3.toString());
		$("#tip3").click();
		$(this).next().remove();
		$(this).prev().remove();
		$(this).prev().prev().remove();
		$(this).remove();
		//	flag=1; 
	}
	// Function to alert that the customer 3 has already paid, in case he is selected again
	else{
		alert("Customer 3 has already paid");
	}

});

// Function to handle payment by customer 4
$(document).on("click",".customer4_pay",function(){

	/*$(this).prev().hide();
	$(this).prev().prev().hide();
	$(this).prev().prev().prev().hide();*/
	if($(".customers4").length!=0){
		// Insert the item in the customer 4 div
		$(".customers4").show();
		var item = $(this).prev().prev().prev().prev();
		if(flag==0){
			item.insertAfter($("#customer4"));
			$("<button class='undoselection' id='undo4'>Undo</button>").insertAfter(item);
		}else{
			item.insertAfter($(".customers4 .oneitem"));
			$("<button class='undoselection' id='undo4'>Undo</button>").insertAfter(item);
		}
		// Get information about the item
		$(this).remove();
 		var textdiv = item.text();
		var pricestart = textdiv.indexOf("$");
		var pricevalue = textdiv.substr(pricestart+1,textdiv.indexOf(' '));
		var quantitystart = textdiv.indexOf("Quantity: ");
		var quantitysplit = textdiv.split(":");
		var quantity = quantitysplit[quantitysplit.length-1].substr(1);
		
		totalitem4=parseFloat(pricevalue);
		totalprices4 = totalprices4+totalitem4;
		
		// Calculate the taxes
		var taxesindex = $(".taxes4").text().indexOf("$");
		var taxestext = $(".taxes4").text().substr(taxesindex+1);
		var taxes = Math.round((parseFloat(taxestext)+(0.0825*totalitem4))*100)/100;
		$(".taxes4").text("Taxes: $"+taxes);
	
		// Calculate the tip
		$(".10_tip4").text("10% Tip: $"+(totalprices4*10/100).toFixed(2));
		$(".15_tip4").text("15% Tip: $"+(totalprices4*15/100).toFixed(2));
		$(".20_tip4").text("20% Tip: $"+(totalprices4*20/100).toFixed(2));
		//var tip = calculateTip(4);
		totalfinal4 = parseFloat(totalprices4+taxes).toFixed(2);
		$(".total4").text("Total: $"+totalfinal4.toString());
		$("#tip4").click();
		$(this).prev().remove();
		$(this).prev().prev().remove();
		$(this).prev().prev().prev().remove();
		$(this).remove();
		//flag=1; 
	}
	// Inform the customers that customer 4 has already paid, in case he is selected again
	else{
		alert("Customer 4 has already paid");
	}

});

// Function to handle the undo button
$(document).on("click",".undoselection",function(){

	// Get information about the item
	var idbutton = $(this).attr('id');
	var idnum = idbutton.slice(4);
	var item = $(this).prev();

	var textdiv = item.text();
	var pricestart = textdiv.indexOf("$");
	var pricevalue = textdiv.substr(pricestart+1,textdiv.indexOf(' '));

	var quantitystart = textdiv.indexOf("Quantity: ");
	var quantitysplit = textdiv.split(":");
	var quantity = quantitysplit[quantitysplit.length-1].substr(1);
	var totalitem=parseFloat(pricevalue);		
	
	// Subtract the item taxes from the total taxes
 	var taxesindex = $(".taxes"+idnum).text().indexOf("$");
	var taxestext = $(".taxes"+idnum).text().substr(taxesindex+1);
	var taxes = Math.round(parseFloat(taxestext)*100)/100;
	var taxesitem = Math.round((0.0825*totalitem)*100)/100;
	var newtaxes = taxes-taxesitem;
	$(".taxes"+idnum).text("Taxes: $"+newtaxes);

	// Calculate new total and new tip for the corresponding customer (1, 2, 3 or 4)
	var prevtotal = parseFloat($(".total"+idnum).text().slice(8));
	var newtotal = parseFloat(prevtotal-taxesitem-totalitem).toFixed(2);
	if(idnum=='1'){
		totalprices1 = totalprices1-totalitem;
		totalfinal1 = newtotal;
		$(".10_tip").text("10% Tip: $"+(totalprices1*10/100).toFixed(2));
		$(".15_tip").text("15% Tip: $"+(totalprices1*15/100).toFixed(2));
		$(".20_tip").text("20% Tip: $"+(totalprices1*20/100).toFixed(2));
	}
	else if(idnum=='2'){
		totalprices2 = totalprices2-totalitem;
		totalfinal2 = newtotal;
		$(".10_tip2"+idnum).text("10% Tip: $"+(totalprices2*10/100).toFixed(2));
		$(".15_tip2"+idnum).text("15% Tip: $"+(totalprices2*15/100).toFixed(2));
		$(".20_tip2"+idnum).text("20% Tip: $"+(totalprices2*20/100).toFixed(2));
	}
	else if(idnum=='3'){
		totalprices3 = totalprices3-totalitem;
		totalfinal3 = newtotal;
		$(".10_tip3"+idnum).text("10% Tip: $"+(totalprices3*10/100).toFixed(2));
		$(".15_tip3"+idnum).text("15% Tip: $"+(totalprices3*15/100).toFixed(2));
		$(".20_tip3"+idnum).text("20% Tip: $"+(totalprices3*20/100).toFixed(2));
	}
	else if(idnum=='4'){
		totalprices4 = totalprices4-totalitem;
		totalfinal4 = newtotal;
		$(".10_tip4"+idnum).text("10% Tip: $"+(totalprices4*10/100).toFixed(2));
		$(".15_tip4"+idnum).text("15% Tip: $"+(totalprices4*15/100).toFixed(2));
		$(".20_tip4"+idnum).text("20% Tip: $"+(totalprices4*20/100).toFixed(2));
	}

	if(newtotal!=0){
		$(".total"+idnum).text("Total: $"+newtotal.toString());
	}else{
		$(".total"+idnum).text("Total: $0");
	}

	// Put the item back in the ordered items div
	$("#tip"+idnum).click();
	var itemundo = item.appendTo($(".ordereditems"));
	var but1 = $("<button class='customer1_pay'>Cus 1</button>").insertAfter(itemundo);
	var but2 = $("<button class='customer2_pay'>Cus 2</button>").insertAfter(but1);
	var but3 = $("<button class='customer3_pay'>Cus 3</button>").insertAfter(but2);
	var but4 = $("<button class='customer4_pay'>Cus 4</button>").insertAfter(but3);
	$(this).remove();
});

$(document).ready(getItems);
$(document).ready(toGo);
$(document).ready(enterButton);
$(document).ready(SubmitEmail);
$(document).ready(PrintEmail);
$(document).ready(PrintReceipt);
$(document).ready(PayButton);
$(document).ready(cash_credit_hide);
$(document).ready(cashButton);
$(document).ready(creditButton);
//$(document).ready(selecthandler);
