cmake_minimum_required(VERSION 2.8.3)
project(aula3)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  std_msgs
)

catkin_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(emissor src/emissor.cpp)
target_link_libraries(emissor ${catkin_LIBRARIES})
