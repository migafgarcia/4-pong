cmake_minimum_required(VERSION 3.8)

add_executable(4-pong 4-pong.cpp game_objects/GameObject.cpp shaders/Shaders.cpp shaders/Shaders.h players/Player.h players/HumanPlayer.cpp players/HumanPlayer.h players/AiPlayer.cpp players/AiPlayer.h controllers/Controller.cpp controllers/Controller.h controllers/PaddleController.cpp controllers/PaddleController.h controllers/BallController.cpp controllers/BallController.h Collisions.cpp Collisions.h)

target_link_libraries(4-pong glfw)
target_link_libraries(4-pong glm)
target_link_libraries(4-pong glad)
