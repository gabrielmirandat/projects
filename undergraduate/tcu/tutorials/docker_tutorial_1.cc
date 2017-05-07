https://www.digitalocean.com/community/tutorials/how-to-install-and-use-docker-on-ubuntu-16-04


// list all subcommands
$ docker

// view specific command
$ docker docker-subcommand --help

// view system-wide info
$ docker info

// search for ubuntu image in Docker hub
$ docker search ubuntu

// download image to computer
$ docker pull ubuntu

// run container of downloaded image
$ docker run hello-world

// see all images downloaded in computer
$ docker images

// run with interactive shell and local
$ docker run -it --net=host ubuntu
	$ apt-get update
	$ apt-get install -y nodejs

// destroy a container
$ docker rm

// save the state of a container as a new image
$ exit     											// exit container
$ docker commit -m "What did you do to the image"   // commit changes to new image
 -a "Author Name" container-id 
 repository/new_image_name          
