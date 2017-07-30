ultima modificação: 29/09
se não lido por uma semana, reler isso

ROS INDIGO (UBUNTU 14.04)
SIMULADOR GAZEBO
MEU ROS É CATKIN
'wiki.ros.org/catkin'
SOBRE LICENSAS OPEN-SOURCE
'https://opensource.org/licenses/alphabetical'

Getting Started: Introduction | Concepts | Higher-Level Concepts | Client Libraries | Technical Overview
	Learn about various concepts, client libraries, and technical overview of ROS. 

Introduction
	- hardware abstraction, 
	- low-level device control, 
	- implementation of commonly-used functionality, 
	- message-passing between processes, 
	- and package management.

Concepts
	3 níveis de conceitos: the Filesystem level, the Computation Graph level, and the Community level
		-> 'Filesystem': recursos encontrados no baixado do disco
			- 'Packages': processos (nodos), dependências, arquivos de config
			- 'Metapackages': pacotes especializados
			- 'Package Manifests': (package.xml): metadados do pacote 
			- 'Repositories': coleção de pacotes comuns
			- 'Message (msg) types': my_package/msg/MyMessageType.msg, definem estruturas para pacotes enviados no ros (MD5)
			- 'Service (srv) types':  my_package/srv/MyServiceType.srv, definem estruturas de pedidos e respostas
		
		-> 'Computation graph': rede P2P dos processos do ros que compartilham dados
							  são os nodes, Master, Parameter Server, messages, services, topics, e bags
							  implementados no repositório ros_comm
			- 'Nodes': são processos. Cada nó executa algo no robô, como controlar o motor da perna ou realizar planejamento de rota
			         é escrito com o uso de uma biblioteca cliente ROS, como roscpp ou rospy
			- 'Master': provê registro de nome e lookup pro resto do Computation Graph
					  permite que os nós encontrem uns aos outros, troquem mensagens e invoquem serviços
			- 'Parameter Server': permite armazenamento dos dados por chave. É parte do master
			- 'Messages': forma de comunicação dos nós. É uma estrutura de dados com tipos definidos.
			- 'Topics': Mensagens são roteadas via um sistema de transporte de publish (publicar) / subscribe (inscrever/aderir)
					  È onde nó publica pra enviar mensagem ou se inscreve pra receber a mensagem. 
					  Nome usado pra identificar conteúdo de uma mensagem. Como se fosse um bus, recebe publicações e inscrições de 
					  vários nós simultaneamente
			- 'Services': são os Request / reply requeridos pelo sistema distribuído. Par de estruturas (request, reply)
						nó oferece serviço, cliente usa serviço mandando um request e esperando por um reply
						oferecidas pelas bibliotecas como se fossem chamadas remotas a funções
			- 'Bags': formato para salvar e resgatar dados de mensagens ros. Para armazenar dados de sensores

			- 'Master' age como um servidor de Names do Computation graph
				- armazena info para regisro em Topics e Services para os Nodes
				- Nodes comunicam com Master pra pra reportar info de registro
				- fazendo esta comunicação, Nodes podem conhecer uns aos outros e fazer comunicação entre eles
				- Master faz callbacks aos Nodes quando as info de registros mudam
				- permite Nodes dinamicamente criarem conexão com novos nós
				- é como um DNS, Nodes se comunicam diretamente, Master só oferece info entre eles
				- Nodes que subscribe a um Topic pede conexão a Nodes que publicaram aquele Topic. Feito com TCP/IP (TCPROS)
				- sistema de Names (tipo namespaces), nodes, topics, services, e parameters tem Names 
				- toda bibliotecas cliente de ROS suporta remapear nomes pela linha de comando, significando que um pograma 
				  compilado pode reconfigurar em momento de execução para operar numa topologia Computation Graph diferente
				- Nodes são desacoplados, podendo serem iniciados, deletados e reiniciados em qualquer ordem sem erros
				- exemplo: controle do Hokuyo laser range-finder
					- começa driver hokuyo_node que fala com o laser
					- publica mensagens sensor_msgs/LaserScan no topic scan
					- cria node que usa laser_filters que se inscreve no topic scan
					- agora ele recebe mensagens diretamente do laser
				- para adicionar outro laser ao robô (reconfigurar sistema)
					- remapear Names usados
					- quando iniciar o hokuyo_node, remapear scan para base_scan
					- fazer o mesmo para o outro node
					- agora não usam o topic scan, e sim o base_scan


		-> 'Community level': recursos que permiter comunidades separadas trocar software e conhecimento, são Distributions, 
			Repositories, Wiki, FAQ e Blog.

		-> 'Names': podem ser Graph Resource Names ou Package Resource Names
			- 'Graph Resource Names': estrutura hierárquica de nomes usada por todos os recursos do Computation Graph, 
				Nodes, Parameters, Topics e Services.
					/ (the global namespace)
					/foo
					/stanford/robot/name
					/wg/node1
				- encapsulamento
				- cada recurso definido dentro de um namespace, que podem acessar recursos do próprio ou de outros namespaces
				- tools e parametros que precisam ser visíveis à todo o grafo podem ser criados como top-level Nodes.
				- tipos de nomes - base, relative, global, and private
					- 'base': base
					- 'relative': relative/name
					- 'global': /global/name
					- 'private': ~private/name	
				- Todo Name num Node Ros pode ser remapeado quando iniciado por linha de comando. 

		- 'Package Resource Names': com conceitos a nível de Filesystem
			- std_msgs/String refere-se ao tipo de mensagem String do pacote std_msgs. Refere-se também ao diretório 
			   'path/to/std_msgs/msg/String.msg'. 
			- São tipos Message(msg), tipos Service(srv) e tipos Node. 

Higher-Level Concepts
	São os 'common', 'common_msgs', and 'geometry'
		-> 'Transformações de Frames de coordenadas': O pacote tf provê métodos para coordenar múltiplas coordenadas pelo tempo
		-> 'Ações e tarefas': pacote actionlib define interface 'common' topic para tarefas de escalonamento do kernel no ROS 
		-> 'Ontologia de Mensagens': 'common_msgs', define várias classes de mensagens
			- 'actionlib_msgs': mensagem pra representar Actions
			- 'diagnostic_msgs': mensagem para mandar diagnóstico de dados
			- 'geometry_msgs': mensagens pra representar primitivas 'common geometric'
			- 'nav_msgs': mensagens para navegação
			- 'sensor_msgs': mensagens para representar dados de sensores
		-> 'Plugins': pacote pluginlib provê biblioteca para carregar libs C++ dinamicamente
		-> 'Filtros': pacote filters provê libs C++ para processar dados usando uma sequência de filtros
		-> 'Robot Model': pacote urdf define um xml pra representar um modelo de robô e parser C++
		-> 'Cheat Sheet': pdf falando tudo

Client Libraries
	Coleção de código pra facilitar programador ROS
	Permite escrever Nós, publicar e se inscrever em Tópicos, escrever e chamar Serviços e usar o servidor de Parâmetros.
	-> 'Principais bibliotecas'
		- 'roscpp': mais usada no ros, alta performance
		- 'rospy': como roscpp, em python
		- 'roslisp': em lisp
	-> 'Experimentais'
		- roscs, roseus, rosgo, roshark, rosjava, rosnodejs, roslua, rosR, rosruby

Tutorials

1. Core ROS Tutorials
1.1 Beginner Level
	1. Installing and Configuring Your ROS Environment
		1. Install ROS
		2. Managing Your Environment
			 'Note: Throughout the tutorials you will see references to "rosbuild" and "catkin". These 
			 are the two available methods for organizing and building your ROS code. Generally, 
			 rosbuild is easy to use and simple, where as catkin uses more standard CMake conventions, 
			 so it is more sophisticated, but provides more flexibility especially for people wanting 
			 to integrate external code bases or who want to release their software. For a full break 
			 down visit catkin or rosbuild. '
			 -> ao abrir um terminal: $ source /opt/ros/indigo/setup.bash
		3. Create a ROS Workspace
			- create a catkin workspace
				$ mkdir -p ~/catkin_ws/src
				$ cd ~/catkin_ws/src
				$ catkin_init_workspace
					~ Creating symlink "/home/gabriel/catkin_ws/src/CMakeLists.txt" 
					  pointing to "/opt/ros/indigo/share/catkin/cmake/toplevel.cmake"
			- build the workspace
				$ cd ~/catkin_ws/
				$ catkin_make
			- source te setup.sh
				$ source devel/setup.bash
			- make sure ROS_PACKAGE_PATH environment variable includes the directory youre in. 
				$ echo $ROS_PACKAGE_PATH

	2. Navigating the ROS Filesystem
		- inspect a package in ros-tutorials
			$ sudo apt-get install ros-indigo-ros-tutorials
		- 'Packages': Packages are the software organization unit of ROS code. 
		  			  Each package can contain 'libraries', 'executables', 'scripts', or 'other artifacts'.
		- 'Manifests (package.xml)': A manifest is a description of a package. It serves to define dependencies 
									 between packages and to capture meta information about the package 
									 like 'version', 'maintainer', 'license', etc... 
		- 'rospack': allows you to get information about packages
			- $ rospack find [package_name]
			- $ rospack find roscpp
		- 'roscd': is part of the rosbash suite. It allows you to change directory (cd) directly to a package or a stack. 
			- $ roscd [locationname[/subdir]]
			- $ roscd roscpp
			- $ pwd
			- $ roscd roscpp/cmake
			- $ pwd
		-  roscd, like other ROS tools, will only find ROS packages that are within the directories listed in your ROS_PACKAGE_PATH
			- $ echo $ROS_PACKAGE_PATH
		- 'roscd log': go to ros programs log folder
		- 'rosls': is part of the rosbash suite. It allows you to ls directly in a package by name rather than by absolute path. 
			- $ rosls [locationname[/subdir]]
			- $ rosls roscpp_tutorials
	
	3. Creating a ROS Package
		- 'roscreate-pkg' or 'catkin' - to create a new package
		- 'rospack' - to list package dependencies
		1. What makes up a catkin Package?
			- must contain a  'catkin compliant package.xml' - metainfo about the package
			- must contain a 'CMakeLists.txt which uses catkin'
			- one package for directory
			- packagge structure
				my_package/
	  				CMakeLists.txt
	  				package.xml
	  	2. Packages in a catkin Workspace
	  		- 'catkin workspace': to work with workspaces
	  			- structure of workspace
	  				workspace_folder/        -- WORKSPACE
					  src/                   -- SOURCE SPACE
					    CMakeLists.txt       -- 'Toplevel' CMake file, provided by catkin
					    package_1/
					      CMakeLists.txt     -- CMakeLists.txt file for package_1
					      package.xml        -- Package manifest for package_1
					    ...
					    package_n/
					      CMakeLists.txt     -- CMakeLists.txt file for package_n
					      package.xml        -- Package manifest for package_n
		3. Creating a catkin Package
			- 'catkin_create_pkg' - create a new catkin package
			- $ cd ~/catkin_ws/src 										    // change to the source space directory of the catkin workspace you created
			- $ catkin_create_pkg beginner_tutorials std_msgs rospy roscpp  // create a new package called 'beginner_tutorials' which depends on std_msgs, roscpp, and rospy 
		   // # catkin_create_pkg <package_name> [depend1] [depend2] [depend3]
		4. Building a catkin workspace and sourcing the setup file
			- $ cd ~/catkin_ws
			- $ 'catkin_make' 											    // to build the packages in the catkin workspace
			// After the workspace has been built it has created a similar structure in the devel subfolder
			- $ . ~/catkin_ws/devel/setup.bash							    // source the generated setup file to add the builden workspace in the ROS environment
		5. package dependencies
			- $ rospack depends1 beginner_tutorials						    // to list the first-order dependencies of beginner_tutorials package
			// These dependencies for a package are stored in the package.xml file
			- $ roscd beginner_tutorials
			- $ cat package.xml
			- $ rospack depends1 rospy									    // to list the dependencies of the dependency
			- $ rospack depends beginner_tutorials							// shows all dependencies, even the indirects
		6. Customizing Your Package
			- 'package.xml'
				- <descrition> - short description of package
				- <maintainer> - describe developer in this tag
				- <license> - definir uma licença olhando a lista de licensas na url do topo da página
				- <dependencies> - describe the dependencies of your package.  Split into 'build_depend', 'buildtool_depend', 'run_depend', 'test_depend'.

	4. Building a ROS Package
		- $ source /opt/ros/indigo/setup.bash								// remember to source your environment setup file if you have not already
		- $ cd ~/catkin_ws
		- $ catkin_make [make_targets] [-DCMAKE_VARIABLES=...] 				// catkin_make combines the calls to cmake and make in the standard CMake workflow
		- $ catkin_make install  # (optionally)
		// Building zero to many catkin packages in a workspace follows this work flow
		// The above commands will build any catkin projects found in the src folder
	5. Understanding ROS Nodes
		-  introduces ROS graph concepts
		- use of  'roscore', 'rosnode', and 'rosrun' 
		- $ sudo apt-get install ros-indigo-ros-tutorials 				// download lightweight simulator
		- Graph contents
			'Nodes': A node is an executable that uses ROS to communicate with other nodes.
			'Messages': ROS data type used when subscribing or publishing to a topic.
			'Topics': Nodes can publish messages to a topic as well as subscribe to a topic to receive messages.
			'Master': Name service for ROS (i.e. helps nodes find each other)
			'rosout': ROS equivalent of stdout/stderr
			'roscore': Master + rosout + parameter server (parameter server will be introduced later) 
		- Node: executable file within a ROS package
		- Client Libraries: allow nodes written in different programming languages to communicate (rospy and roscpp)
		- $ roscore														// first thing you should run when using ROS
		- $ rosnode list 												// displays information about the ROS nodes that are currently running
		- $ rosnode info /rosout 										// returns information about a specific node
		- $ rosrun turtlesim turtlesim_node 							// allows you to use the package name to directly run a node within a package
	   // $ rosrun [package_name] [node_name]
		- $ rosrun turtlesim turtlesim_node __name:=my_turtle 			// changes the node name
		- $ rosnode ping my_turtle 										// ping to the node to see if it is connected

	6. Understanding ROS topics
		- introduces ROS topics as well as using the 'rostopic' and 'rqt_plot' commandline tools.
		- (1) $ roscore 								// Let's start by making sure that we have roscore running
		- (2) $ rosrun turtlesim turtlesim_node 		// we will also use turtlesim
		- (3) $ rosrun turtlesim turtle_teleop_key 	    // to drive the turtle around with - turtle keyboard teleoperation

		2. ROS Topics
			- The turtlesim_node and the turtle_teleop_key node are communicating with each other over a ROS Topic. 
			- turtle_teleop_key is publishing the key strokes on a topic, while turtlesim subscribes to the same topic to receive the key strokes.
			- Lets use 'rqt_graph' which shows the nodes and topics currently running. 
			- 'rqt_graph' creates a dynamic graph of whats going on in the system. 
			- 'rqt_graph' is part of the rqt package. 
			- $ sudo apt-get install ros-<distro>-rqt
			- $ sudo apt-get install ros-<distro>-rqt-common-plugins
			- $ rosrun rqt_graph rqt_graph 					// to see what is going on with the nodes
				- Nodes: /teleop_turtle e \turtlesim
				- Topics: /turtle1/cmd_vel

			- $ rostopic -h 								// The rostopic tool allows you to get information about ROS topics.
			// rostopic echo [topic] 						// shows the data published on a topic.
			- $ rostopic echo /turtle1/cmd_vel 				// move the turtle to see the data

			- refreshing rqt_graph, you can see that rostopic echo node is subscribed to /turtle1/cmd_vel topic.

			// $ rostopic list -h 							// returns a list of all topics currently subscribed to and published.  
			$ rostopic list -v 								// uses the verbose option

		3. ROS Messages			
			- Communication on topics happens by sending ROS 'messages' between nodes. 
			- For the publisher (turtle_teleop_key) and subscriber (turtlesim_node) to communicate, the publisher and subscriber 
			  must send and receive the same type of message. 
			- This means that a 'topic type' is defined by the 'message type' published on it.
			- The 'type of the message' sent on a topic can be determined using 'rostopic type'. 
			// rostopic type [topic] 						// returns the message type of any topic being published. 
			- $ rostopic type /turtle1/cmd_vel 				// geometry_msgs/Twist
			- $ rosmsg show geometry_msgs/Twist 			// to see details of the message
					// geometry_msgs/Vector3 linear
					//   float64 x
					//   float64 y
					//   float64 z
					// geometry_msgs/Vector3 angular
					//   float64 x
					//   float64 y
					//   float64 z
			// rostopic pub [topic] [msg_type] [args] 		 // publishes data on to a topic currently advertised.
			- $ rostopic pub -1 /turtle1/cmd_vel geometry_msgs/Twist  
			  -- '[2.0, 0.0, 0.0]' '[0.0, 0.0, 1.8]' 		 // send a single message to turtlesim telling it to move with an linear velocity 
			  												 // of 2.0, and an angular velocity of 1.8 . 
				- rostopic pub 			// publish messages to a given topic
				- -1 					// causes rostopic to only publish one message then exit
				- /turtle1/cmd_vel 		// the name of the topic to publish to
				- geometry_msgs/Twist 	// message type to use when publishing to the topic
				- -- 					// required in cases where your arguments have a leading dash -, like negative numbers
				- '[2.0, 0.0, 0.0]' 
				  '[0.0, 0.0, 1.8]' 	// arguments are actually in YAML syntax

			// You may have noticed that the turtle has stopped moving; 
		    // this is because the turtle requires a steady stream of commands at 1 Hz to keep moving. 
			// We can publish a steady stream of commands using rostopic pub -r command
			- $ rostopic pub /turtle1/cmd_vel geometry_msgs/Twist -r 1 
			  -- '[2.0, 0.0, 0.0]' '[0.0, 0.0, -1.8]'

			// rostopic pub node (here in red) is communicating with the rostopic echo node
			// rostopic hz [topic] 							// reports the rate at which data is published.
			- $ rostopic hz /turtle1/pose   				// how fast the turtlesim_node is publishing /turtle1/pose
			- $ rostopic type /turtle1/cmd_vel | rosmsg show// to get in depth information about a topic

			// to plot the data being published on the /turtle1/pose topic.
			- $ rosrun rqt_plot rqt_plot 					// First, start rqt_plot by typing 
				// to see turtle moving graphics
				- /turtle1/pose/x
				- /turtle1/pose/y