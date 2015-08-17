/**
 *  main.cpp
 *
 *  Version: 1.0.0.0
 *  Created on: 13/08/2015
 *  Modified on: 13/08/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#include "rosaria_motion/RosariaMotionNode.h"

int main(int argc, char** argv)
{
	ros::init(argc, argv, "rosaria_motion_node");
	ros::NodeHandle nh;
	rosaria_motion::RosariaMotionNode node(nh);
	node.spin();
	return 0;
}
