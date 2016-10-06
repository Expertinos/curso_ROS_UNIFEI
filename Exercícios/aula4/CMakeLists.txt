cmake_minimum_required(VERSION 2.8.3)

project(aula4)

find_package(catkin REQUIRED COMPONENTS roscpp)

catkin_package(
	 INCLUDE_DIRS include
	 CATKIN_DEPENDS roscpp
	 )

include_directories(include ${catkin_INCLUDE_DIRS})

set(H_FILES
	 include/Node.h
	 include/aula4/EmissorNode.h
	 include/aula4/ReceptorNode.h
	 )

set(CPP_FILES
	 src/Node.cpp
	 src/aula4/EmissorNode.cpp
	 src/aula4/ReceptorNode.cpp
	 )

add_executable(emissor_node src/emissor_node.cpp ${CPP_FILES})
add_dependencies(emissor_node ${catkin_EXPORTED_TARGETS})
target_link_libraries(emissor_node ${catkin_LIBRARIES})

add_executable(receptor_node src/receptor_node.cpp ${CPP_FILES})
add_dependencies(receptor_node ${catkin_EXPORTED_TARGETS})
target_link_libraries(receptor_node ${catkin_LIBRARIES})
