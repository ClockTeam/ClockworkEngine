cmake_minimum_required(VERSION 2.8.7 FATAL_ERROR)

project(Clockwork)

if($ENV{BUILD_NUMBER})
  set(BUILD_NUMBER $ENV{BUILD_NUMBER})
else()
  set(BUILD_NUMBER 0)
endif()

set(CLOCKWORK_NAME "Clockwork")
set(CLOCKWORK_VERSION "0.0.3.${BUILD_NUMBER}")
set(CLOCKWORK_BRIEF "${MYLIB_NAME} is a 3D game engine designed to help me experiment.")

option(CLOCKWORK_EDITOR "Enables building the editor" ON)

set_property( GLOBAL PROPERTY USE_FOLDERS ON)

# code coverage options
set(GCOV_FLAGS "-fprofile-arcs -ftest-coverage")

set(DEBUG_FLAGS "-g -O0 -Wall")
set(RELEASE_FLAGS "-O3")

set(CMAKE_CXX_FLAGS ${RELEASE_FLAGS})
set(CMAKE_C_FLAGS ${RELEASE_FLAGS})

set(CMAKE_CXX_FLAGS_DEBUG ${DEBUG_FLAGS})
set(CMAKE_CXX_FLAGS_DEBUG ${GCOV_FLAGS})
set(CMAKE_C_FLAGS_DEBUG ${DEBUG_FLAGS})
set(CMAKE_C_FLAGS_DEBUG ${GCOV_FLAGS})
set(CMAKE_EXE_LINKER_FLAGS_DEBUG ${GCOV_FLAGS})

set(CMAKE_CONFIGURATION_TYPES Debug Release)

MACRO(SOURCE_GROUP_BY_FOLDER target)
  SET(SOURCE_GROUP_DELIMITER "/")
  SET(last_dir "")
  SET(files "")
  FOREACH(file ${${target}_SRC} ${${target}_HEADERS})
    file(RELATIVE_PATH relative_file "${PROJECT_SOURCE_DIR}/${target}" ${file})
    GET_FILENAME_COMPONENT(dir "${relative_file}" PATH)
    IF (NOT "${dir}" STREQUAL "${last_dir}")
      IF (files)
        SOURCE_GROUP("${last_dir}" FILES ${files})
      ENDIF (files)
      SET(files "")
    ENDIF (NOT "${dir}" STREQUAL "${last_dir}")
    SET(files ${files} ${file})
    SET(last_dir "${dir}")
  ENDFOREACH(file)
  IF (files)
    SOURCE_GROUP("${last_dir}" FILES ${files})
  ENDIF (files)
ENDMACRO(SOURCE_GROUP_BY_FOLDER)

add_subdirectory(src)

SOURCE_GROUP_BY_FOLDER(Clockwork)

set_target_properties(GLEW PROPERTIES FOLDER 3rdParty)
set_target_properties(SDL PROPERTIES FOLDER 3rdParty)
set_target_properties(Assimp PROPERTIES FOLDER 3rdParty)