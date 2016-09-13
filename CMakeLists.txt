################
# CMAKE RULES! #
################
# Huge thanks to mxaddict for setting up the CMake build system!

# we need features that are 2.6 >= dependent
cmake_minimum_required(VERSION 2.6)

# lets name the project
project(Clockwork)

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

SET(CORE_SRC 
	src/engine/core/coreEngine.cpp
	src/engine/core/entity.cpp
	src/engine/core/game.cpp
	src/engine/core/input.cpp
	src/engine/core/mappedValues.cpp
	src/engine/core/math3d.cpp
	src/engine/core/profiling.cpp
	src/engine/core/timing.cpp
	src/engine/core/transform.cpp
	src/engine/core/util.cpp
	src/engine/core/coreEngine.h
	src/engine/core/entity.h
	src/engine/core/entityComponent.h
	src/engine/core/game.h
	src/engine/core/input.h
	src/engine/core/mappedValues.h
	src/engine/core/math3d.h
	src/engine/core/profiling.h
	src/engine/core/referenceCounter.h
	src/engine/core/timing.h
	src/engine/core/transform.h
	src/engine/core/util.h
)

SOURCE_GROUP(Core FILES ${CORE_SRC})

SET(COMPONENTS_SRC 
	src/engine/components/freeLook.cpp
	src/engine/components/freeMove.cpp
	src/engine/components/physicsEngineComponent.cpp
	src/engine/components/physicsObjectComponent.cpp
	src/engine/components/freeLook.h
	src/engine/components/freeMove.h
	src/engine/components/meshRenderer.h
	src/engine/components/physicsEngineComponent.h
	src/engine/components/physicsObjectComponent.h
)

SOURCE_GROUP(Components FILES ${COMPONENTS_SRC})

SET(PHYSICS_SRC 
	src/engine/physics/aabb.cpp
	src/engine/physics/boundingSphere.cpp
	src/engine/physics/collider.cpp
	src/engine/physics/physicsEngine.cpp
	src/engine/physics/physicsObject.cpp
	src/engine/physics/plane.cpp
	src/engine/physics/aabb.h
	src/engine/physics/boundingSphere.h
	src/engine/physics/collider.h
	src/engine/physics/physicsEngine.h
	src/engine/physics/physicsObject.h
	src/engine/physics/plane.h
)

SOURCE_GROUP(Physics FILES ${PHYSICS_SRC})

SET(RENDERING_SRC 
	src/engine/rendering/camera.cpp
	src/engine/rendering/lighting.cpp
	src/engine/rendering/material.cpp
	src/engine/rendering/mesh.cpp
	src/engine/rendering/renderingEngine.cpp
	src/engine/rendering/shader.cpp
	src/engine/rendering/texture.cpp
	src/engine/rendering/window.cpp
	src/engine/rendering/camera.h
	src/engine/rendering/lighting.h
	src/engine/rendering/material.h
	src/engine/rendering/mesh.h
	src/engine/rendering/renderingEngine.h
	src/engine/rendering/shader.h
	src/engine/rendering/texture.h
	src/engine/rendering/window.h
)

SOURCE_GROUP(Rendering FILES ${RENDERING_SRC})

SET(LIBS_SRC 
	src/engine/staticLibs/stb_image.c
	src/engine/staticLibs/simdaccel.h
	src/engine/staticLibs/simddefines.h
	src/engine/staticLibs/simdemulator.h
	src/engine/staticLibs/stb_image.h
	src/engine/staticLibs/x86simdaccel.h
)

SOURCE_GROUP(StaticLibs FILES ${LIBS_SRC})

SET(SRC 
	src/engine/testing.cpp
	src/engine/3DEngine.h
	src/engine/testing.h
)

SET(CLOCKWORK_SRC_FILES ${CORE_SRC} ${COMPONENTS_SRC} ${PHYSICS_SRC} ${RENDERING_SRC} ${LIBS_SRC} ${SRC})

# Define the executable
add_library(ClockworkEngine ${CLOCKWORK_SRC_FILES})

# Lets LOAD app our headers!
file(GLOB_RECURSE GAMEHDRS ${Clockwork_SOURCE_DIR}/src/player/*.h)

# Lets LOAD app our sources!
file(GLOB_RECURSE GAMESRCS
	${Clockwork_SOURCE_DIR}/src/player/*.cpp
	${Clockwork_SOURCE_DIR}/src/player/*.c
)

add_executable(Game ${GAMEHDRS} ${GAMESRCS})

# Lets LOAD app our headers!
file(GLOB_RECURSE EDITORHDRS ${Clockwork_SOURCE_DIR}/src/editor/*.h)

# Lets LOAD app our sources!
file(GLOB_RECURSE EDITORSRCS
	${Clockwork_SOURCE_DIR}/src/editor/*.cpp
	${Clockwork_SOURCE_DIR}/src/editor/*.c
)

add_executable(Editor ${EDITORHDRS} ${EDITORSRCS})


# We need a CMAKE_DIR with some code to find external dependencies
SET(Clockwork_CMAKE_DIR "${Clockwork_SOURCE_DIR}/cmake")

#######################################
# LOOK for the packages that we need! #
#######################################

# OpenGL
find_package(OpenGL REQUIRED)

# GLEW
INCLUDE(${Clockwork_CMAKE_DIR}/FindGLEW.cmake)

# SDL2
INCLUDE(${Clockwork_CMAKE_DIR}/FindSDL2.cmake)

# ASSIMP
INCLUDE(${Clockwork_CMAKE_DIR}/FindASSIMP.cmake)

# Define the include DIRs
include_directories(
	${Clockwork_SOURCE_DIR}/headers
	${Clockwork_SOURCE_DIR}/sources
	${HDRS}
	${OPENGL_INCLUDE_DIRS}
	${GLEW_INCLUDE_DIRS}
	${SDL2_INCLUDE_DIRS}
	${ASSIMP_INCLUDE_DIRS}
)

# Define the link libraries
target_link_libraries( ClockworkEngine
	${OPENGL_LIBRARIES}
	${GLEW_LIBRARIES}
	${SDL2_LIBRARIES}
	${ASSIMP_LIBRARIES}
)

# Define the link libraries
target_link_libraries( Game
	ClockworkEngine
)

# Define the link libraries
target_link_libraries( Editor
	ClockworkEngine
)
