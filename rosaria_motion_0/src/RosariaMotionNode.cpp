/**
 *  RosariaMotionNode.cpp
 *
 *  Version: 0.0.0.0
 *  Created on: 12/08/2015
 *  Modified on: 13/08/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#include "rosaria_motion/RosariaMotionNode.h"

/**
 * Construtor.
 */
rosaria_motion::RosariaMotionNode::RosariaMotionNode(ros::NodeHandle nh, std::string robot_name) :
	nh_(nh)
{	
	robot_name_ = robot_name;	
}

/**
 * Destruidor
 */
rosaria_motion::RosariaMotionNode::~RosariaMotionNode()
{
}

/**
 * 
 */
void rosaria_motion::RosariaMotionNode::spin() 
{
	ROS_INFO("Rosaria Motion Node is up and running!!!");
	ROS_INFO("Robot name is %s", robot_name_.c_str());
	ros::Rate loop_rate(10.0);
	while (nh_.ok()) 
	{
		ros::spinOnce();
		loop_rate.sleep();
	}
}
