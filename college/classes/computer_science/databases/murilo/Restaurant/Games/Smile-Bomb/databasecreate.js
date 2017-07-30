function create(){
	$.ajax({
		url: 'createdb.php',
		sucess: function(){
			console.log("Database created successfully!");
		}
	});
}

$(document).ready(create);