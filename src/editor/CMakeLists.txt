SET(SRC main.cpp)
SET(EDITOR_SRC_FILES ${SRC})

add_executable(Editor ${EDITOR_SRC_FILES})

find_package(OpenGL REQUIRED)

include_directories(
	${PROJECT_SOURCE_DIR}/src/engine/Include
	${PROJECT_SOURCE_DIR}/src/3rdParty/SDL/include
	${PROJECT_SOURCE_DIR}/src/3rdParty/GLEW
	${PROJECT_SOURCE_DIR}/src/3rdParty/Assimp/include
)

target_link_libraries( Editor
	${OPENGL_LIBRARIES}
	Clockwork
	GLEW
	SDL
	Assimp
)
