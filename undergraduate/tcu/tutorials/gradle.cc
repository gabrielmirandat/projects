Create a shortcut to that Gradle distribution:
	cd /usr/local
	sudo ln -s gradle-3.0 gradle

Create GRADLE_HOME Environment Variables
	sudo nano /etc/profile.d/gradle.sh
	export GRADLE_HOME=/usr/local/gradle
	export PATH=${GRADLE_HOME}/bin:${PATH}
	source /etc/profile

Creating New Gradle Builds
	mkdir basic-demo
	$ cd basic-demo
	$ touch build.gradle

	gradle tasks
	gradle help --task wrapper

	// generate wrapper and gradlew script
	// generate jar file and properties file
	gradle wrapper

	// show properties
	./gradlew properties

	mkdir src
	cd src/
	touch myfile.txt

Configure a Gradle core task	
	// create a task
	// in build.gradle
	task copy(type: Copy) {
    	from 'src'
    	into 'dest'
	}

	// to see the new task
	./gradlew tasks --all

	// execute the new copy task
	./gradlew copy

Configure a core task and use a plugin
	// gradle plugin portal
	https://plugins.gradle.org/

	// add base plugin
	// in build.gradle
	plugins {
    	id 'base'
	}

	// create task that
	// creates zip of src dir
	// in build.gradle
	task zip(type: Zip) {
    	from 'src'
	}

	./gradlew zip

	// remove the build dir
	./gradlew clean

Add a "Hello, World!" task


