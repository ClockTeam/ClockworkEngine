################
# CMAKE RULES! #
################
# Huge thanks to mxaddict for setting up the CMake build system!

# we need features that are 2.6 >= dependent
cmake_minimum_required(VERSION 2.6)

# lets name the project
project(3DEngineCpp)

# add the -c and -Wall flags
add_definitions(
	-c
	-Wall
)

if ( CMAKE_BUILD_TYPE STREQUAL "" )
	# CMake defaults to leaving CMAKE_BUILD_TYPE empty. This screws up
	# differentiation between debug and release builds.
	set(
		CMAKE_BUILD_TYPE
			"Debug"
		CACHE STRING
			"Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) \"Debug\" \"Release\" \"RelWithDebInfo\" \"MinSizeRel\"."
		FORCE
	)
endif ( CMAKE_BUILD_TYPE STREQUAL "" )

if ( CMAKE_BUILD_TYPE STREQUAL "Release" )
add_definitions( -O2 )
endif ( CMAKE_BUILD_TYPE STREQUAL "Release" )

# Lets LOAD app our headers!
file(GLOB_RECURSE HDRS ${3DEngineCpp_SOURCE_DIR}/src/Engine/*.h)

# Lets LOAD app our sources!
file(GLOB_RECURSE SRCS
	${3DEngineCpp_SOURCE_DIR}/src/Engine/*.cpp
	${3DEngineCpp_SOURCE_DIR}/src/Engine/*.c
)

# Define the executable
add_library(3DEngineCpp ${HDRS} ${SRCS})

# Lets LOAD app our headers!
file(GLOB_RECURSE GAMEHDRS ${3DEngineCpp_SOURCE_DIR}/src/Test/*.h)

# Lets LOAD app our sources!
file(GLOB_RECURSE GAMESRCS
	${3DEngineCpp_SOURCE_DIR}/src/Test/*.cpp
	${3DEngineCpp_SOURCE_DIR}/src/Test/*.c
)

add_executable(Game ${GAMEHDRS} ${GAMESRCS})


# We need a CMAKE_DIR with some code to find external dependencies
SET(3DEngineCpp_CMAKE_DIR "${3DEngineCpp_SOURCE_DIR}/cmake")

#######################################
# LOOK for the packages that we need! #
#######################################

# OpenGL
find_package(OpenGL REQUIRED)

# GLEW
INCLUDE(${3DEngineCpp_CMAKE_DIR}/FindGLEW.cmake)

# SDL2
INCLUDE(${3DEngineCpp_CMAKE_DIR}/FindSDL2.cmake)

# ASSIMP
INCLUDE(${3DEngineCpp_CMAKE_DIR}/FindASSIMP.cmake)

# Define the include DIRs
include_directories(
	${3DEngineCpp_SOURCE_DIR}/headers
	${3DEngineCpp_SOURCE_DIR}/sources
	${HDRS}
	${OPENGL_INCLUDE_DIRS}
	${GLEW_INCLUDE_DIRS}
	${SDL2_INCLUDE_DIRS}
	${ASSIMP_INCLUDE_DIRS}
)

# Define the link libraries
target_link_libraries( 3DEngineCpp
	${OPENGL_LIBRARIES}
	${GLEW_LIBRARIES}
	${SDL2_LIBRARIES}
	${ASSIMP_LIBRARIES}
)

# Define the link libraries
target_link_libraries( Game
	3DEngineCpp
)
