https://www.digitalocean.com/community/tutorials/how-to-install-wordpress-on-ubuntu-14-04

Easily set up flexible blogs and websites on top of a MySQL backend with PHP processing. 
Youll need to have a LAMP (Linux, Apache, MySQL, and PHP) stack installed on your VPS instance.
    - group of open source software that is typically installed together 
      to enable a server to host dynamic websites and web apps.
    - Linux operating system, with the Apache web server. The site data is 
      stored in a MySQL database, and dynamic content is processed by PHP.

'Step One — Install Apache'
The Apache web server is currently the most popular web server in the world, which makes it a great default choice for hosting a website.
'How To Find your Servers Public IP Address'
$ ip addr show eth0 | grep inet | awk '{ print $2; }' | sed 's/\/.*$//'
$ curl http://icanhazip.com
186.222.173.198

'Step Two — Install MySQL'
MySQL is a database management system. 
Basically, it will organize and provide access to databases where our site can store information.

We need to tell MySQL to create its database directory structure where it will store its information. 
$ sudo mysql_install_db

'Step Three — Install PHP'
Will process code to display dynamic content.  It can run scripts, connect to our MySQL databases 
to get information, and hand the processed content over to our web server to display.

$ sudo nano /etc/apache2/mods-enabled/dir.conf

'nano' é um editor de texto para sistemas Unix-like ou ambientes usando command line interface (CLI). 
Ele emula o editor de texto Pico, parte do cliente de email Pine, e também provê funcionalidade adicional. 
Em contraste com Pico, nano é licenciado sob o GNU General Public License (GPL).

'restart Apache server'
$ sudo service apache2 restart

'Install PHP Modules'

'Step Four — Test PHP Processing on your Web Server'
We will call this script info.php. In order for Apache to find the file and serve it correctly, 
it must be saved to a very specific directory, which is called the "web root". Its in '/var/www/html/'

'Step One — Create a MySQL Database and User for WordPress'
WordPress uses a relational database to manage and store site and user information.
We need to make a database and a user for WordPress to work with.

First, we can create a separate database that WordPress can control.
Every MySQL statement must end in a semi-colon (;)

Next, we are going to create a separate MySQL user account that we will use 
exclusively to operate on our new database.

'Step Two — Download WordPress'
Next, we will download the actual WordPress files from the projects website.

'Step Three — Configure WordPress'
'Step Four — Copy Files to the Document Root'
One of the easiest and most reliable way of transferring files from directory to directory is 
with the rsync command. This preserves permissions and has good data integrity features.

The location of the document root in the Ubuntu 14.04 LAMP guide is '/var/www/html/'. 
We can transfer our WordPress files there by typing:
$ sudo rsync -avP ~/wordpress/ /var/www/html/