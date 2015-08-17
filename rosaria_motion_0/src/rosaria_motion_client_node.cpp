/**
 *  main.cpp
 *
 *  Version: 0.0.0.0
 *  Created on: 13/08/2015
 *  Modified on: 13/08/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#include <ros/ros.h>

double random(double min, double max) {
	return (max - min) * (rand() % 101) / 100 + min;
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "rosaria_motion_client_node");
	ros::NodeHandle nh;
	ros::Rate loop_rate(1);
	ROS_INFO("Rosaria Motion Client Node is up and running!!!");
	while (nh.ok()) 
	{		
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}
