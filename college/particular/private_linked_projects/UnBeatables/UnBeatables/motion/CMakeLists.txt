cmake_minimum_required(VERSION 2.8)
project(motion)

#########################################################
# FINDING QIBUILD
#########################################################
find_package(qibuild)

#########################################################
# INCLUDE DIRECTORIES
#########################################################
get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} PATH)
include_directories(
${CMAKE_CURRENT_SOURCE_DIR}/include
${PARENT_DIR}/common
)

#########################################################
# INCLUDE FILES
#########################################################
set(SOURCES 
	"src/${PROJECT_NAME}.cpp"
    src/naoqi_module_loader.cpp
	)

# The naoqi module
qi_create_lib(${PROJECT_NAME} SHARED ${SOURCES} SUBFOLDER naoqi)
qi_use_lib(${PROJECT_NAME} ALCOMMON BOOST)
qi_stage_lib(${PROJECT_NAME})

#########################################################
# ADD CLIENT
#########################################################

# Create an Executable that can call the motionCapture Module (locally or remotely)
qi_create_bin("${PROJECT_NAME}Client" "${PROJECT_NAME}Client.cpp")
qi_use_lib("${PROJECT_NAME}Client" ALCOMMON ALPROXIES BOOST)


#########################################################
# OTHER THINGS
#########################################################
#Disable BOOST Useless warning
add_definitions(-DBOOST_SIGNALS_NO_DEPRECATION_WARNING)
