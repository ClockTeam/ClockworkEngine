# Define target name
set (TARGET_NAME GLEW)

# Define source files
file(GLOB_RECURSE CPP_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp *.c)
file(GLOB_RECURSE H_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
set (SOURCE_FILES ${CPP_FILES} ${H_FILES})

# Define dependency libs
set (INCLUDE_DIRS .)

add_library (${TARGET_NAME} STATIC ${CPP_FILES} ${H_FILES})
include_directories (${INCLUDE_DIRS})
target_link_libraries (${TARGET_NAME} ${ABSOLUTE_PATH_LIBS} ${LIBS})

# Install headers for building the Urho3D library
#install_header_files (DIRECTORY ./ DESTINATION ${DEST_INCLUDE_DIR}/ThirdParty/GLEW FILES_MATCHING PATTERN *.h BUILD_TREE_ONLY)  # Note: the trailing slash is significant
