SET(CORE_SRC 
	Source/core/coreEngine.cpp
	Source/core/entity.cpp
	Source/core/game.cpp
	Source/core/input.cpp
	Source/core/mappedValues.cpp
	Source/core/math3d.cpp
	Source/core/profiling.cpp
	Source/core/timing.cpp
	Source/core/transform.cpp
	Source/core/util.cpp
	Include/core/coreEngine.h
	Include/core/entity.h
	Include/core/entityComponent.h
	Include/core/game.h
	Include/core/input.h
	Include/core/mappedValues.h
	Include/core/math3d.h
	Include/core/profiling.h
	Include/core/referenceCounter.h
	Include/core/timing.h
	Include/core/transform.h
	Include/core/util.h
)

SOURCE_GROUP(Core FILES ${CORE_SRC})

SET(COMPONENTS_SRC 
	Source/components/freeLook.cpp
	Source/components/freeMove.cpp
	Source/components/physicsEngineComponent.cpp
	Source/components/physicsObjectComponent.cpp
	Include/components/freeLook.h
	Include/components/freeMove.h
	Include/components/meshRenderer.h
	Include/components/physicsEngineComponent.h
	Include/components/physicsObjectComponent.h
)

SOURCE_GROUP(Components FILES ${COMPONENTS_SRC})

SET(PHYSICS_SRC 
	Source/physics/aabb.cpp
	Source/physics/boundingSphere.cpp
	Source/physics/collider.cpp
	Source/physics/physicsEngine.cpp
	Source/physics/physicsObject.cpp
	Source/physics/plane.cpp
	Include/physics/aabb.h
	Include/physics/boundingSphere.h
	Include/physics/collider.h
	Include/physics/physicsEngine.h
	Include/physics/physicsObject.h
	Include/physics/plane.h
)

SOURCE_GROUP(Physics FILES ${PHYSICS_SRC})

SET(RENDERING_SRC 
	Source/rendering/camera.cpp
	Source/rendering/lighting.cpp
	Source/rendering/material.cpp
	Source/rendering/mesh.cpp
	Source/rendering/renderingEngine.cpp
	Source/rendering/shader.cpp
	Source/rendering/texture.cpp
	Source/rendering/window.cpp
	Include/rendering/camera.h
	Include/rendering/lighting.h
	Include/rendering/material.h
	Include/rendering/mesh.h
	Include/rendering/renderingEngine.h
	Include/rendering/shader.h
	Include/rendering/texture.h
	Include/rendering/window.h
)

SOURCE_GROUP(Rendering FILES ${RENDERING_SRC})

SET(LIBS_SRC 
	Source/staticLibs/stb_image.c
	Include/staticLibs/simdaccel.h
	Include/staticLibs/simddefines.h
	Include/staticLibs/simdemulator.h
	Include/staticLibs/stb_image.h
	Include/staticLibs/x86simdaccel.h
)

SOURCE_GROUP(StaticLibs FILES ${LIBS_SRC})

SET(SRC 
	Source/testing.cpp
	Include/3DEngine.h
	Include/testing.h
)

SET(CLOCKWORK_SRC_FILES ${CORE_SRC} ${COMPONENTS_SRC} ${PHYSICS_SRC} ${RENDERING_SRC} ${LIBS_SRC} ${SRC})
add_library(${CLOCKWORK_NAME} STATIC ${CLOCKWORK_SRC_FILES})
# OpenGL
find_package(OpenGL REQUIRED)

include_directories(
	${PROJECT_SOURCE_DIR}/src/3rdParty/SDL/include
	${PROJECT_SOURCE_DIR}/src/3rdParty/GLEW
	${PROJECT_SOURCE_DIR}/src/3rdParty/Assimp/include
)

target_link_libraries( ${CLOCKWORK_NAME}
	${OPENGL_LIBRARIES}
	Assimp
	GLEW
	SDL
)
