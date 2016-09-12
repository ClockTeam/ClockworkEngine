add_subdirectory(3rdParty/Assimp)
add_subdirectory(3rdParty/GLEW)
add_subdirectory(3rdParty/SDL)


add_subdirectory(engine)

if(CLOCKWORK_EDITOR)
   add_subdirectory(editor)
endif()

# add_subdirectory(player)