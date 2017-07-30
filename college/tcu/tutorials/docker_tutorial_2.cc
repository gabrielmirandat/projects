image     - pacote executável com tudo para rodar um software
container - processo da imagem (instância na memória)

Stack
Services
Container (you are here)


// ----------------------------------------------------------------------------
docker build -t friendlyname .  			# Create image using this directorys Dockerfile
docker run -p 4000:80 friendlyname  		# Run "friendlyname" mapping port 4000 to 80
docker run -d -p 4000:80 friendlyname       # Same thing, but in detached mode
docker ps                                 	# See a list of all running containers
docker stop <hash>                     		# Gracefully stop the specified container
docker ps -a           						# See a list of all containers, even the ones not running
docker kill <hash>                   		# Force shutdown of the specified container
docker rm <hash>              				# Remove the specified container from this machine
docker rm $(docker ps -a -q)           		# Remove all containers from this machine
docker images -a                            # Show all images on this machine
docker rmi <imagename>            			# Remove the specified image from this machine
docker rmi $(docker images -q)             	# Remove all images from this machine
docker login             					# Log in this CLI session using your Docker credentials
docker tag <image> username/repository:tag  # Tag <image> for upload to registry
docker push username/repository:tag         # Upload tagged image to registry
docker run username/repository:tag          # Run image from a registry
// ----------------------------------------------------------------------------
docker stack ls              					# List all running applications on this Docker host
docker stack deploy -c <composefile> <appname>  # Run the specified Compose file
docker stack services <appname>       			# List the services associated with an app
docker stack ps <appname>   					# List the running containers associated with an app
docker stack rm <appname>                       # Tear down an application
// ----------------------------------------------------------------------------
docker-machine create --driver virtualbox myvm1 								# Create a VM (Mac, Win7, Linux)
docker-machine create -d hyperv --hyperv-virtual-switch "myswitch" myvm1 		# Win10
docker-machine env myvm1                										# View basic information about your node
docker-machine ssh myvm1 "docker node ls"         								# List the nodes in your swarm
docker-machine ssh myvm1 "docker node inspect <node ID>"        				# Inspect a node
docker-machine ssh myvm1 "docker swarm join-token -q worker"   					# View join token
docker-machine ssh myvm1   														# Open an SSH session with the VM; type "exit" to end
docker-machine ssh myvm2 "docker swarm leave"  									# Make the worker leave the swarm
docker-machine ssh myvm1 "docker swarm leave -f" 								# Make master leave, kill swarm
docker-machine start myvm1            											# Start a VM that is currently not running
docker-machine stop $(docker-machine ls -q)               						# Stop all running VMs
docker-machine rm $(docker-machine ls -q) 										# Delete all VMs and their disk images
docker-machine scp docker-compose.yml myvm1:~     								# Copy file to nodes home dir
docker-machine ssh myvm1 "docker stack deploy -c <file> <app>"   				# Deploy an app



// create docker image
$ sudo docker build --network=host -t friendlyhello .

// list local images
$ docker images

// run the app, mapping your machine’s port 4000 to the container’s EXPOSEd port 80 using -p
$ docker run -p 4000:80 friendlyhello

// run in background and show complete container ID
$ docker run -d -p 4000:80 friendlyhello

// list containers and ids
$ docker ps

// end the container process
$ docker stop 1fa4ab2cf395

// log in docker cloud on machine
$ docker login

// existing image will upload to your desired destination
$ docker tag friendlyhello username/repository:tag
$ docker tag friendlyhello gabrielmirandat/friendlyhello:fh1

// upload your tagged image
$ docker push username/repository:tag
$ docker push gabrielmirandat/friendlyhello:fh1

// run app in any machine
$ docker run -p 4000:80 username/repository:tag
$ docker run -p 4000:80 gabrielmirandat/friendlyhello:fh1

// a docker-compose.yml file is a YAML file that defines how Docker containers should behave in production
docker-compose.yml

// nop
$ docker swarm init

// run application
$ docker stack deploy -c docker-compose.yml getstartedlab

// see list of containers launched by docker-compose.yml
$ docker stack ps getstartedlab

// scale the app by changing the replicas value in docker-compose.yml
$ docker stack deploy -c docker-compose.yml getstartedlab

// put app down
$ docker stack rm getstartedlab

// enable swarm mode making host swarm manager
$ docker swarm init

// add workers to the swarm
$ docker swarm join

// create a couple of VMs 
$ docker-machine create --driver virtualbox myvm1
$ docker-machine create --driver virtualbox myvm2

// make virtual machine swarm manager
$ sudo docker-machine ssh myvm1 "docker swarm init --advertise-addr 192.168.99.100:2376"

// join virtual machine as worker
$ sudo docker-machine ssh myvm2 "docker swarm join \
>     --token SWMTKN-1-3zycqzp31a16jsqr81t1pnr72ew16yinmeocwk2pmv77sp9wn4-d36on4fxz438y8xbky54akwfp \
>     192.168.99.100:2377"

// copy file to virtual machine
$ docker-machine scp docker-compose.yml myvm1:~

// deploy in virtual machine
$ docker-machine ssh myvm1 "docker stack deploy -c docker-compose.yml getstartedlab"

// start vm
$ sudo docker-machine start myvm1