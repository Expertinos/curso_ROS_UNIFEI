cmake_minimum_required(VERSION 2.8.3)
project(login_manager)

find_package(catkin REQUIRED COMPONENTS
	roscpp
	message_generation
	)

add_message_files(
	FILES
	Beacon.msg
	)

generate_messages(
  	DEPENDENCIES
	std_msgs
	)

catkin_package(
	CATKIN_DEPENDS 
	message_runtime
	)

include_directories(
	include 
	${catkin_INCLUDE_DIRS}
	)

add_executable(login_manager_node 
	src/login_manager_node.cpp
	src/LoginManagerNode.cpp
	src/Robot.cpp
)

add_dependencies(login_manager_node 
	${catkin_EXPORTED_TARGETS}
)

target_link_libraries(login_manager_node
	${catkin_LIBRARIES}
)
