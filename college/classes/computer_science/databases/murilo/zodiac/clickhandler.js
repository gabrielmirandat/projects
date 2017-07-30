var cells = [];
var flag = 0;

var redo = [];
var sequence = [];

// This class stores a path selected by the user (Obs.: A path can be just one cell. In other words, it can be just a single click)
function Path(){
    this.cells = [];
}

// This variable stores all the paths done by the user
var hist = [];

/*

 Check which class is active, highlight the next one and remove the current one.
 Then, increment the counter of how many times the cell has been clicked,
 then update the css parameters related to the text.

 */

var highlight = function(cell) {

    if (cell.hasClass("active1")) {
        cell.addClass("active2");
        cell.removeClass("active1");
        var text = cell.text();
        var c = parseInt(text);
        c += 1;
        cell.find("span").text(c);
        cell.find("span").attr('style', 'color:black', 'position: absolute', 'bottom: 0', 'right: 0');

    } else if (cell.hasClass("active2")) {
        cell.addClass("active3");
        cell.removeClass("active2");
        var text = cell.text();
        var c = parseInt(text);
        c += 1;
        cell.find("span").text(c);
        cell.find("span").attr('style', 'color:black', 'position: absolute', 'bottom: 0', 'right: 0');

    } else if (cell.hasClass("active3")) {
        cell.addClass("active4");
        cell.removeClass("active3");
        var text = cell.text();
        var c = parseInt(text);
        c += 1;
        cell.find("span").text(c);
        cell.find("span").attr('style', 'color:black', 'position: absolute', 'bottom: 0', 'right: 0');

    } else if (cell.hasClass("active4")) {
        cell.addClass("active5");
        cell.removeClass("active4");
        var text = cell.text();
        var c = parseInt(text);
        c += 1;
        cell.find("span").text(c);
        cell.find("span").attr('style', 'color:black', 'position: absolute', 'bottom: 0', 'right: 0');

    } else if (cell.hasClass("active5")) {
        var text = cell.text();
        var c = parseInt(text);
        c += 1;
        cell.find("span").text(c);
        cell.find("span").attr('style', 'color:black', 'position: absolute', 'bottom: 0', 'right: 0');
    }

    else {
        cell.addClass("active1");
        var text = cell.text();
        var c = parseInt(text);
        c += 1;
        cell.find("span").text(c);
        cell.find("span").attr('style', 'color:black', 'position: absolute', 'bottom: 0', 'right: 0');
    }
}

var unhighlight = function(cell) {

    if (cell != undefined) {

        if (cell.hasClass("active1")) {
            cell.removeClass("active1");
            var text = cell.text();
            var c = parseInt(text);
            c -= 1;
            cell.find("span").text(c);
            cell.find("span").attr('style', 'color:white', 'position: absolute', 'bottom: 0', 'right: 0');

        } else if (cell.hasClass("active2")) {
            cell.addClass("active1");
            cell.removeClass("active2");
            var text = cell.text();
            var c = parseInt(text);
            c -= 1;
            cell.find("span").text(c);
            cell.find("span").attr('style', 'color:black', 'position: absolute', 'bottom: 0', 'right: 0');

        } else if (cell.hasClass("active3")) {
            cell.addClass("active2");
            cell.removeClass("active3");
            var text = cell.text();
            var c = parseInt(text);
            c -= 1;
            cell.find("span").text(c);
            cell.find("span").attr('style', 'color:black', 'position: absolute', 'bottom: 0', 'right: 0');

        } else if (cell.hasClass("active4")) {
            cell.addClass("active3");
            cell.removeClass("active4");
            var text = cell.text();
            var c = parseInt(text);
            c -= 1;
            cell.find("span").text(c);
            cell.find("span").attr('style', 'color:black', 'position: absolute', 'bottom: 0', 'right: 0');

        } else if (cell.hasClass("active5")){

            var text = cell.text();
            var c = parseInt(text);
            c -= 1;

            if(c<5){
                cell.addClass("active4");
                cell.removeClass("active5");
                cell.find("span").text(c);
                cell.find("span").attr('style', 'color:black', 'position: absolute', 'bottom: 0', 'right: 0');
            }else{
                cell.find("span").text(c);
                cell.find("span").attr('style', 'color:black', 'position: absolute', 'bottom: 0', 'right: 0');
            }
        }

        else {
            var text = cell.text();
            var c = parseInt(text);
            c -= 1;
            cell.find("span").text(c);
            cell.find("span").attr('style', 'color:white', 'position: absolute', 'bottom: 0', 'right: 0');
        }
    }
}

/* Function to evaluate if two cells are diagonally one from another */
var isDiagonal = function(v, line1, line2, column1, column2) {
    /* Subtract the number and get their absolute values */
    num1 = line1 - line2;
    num2 = column1 - column2;
    a1 = Math.abs(num1);
    a2 = Math.abs(num2);
    /*	Get the sign of the column subtraction.
     If column 1 is greater than column 2, the signal is positive.
     If column 1 is less than column 2, the signal is negative.
     */
    if (num2 > 0) {
        sign = 1;
    } else {
        sign = -1;
    }

    /* If the absolute values are the same, the cells are diagonal from one another */
    if (a1 == a2) {
        var v = [true, sign];
        return v;
        /* If the absolute values are not the same, the cells are not diagonal from one another */
    } else {
        var v = [false, sign];
        return v;
    }
}

/* Main function to listen to all the buttons and keys */
var main = function() {

    $('#undo-btn').click(function()
    {
        if(hist.length > 0) // If there is some element in hist
        {
            var path = hist.pop();
            redo.push(path);
            //console.log(redo);
            for (i = 0; i < path.cells.length; i++) {
                unhighlight(path.cells[i]);
            }
        }

    });

    $('#redo-btn').click(function() {

        if(redo.length > 0) // If there is element in redo
        {
            var path = redo.pop();
            hist.push(path);
            //console.log(path);
            for (i = 0; i < path.cells.length; i++) {
                highlight(path.cells[i]);
            }
        }
    });

    $('#save-btn').click(function(){

        var history = convertHistory(hist);
        var getfile = $.ajax({
            url: "createfile.php",
            type: "POST",
            dataType: "json",
            data: {userpath:JSON.stringify(history)},
            success: function(data){
                console.log("Success!");
            }
        });
        window.setTimeout(function(){
            location.href = "savefile.php";
            var deleteTimeout = setTimeout(function(){
                var deletefile = $.ajax({
                    url: "deletefile.php",
                    type: "POST",
                    dataType: "json",
                    success: function(data){
                        console.log("File deleted in the server!");
                    }
                });
            },10000);
        },1000);
    });

    var elem = $("<dfdjsklfajdsajklfjlkfdjflkdsafkldjkl>")
    elem.css('')
    append(elem);

    /* Handle click of any button for the preset */
    $(".presets").click(function(){
        var filename = $(this).text()+".txt";
        $.ajax({url: "readfile.php",
                type: "GET",
                data: {name:filename},
                success: function(data){
                    var numarray = data.split(", ");
                    highlightPattern(0,numarray);   
                }
        });
    });

    /* If a cell is clicked, highlight it and put it in the array */
    $(".cell").click(function(event) {

        //Clear redo
        redo = [];

        clicked = $(this);
        highlight(clicked);
        cells[cells.length] = clicked;
        var path = new Path();

        //Push the first cell clicked
        path.cells.push(clicked);   //Add the cell to the path
        var temp_cell = new Path();
        temp_cell.cells.push(clicked);
        hist.push(temp_cell);       //Add the path to the history

        // If the key to make a path is pressed
        if(flag == 1)
        {
            // If two cells were clicked to make a path
            if(cells.length == 2) // If the user has already clicked in two cells, so make the path between these cells if exist a path
            {

                var c1 = cells[0].attr('id');
                var c2 = cells[1].attr('id');
                var s1 = [];
                var s2 = [];
                /* Get the number that comes after the "cipher" word in the id attribute */
                s1 = c1.substring(6, c1.length);
                s2 = c2.substring(6, c2.length);
                /* Convert these numbers to integers */
                var n1 = parseInt(s1);
                var n2 = parseInt(s2);
                v = [n1, n2];
                /* Sort the array in the ascending order */
                v.sort(function(a, b) {
                    return a - b
                });

                path.cells = [];  // Clean the path variable
                // Add the first cell of the path
                path.cells.push($(document.getElementById("cipher" + v[0].toString())));

                /* Get the lines of the clicked cells */
                line1 = Math.floor(v[0] / 17);
                line2 = Math.floor(v[1] / 17);
                /* Get the columns of the clicked cells */
                column1 = v[0] % 17;
                column2 = v[1] % 17;

                /* If the path is vertical */
                if (line1 != line2 && column1 == column2) {
                    for (i = line1 + 1; i < line2; i++) {
                        var mark = i * 17 + column1;
                        highlight($(document.getElementById("cipher" + mark.toString())));
                        path.cells.push($(document.getElementById("cipher" + mark.toString())));
                    }
                }

                /* If the path is horizontal */
                else if (line1 == line2 && column1 != column2) {
                    for (i = column1 + 1; i < column2; i++) {
                        var mark = line1 * 17 + i;
                        highlight($(document.getElementById("cipher" + mark.toString())));
                        path.cells.push($(document.getElementById("cipher" + mark.toString())));
                    }
                }

                /* If the path is diagonal */
                else if (line1 != line2 && column1 != column2) {
                    var ans = isDiagonal(v, line1, line2, column1, column2);
                    /* If the cells are diagonal from one another and the signal is negative, column 1 is less than column 2. This means to "go right" */
                    var aux = v[0];
                    if (ans[0] == true && ans[1] == -1) {
                        /* 	If "going right", this means that the column will be incremented.
                         If aux is the second cell clicked, which has been highlighted already,
                         the last element that has been highlighted is this cell minus 18.
                         If aux equals this last element, the while stops.
                         The path will have been highlighted.
                         */
                        while (aux != (v[1] - 18)) {
                            aux = aux + 18;
                            highlight($(document.getElementById("cipher" + aux.toString())));
                            path.cells.push($(document.getElementById("cipher" + aux.toString())));
                        }
                        /* If the cells are diagonal from one another and the signal is positive, column 1 is greater than column 2. This means to "go left" */
                    } else if (ans[0] == true && ans[1] == 1) {
                        /* 	If "going left", this means that the column will be decremented.
                         If aux is the second cell clicked, which has been highlighted already,
                         the last element that has been highlighted is this cell minus 16.
                         If aux equals this last element, the while stops.
                         The path will have been highlighted.
                         */
                        while (aux != (v[1] - 16)) {
                            aux = aux + 16;
                            highlight($(document.getElementById("cipher" + aux.toString())));
                            path.cells.push($(document.getElementById("cipher" + aux.toString())));
                        }
                    } else if (ans[0] == false) {
                        alert("This path is not valid.");
                        path.cells.push($(document.getElementById("cipher" + v[1].toString())));
                        /*console.log(path);
                        console.log(hist);*/
                        cells = [];
                        flag = 0;
                        return;
                    }
                }

                //Pop the last two elements from the History because instead of saving 2 cells, we are going to save just the path formed by these cells
                hist.pop();
                hist.pop();

                // Add the last cell of the path
                path.cells.push($(document.getElementById("cipher" + v[1].toString())));

                // If the number of the last clicked cell is less the first clicked cell, it's necessary to sort the array in a descending order
                if(n2 < n1)
                {

                    path.cells.sort(function(a,b){

                        /* Encapsulate in function */
                        var c1 = a.attr('id');
                        var c2 = b.attr('id');
                        var s1 = [];
                        var s2 = [];
                        /* Get the number that comes after the "cipher" word in the id attribute */
                        s1 = c1.substring(6, c1.length);
                        s2 = c2.substring(6, c2.length);
                        /* Convert these numbers to integers */
                        var n1 = parseInt(s1);
                        var n2 = parseInt(s2);
                        return n2-n1
                    });
                    //console.log(path.cells);
                }

                // Then add the path to the history
                hist.push(path);

                cells = []; // Clean cells

            }
        }else{ // If the key was not pressed, it's not necessary to save the last click, so clean cells
            cells = [];
        }

    });

    /*
    This function hadles the event when a keydown event happens
    */
    function KeyPress(e)
    {
        // Undo Shortcut Key  Ctrl + Z
        if ((e.which == 90 || e.keyCode == 90) && e.ctrlKey)
        {
            if(hist.length > 0) // If there is some element in hist
            {
                var path = hist.pop();
                redo.push(path);
                //console.log(path.cells.length);
                for (i = 0; i < path.cells.length; i++) {
                    unhighlight(path.cells[i]);
                }
            }
        }

        // Redo Shortcut Key  Ctrl + Y
        if ((e.which == 89 || e.keyCode == 89) && e.ctrlKey)
        {
            if(redo.length > 0) // If there is element in redo
            {
                var path = redo.pop();
                hist.push(path);
                for (i = 0; i < path.cells.length; i++) {
                    highlight(path.cells[i]);
                }
            }
        }

        // Key for making paths
        if(event.which == 75){
            if (flag == 0) {
                flag = 1;
            }
        }
    }


    $(this).keydown(function(event) {
        KeyPress(event);
    });

    /*
     When the key is released (in this case it's the key k),
     calculate the path between the 2 cells and highlight all the cells in the path.
     */

    $(this).keyup(function(event){
        if(event.which==75){
            cells = [];
            flag = 0;
        }
    });

}


/*
    Gets all the cells in the history
*/
var convertHistory = function(pattern){

    var path=[];
    var finalpath = [];

    for(i=0;i<pattern.length;i++){
        for(j=0;j<pattern[i].cells.length;j++){
            var c = pattern[i].cells[j].attr('id');
            var s = [];
            /* Get the number that comes after the "cipher" word in the id attribute */
            s = c.substring(6, c.length);
            path[j] = parseInt(s);
        }

        finalpath[i] = path;
        path = [];
    }

    // console.log(finalpath);
    return finalpath;
}

/* Function to highlight the elements in a pattern with an interval of 1 millisecond */
var highlightPattern = function(i,nums){
    setTimeout(function(){ 
        if (i<nums.length){
            nums[i] = parseInt(nums[i]);
            $("#cipher"+nums[i]).click();
            i++;
            highlightPattern(i,nums); 
        }    
    },0.5)
}        

$(document).ready(main);