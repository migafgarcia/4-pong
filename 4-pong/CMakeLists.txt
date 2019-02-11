# CMakeList.txt : CMake project for 4-pong, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.8)

# Add source to this project's executable.
add_executable(4-pong 4-pong.cpp game_objects/GameObject.cpp shaders/Shaders.cpp shaders/Shaders.h controllers/Player.h controllers/HumanPlayer.cpp controllers/HumanPlayer.h controllers/AiPlayer.cpp controllers/AiPlayer.h Controller.cpp Controller.h)

# TODO: Add tests and install targets if needed.
target_link_libraries(4-pong glfw)
target_link_libraries(4-pong glm)
target_link_libraries(4-pong glad)
