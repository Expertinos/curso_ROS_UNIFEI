cmake_minimum_required(VERSION 2.8.3)
project(aula6)

set(fuzzylite ~/fuzzylite/fuzzylite)

find_package(catkin REQUIRED COMPONENTS
	 roscpp
	 sensor_msgs
	 geometry_msgs
)

catkin_package(
	 INCLUDE_DIRS include
	 CATKIN_DEPENDS roscpp sensor_msgs geometry_msgs
)

include_directories(
	 include
	 ${catkin_INCLUDE_DIRS}
	 ${fuzzylite}/release/bin
	 ${fuzzylite}
)

link_directories(
	${fuzzylite}/release/bin
	${fuzzylite}
)

set(H_FILES
	 include/Node.h
	 include/EnumConverter.h
	 include/aula6/ControllerNode.h
	 )

set(CPP_FILES
	 src/Node.cpp
	 src/aula6/FuzzyControllerNode.cpp
	 )

add_executable(fuzzy_controller_node src/fuzzy_controller_node.cpp ${CPP_FILES})
add_dependencies(fuzzy_controller_node ${catkin_EXPORTED_TARGETS})
target_link_libraries(fuzzy_controller_node ${catkin_LIBRARIES} fuzzylite)
