cmake_minimum_required(VERSION 2.8.3)
project(aula5_msgs)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs message_generation std_msgs
)

add_message_files(
	DIRECTORY msg
	FILES Robo.msg
)

generate_messages(DEPENDENCIES geometry_msgs  std_msgs)

catkin_package(
	 CATKIN_DEPENDS message_runtime geometry_msgs std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)
