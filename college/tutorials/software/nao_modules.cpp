- qibuild
control+h - mostrar arquivos ocultos

#pra usar naoqi, precisa de um proxy, que estão na biblioteca ALCommon. 
#broker é o auxiliador que fica ouvindo a porta de rede o tempo todo.


##################################################################################################################
http://doc.aldebaran.com/2-1/qibuild/beginner/getting_started.html
Getting Started
	qiBuild - aplicativos de comando escritos em python

	- Install Qibuild:
		> sudo pip install qibuild --user  
			(qibuild in /usr/local/lib/python2.7/dist-packages)
			(qibuild --version)

http://doc.aldebaran.com/2-1/qibuild/beginner/qibuild/tutorial.html
Building C++ projects with qibuild
	> create some projects
    > get a toolchain with some precompiled dependencies
    > configure and build the projects
    > deploy them to your robot

    http://doc.aldebaran.com/2-1/qibuild/beginner/qibuild/getting_started/linux.html
    Getting started with qibuild on Linux
    	> sudo apt-get install cmake build-essential
    	> qibuild config --wizard (for first run)
    		(A file will be generated in ~/.config/qi/qibuild.xml. It is shared by all the worktrees you will create.)

    	http://doc.aldebaran.com/2-1/qibuild/beginner/qibuild/ide/qtcreator.html#qibuild-qtcreator
    	Building with qibuild and QtCreator
    		(not let QtCreator call CMake by itself the first time.)
    		> qibuild configure
    		> qibuild make 
    				(open the root CMakeLists.txt in QtCreator.)
    				(choose path that was created by qiBuild)

    > sudo apt-get install python

    Creating a worktree
    	(You need to chose a qibuild “worktree”.)
    	(This path will be the root from where qiBuild searches to find the sources of your projects.)
    	(we will use the notation QI_WORK_TREE to refer to this path.)
    	> qibuild init - in the worktree path
    		(This will create a new qiBuild configuration file in your working directory, in QI_WORK_TREE/.qi/qibuild.xml.)
    		(re-run qibuild config --wizard form a directory inside your worktree, the wizard will ask you if you want to configure settings for this worktree.)

   	Starting a new project from scratch
   		(A worktree is simply a directory tree containing a .qi folder as its root.)
   		> cd /path/to/worktree
   		> qibuild init					- create a worktree
   		> qisrc create foo				- create a new project
   		> qibuild configure foo			- configure the project
   		> qibuild make foo				- build the project
   		> qibuild open 					- launch with IDE

   	Using Aldebaran packages

   		http://doc.aldebaran.com/2-1/qibuild/beginner/qibuild/aldebaran.html
   		Using qibuild with Aldebaran C++ SDKs

   			For the Desktop
   				(get the C++ SDK and extract it, say in /path/to/cpp/sdk)
   				(Create a worktree inside the C++ SDK examples folder)
   					> cd /path/to/cpp/sdk/examples
   					> qibuild init												  - create a worktree 
   					> qitoolchain create naoqi-sdk /path/to/cpp/sdk/toolchain.xml - create a toolchain feed to the C++ SDK
   					> qibuild add-config naoqi-sdk --toolchain naoqi-sdk		  - create a build configuration associated with the toolchain
   					> qibuild configure -c naoqi-sdk helloworld				   	  - configure helloworld project
   					> qibuild make -c naoqi-sdk helloworld						  - build helloworld project

   			For the robot
   				(This if often refer to as cross-compilation)
   				(get the cross-toolchain that matches your robot version (atom for V4 and later, geode for previous version)
   				(extract it, say in /path/to/atom/ctc)
   				> qitoolchain create cross-atom /path/to/ctc/toolchain.xml		   - create a toolchain using the feed from the cross-toolchain
   				> qibuild add-config cross-atom --toolchain cross-atom			   - create a build configuration associated with the cross-toolchain
   				> qibuild configure -c cross-atom								   - configure
				> qibuild make -c cross-atom									   - build

	http://doc.aldebaran.com/2-1/qibuild/advanced/guide/index.html#qibuild-guide

##################################################################################################################

http://doc.aldebaran.com/2-1/dev/cpp/tutos/create_module.html?highlight=extending#declare-dependency-in-cmakelists-txt
Extending NAO API - Creating a new module

1. Create the skeleton using qibuild create
	
	> qisrc create mymodule - cria pasta de trabalho - sem C++ SDK - não é qitoolchain
	myproject
	|__ CMakeLists.txt
	|__ main.cpp		      - just a standard “Hello World”.
	|__ qibuild.cmake     - MUST be included by the CMakeLists.txt to find the qiBuild CMake framework.
	|__ qibuild.manifest  - MUST be present for qiBuild to know how to build the foo project.

2. Declare dependency in CMakeLists.txt

/*	cmake_minimum_required(VERSION 2.8)

	# Give a name to the project.
	project(mymodule)

	# You need this to find the qiBuild CMake framework
	include("qibuild.cmake")

	# Create a executable named mymodule
	# with the source file: main.cpp
	qi_create_bin(mymodule "main.cpp")
*/

	> To communicate with naoqi you need to use a proxy inside your code
	> Proxies are inside "ALCommon library"
	> You need to "import ALCommon inside your CMakeLists".
	> add: qi_use_lib(<your_project_name> <library_you_want_use_1> <library_you_want_use_2>)


#main.cpp
We now extend a little this file to communicate with NAOqi and call bind function from NAOqi’s module.
You need to do a command line option parser with at least --pip (para IP)
                                             and --pport (para PORTA) option.
You need create a proxy to the module you want use. 
To do that you must include <alcommon/alproxy.h>, 
then create a proxy to the module 
and finally you can call a method from this module.
Now you know how to communicate with NAOqi and a method from a module

> The broker is the client used to call a method from a module strange module. 

3. How to create a remote module

A remote module is a program which will connect to NAOqi over the network. It will allow you 
to extend/add basic NAOqi bind functions.  

Create a new class derived from ALModule
You need to create your own inherited class form ALModule. You’ll need ALModule and ALBroker.

Now you already create your inherited class, you can update your main.cpp to create broker 
and to allow every module to communicate with your bind methods.


//SOAP (Simple Object Access Protocol)
//SOAP (Simple Object Access Protocol) is a messaging protocol that allows programs 
//that run on disparate operating systems (such as Windows and Linux) to communicate 
//using Hypertext Transfer Protocol (HTTP) and its Extensible Markup Language (XML).
//Serialization= The basic mechanisms are to flatten object(s) into a one-dimensional 
//stream of bits, and to turn that stream of bits back into the original object(s).

4. How to start remote module

##Using binary program
  ./mymodule --pip <robot_ip> --pport <robot_port>
  ./mymodule --pip 192.168.0.12 --pport 9559

##Using autoload.ini
  First of all you need to send your program on your robot (using scp or rsync)
  and then add the path to your program into /home/nao/naoqi/preferences/autoload.ini under [program] tag.

  Example of autoload.ini:
  [program]
  /home/nao/mymodule
  # or
  /home/nao/myfolder/whatever/mymodule

5. How to create a local module

There is a second way to create a module.
This one is launched in NAOqi’s process.
The fastest one.

This type of module is not a program (binary) anymore. You will create a library.
You need change CMakeLists and main.cpp to do that.

Once you have update the CMakeLists the only thing you need to do is change the main.cpp

#main.cpp
You’ve just created your first local module for NAOqi.
You can find it in a folder named 
build-<name>/sdk/lib/naoqi where name if the name of the toolchain you have created containing the NAOqi C++ SDK.

6. How to start a local module

##Using autoload.ini
  Add the path to your library into the [user] tag in autoload.ini file is the first way to
  start your module. This file is located into /home/nao/naoqi/preferences/autoload.ini on your robot.    

  [user]
  /path/to/libmymodule.so

When you add the path to you library, at NAOqi startup your module will be automatically loaded 
in NAOqi process. After that you can use your module as classic ones.

Note: for this to work on your robot, you must cross-compile your module.

##Using dynamic linking loader
  If you want to use your module in another one, the good way to do that is to use programming 
  interface to dynamic linking loader (dlclose, dlerror, dlopen, dlsym).
  The first thing is to find the library on your robot. If you use the standard SDK layout described 
  here (FIXME), you can use qi::path::findLib to obtain the path to your library. Otherwise, you need 
  to hard code the path to it.

7. Switching from local to remote using a CMake option

#CMake
For every example, you can choose whether you want a local or a remote module by setting a CMake option 
looking like MYMODULE_IS_REMOTE.

#main.cpp







