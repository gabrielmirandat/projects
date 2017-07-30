var all_order = [];

// Function to show the nutritional info
var showinfo = function(){
	
	$('.infobutton').click(function(){

		/* If calories are currently being displayed, when the user clicks the button again, hide them. */
		if($(this).next().children("span").hasClass("calories-active")){
			$(this).next().children("span").removeClass("calories-active").addClass("calories-inactive");
		}else{
			$(this).next().children("span").removeClass("calories-inactive").addClass("calories-active");
		}
		/*}else{
			 Send AJAX request to server. Request will be handled in the nutritionalinfo.php file. The name, and the HTML ID of the menu item will be sent to the request 
			$.get("js/nutritionalinfo.php",{
				name:$(this).prev().prev().children("a").text(),
				id:$(this).next().children("span").attr("id")
				}
				,
				function(data){
				 Add the calories text to the span element 
				$("#"+data["Id"]).text("Calories: "+data["Cal"]);
				 Remove the inactive class and display the element
				$("#"+data["Id"]).removeClass("calories-inactive").addClass("calories-active");
			},"json");
		}*/
	});
}

// Function to show the sides and the quantity
var show = function (){
	$('.show_button').click(function(){
		$(this).next().toggle();
	});
}

var add = function(){
	
	$('.add_button').click(function(){
		// Get information related to the item
		var item_name = $(this).parent().parent().prev().prev().children('span').attr('name');
		var item_id = $(this).parent().parent().prev().prev().children('span').attr('id');
		var item_price = $(this).parent().parent().prev().prev().children('span').attr('value');
		var side_dish=[];

		// Get the sides
 		if($(this).prev().prev().prop('checked')){
			 var test = $(this).prev().prev().attr('value');
			side_dish.push (test);
		}			
			
		if($(this).prev().prev().prev().prev().prop('checked')){
			 var test = $(this).prev().prev().prev().prev().attr('value');
			side_dish.push (test);
		}
			
		if($(this).prev().prev().prev().prev().prev().prop('checked')){
			 var test =$(this).prev().prev().prev().prev().prev().attr('value');
			side_dish.push (test);
		}
		
		// Get the quantity
		var quantity_input;
		var quantityelement = $(this).prev().prev().prev().prev().prev().prev().children();
		quantity_input = $(this).prev().prev().prev().prev().prev().prev().children().val();
			
		// Handle the quantity and put the order in an array
		if (isNaN(quantity_input)==true){
			alert('Your quantity input is not a number.');
		}
		else{
			if(quantity_input < 0){
				alert('Your quantity input needs to be more than 0.');
			}
			else if (quantity_input > 0 && quantity_input < 10){
				if(quantityelement.hasClass('free') && quantity_input>1){
					alert("You are only eligible for 1 appetizer or dessert");
				}else{
					var one_order=[item_id,item_price,quantity_input,side_dish];
					all_order.push(one_order);
					$("#display_order").append("<li class='itemslist' id='item"+item_id+"'>Item: "+item_name + "---Quantity: " + quantity_input + "---Sides: " + side_dish + "</li> <button id='remove"+item_id+"' class='removebutton'>Remove</button><br><br>");
				}
			}
			else if (quantity_input >= 10 ){
				alert('Your quantity input is too big. Order less than 10 of the same item please.');
			}
			else{
				alert('You have to specify the quantity.');
			}
		}
	});
}

var addD = function(){

	$('.button_d').click(function(){
		
		// Get item information
		var item_id = $(this).parent().prev().prev().children('span').attr('id');
		var item_price = $(this).parent().prev().prev().children('span').attr('value');
		var item_name = $(this).parent().prev().prev().children('span').attr('name');
		var side_dish=[]
		var quantityelement = $(this).prev().children();
		var quantity_input;
		quantity_input = $(this).prev().children().val();
		
		// Handle the quantity input and put the ordered item in an array
		if (isNaN(quantity_input)==true){
			alert('Your quantity input is not a number.');
		}
		else{
			if(quantity_input < 0){
				alert('Your quantity input needs to be more than 0.');
			}
			else if (quantity_input > 0 && quantity_input < 10){
				if(quantityelement.hasClass('free') && quantity_input>1){
					alert("You are only eligible for 1 appetizer or dessert");
				}else{
					var one_order=[item_id,item_price,quantity_input,side_dish];
					all_order.push(one_order);
					$("#display_order").append("<li class='itemslist' id='item"+item_id+"'>Item: "+item_name + "---Quantity: " + quantity_input +"</li> <button id='remove"+item_id+"' class='removebutton'>Remove</button><br><br>");
				}
			}
			else if (quantity_input >= 10 ){
				alert('Your quantity input is too big. Order less than 10 of the same item please.');
			}
			else{
				alert('You have to specify the quantity.');
			}
		}
	}); 	

}

var submit_button_handler = function(){

	// Function to submit the order
	$(".submit_button").click(function(){
		var itemidarray = [];
		var pricearray = [];
		var quantityarray = [];
		var sidearray = [];
		var k;
		// Check if the order is a free appetizer or dessert
		var quantity = $(".free");
		console.log(all_order);
		if(quantity.length!=0 && all_order.length>1){
			alert("You are only eligible for 1 appetizer or dessert!");
		}else{

			for (var j=0,k=0;j<all_order.length;j++){
				itemidarray[j] = all_order[j][0];
				pricearray[j] = all_order[j][1];
				quantityarray[j] = all_order[j][2];
				if(all_order[j][3].length>0){
					sidearray.push(all_order[j][3]);
				}else{
					sidearray.push(0);
				}
			}
			
			/*console.log(itemidarray);*/
			/*console.log(pricearray);*/
			/*console.log(quantityarray);*/
			/*console.log(sidearray);*/
	
			/* Make AJAX request to submit order to database */
			$.ajax({
				type: "POST",
				url: "js/submitorder.php",
				data: {'itemid':itemidarray,'price':pricearray,'quantity':quantityarray,'side':sidearray}
			});
		
			// Empty the order array and clear the page
			all_order = [];
			$(".sides").prop("checked",false);
			var orderremove = document.getElementById("#display_order");
			$("#display_order").empty();
			$(".quantity_input").val("");
			$(".show_button").next().hide();
		}
	});
}
	

/*var payhandler = function(){
	$('.pay_button').click(function(){
		window.location.href = "pay.php";
	});
}*/

// Function to hide the elements in the beginning
var hide = function(){
	$('.side_order').hide();
	$(".pay_button").hide();
}

// Function to stop the quantity input to respond to an enter press
var enterhandler = function(){
	$('.noEnter').keypress(function(event){
		if(event.which == 13){
			return false;
		}

	});
}

// Function to update the menu items
var updateMI = function()
{
	$('.updateitem').click(function()
	{
		var m_id = $(this).attr('id');
		var decide = $(this).attr('value');	
		$.ajax
		({
			type:"POST",
			url:"js/update.php",
			data:{'menuid':m_id,'option':decide},
			success: function()
			{
				window.location.reload(true);//reload everything
				//window.location.reload(oldtab);
			}
		});
	});	
}

$(document).ready(hide);
$(document).ready(show);
$(document).ready(add);
$(document).ready(addD);
$(document).ready(enterhandler);
$(document).ready(showinfo);
$(document).ready(submit_button_handler);
//$(document).ready(payhandler);
$(document).ready(updateMI);
// Function to handle the customer removing an item from the order
$(document).on("click",".removebutton",function(){
	var lielement = $(this).prev();
	var idelement = lielement.attr('id').substr(4);
	lielement.remove();
	for (var i=0; i<all_order.length;i++){
		if(all_order[i][0]==idelement){
			all_order.splice(i,1);
		}
	}
	$(this).remove();
});