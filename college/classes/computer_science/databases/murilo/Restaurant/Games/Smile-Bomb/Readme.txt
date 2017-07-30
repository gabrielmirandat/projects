Readme

Murilo Cerqueira Medeiros
Student ID: 11033234

CSCE 3420 - Internet Programming - Final Project
Professor: Dr. Ryan Garlick
TA: Kusumanjali Koneru

About the website:

The website is a game. The objective of the game is to successfully dodge all the falling "smiles". The player is also a "smile". For every falling smile that successfully explodes, the player gets 1 point. The user is able to tweet the achieved score and the user can also check a table containing the 10 highest scores achieved in the game.

Implementation:

The game was implemented using HTML, CSS, Javascript, jQuery, jQuery UI and PHP.

HTML and CSS are used to form the basic design of the game. Javascript and jQuery and jQuery UI are used to load the initial state of the game and to animate the game. PHP is used to handle the insertion of the user's score in a database and it's also used to get the 10 highest scores from the database.

In order to properly run the website, the user must have Xampp installed and he must put the website in the htdocs folder or the user must have a fully functioning web server.

Also, I have tried to implement a PHP code to create a database named "Scores", containing a table named "High Scores", containing a column named "Score", but this code didn't do what was expected. This attempt is named "createdb.php" and this code would be loaded using "databasecreate.js".

I have created this database with these parameters using the phpmyadmin graphical interface. Because of that, if the user wants to enter the high scores link, it must have this database properly configured in phpmyadmin with the previously specified parameters.

There is also a bug related to the alert dialog showing the score. For some unknown reason, this alert dialog may appear twice after the game ends.

Other than that, the code is working as expected.

The code that detect if two divs collide is based on the code publicly available here: http://jsfiddle.net/TG2M7/13/
This code was developed by user Ryan Connolly. Other publicly available codes may be found here: http://jsfiddle.net/user/ryanoc/fiddles/2/

Other websites used as references:
http://api.jquery.com
http://stackoverflow.com
https://forum.jquery.com
http://www.w3schools.com/
http://jqueryui.com/

If the website is running on "localhost", the user should simply type localhost and the website will load. When the user finishes the game, there is a restart button to go back and restart the game.

Things that should be improved:
The program should be able to successfully create the database if it does not exist.
The design of some elements such as some buttons should be drastically improved.