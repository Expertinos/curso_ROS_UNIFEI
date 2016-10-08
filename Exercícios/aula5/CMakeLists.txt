cmake_minimum_required(VERSION 2.8.3)

project(aula5)

find_package(catkin REQUIRED COMPONENTS roscpp aula5_msgs)

catkin_package(
	 INCLUDE_DIRS include
	 CATKIN_DEPENDS roscpp aula5_msgs
	 )

include_directories(include ${catkin_INCLUDE_DIRS})

set(H_FILES
	 include/Node.h
	 include/EnumConverter.h
	 include/aula5/EmissorNode.h
	 include/aula5/ReceptorNode.h
	 include/aula5/distancias/DistanciaConverter.h
	 include/aula5/distancias/DistanciaEnum.h
	 )

set(CPP_FILES
	 src/Node.cpp
	 src/aula5/EmissorNode.cpp
	 src/aula5/ReceptorNode.cpp
	 src/aula5/distancias/DistanciaConverter.cpp
	 )

add_executable(emissor_node src/emissor_node.cpp ${CPP_FILES})
add_dependencies(emissor_node ${catkin_EXPORTED_TARGETS})
target_link_libraries(emissor_node ${catkin_LIBRARIES})

add_executable(receptor_node src/receptor_node.cpp ${CPP_FILES})
add_dependencies(receptor_node ${catkin_EXPORTED_TARGETS})
target_link_libraries(receptor_node ${catkin_LIBRARIES})
