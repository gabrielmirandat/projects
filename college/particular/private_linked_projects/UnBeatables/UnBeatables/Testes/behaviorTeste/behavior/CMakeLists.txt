cmake_minimum_required(VERSION 2.8)
project(behavior)

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
  "src/ClasseMenor.cpp"
  "src/Cristina.cpp"
  "src/BehaviorChildTwo.cpp"
  "src/BehaviorChildOne.cpp"
  "src/jhonantansViado.cpp"
  "src/teste1.cpp"
  "src/ClasseMaior.cpp"
	)
# Note: We do not recommend using GLOB to collect a list of source files from your source tree. If no CMakeLists.txt
# file changes when a source is added or removed then the generated build system cannot know when to ask CMake to regenerate.

# The main file
# qi_create_bin(${PROJECT_NAME} main.cpp ${SOURCES})
# qi_use_lib(${PROJECT_NAME} ALCOMMON ALPROXIES BOOST)
FIND_PACKAGE(Boost)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()
add_executable(${PROJECT_NAME} main.cpp ${SOURCES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${Boost_LIBRARIES} rt pthread)
