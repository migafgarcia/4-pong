# CMakeList.txt : CMake project for 4-pong, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

include_directories("glad")
include_directories("KHR")
# Add source to this project's executable.
add_executable (4-pong "4-pong.cpp" "glad.c" Ball.cpp Ball.h Player.cpp Player.h)

# TODO: Add tests and install targets if needed.
target_link_libraries(4-pong glfw)
target_link_libraries(4-pong glm)
