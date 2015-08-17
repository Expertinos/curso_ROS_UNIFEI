/**
 *  main.cpp
 *
 *  Version: 1.0.0.0
 *  Created on: 13/08/2015
 *  Modified on: 13/08/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <ros/ros.h>
#include "rosaria_motion/SetVelocity.h"

#define MIN_LINEAR_VELOCITY 0
#define MAX_LINEAR_VELOCITY 2
#define MIN_ANGULAR_VELOCITY 0
#define MAX_ANGULAR_VELOCITY 1

double random(double min, double max) {
	return (max - min) * (rand() % 101) / 100 + min;
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "rosaria_motion_client_node");
	ros::NodeHandle nh;
	ros::ServiceClient client = nh.serviceClient<rosaria_motion::SetVelocity>("/RosAria/set_velocity");
	ros::Rate loop_rate(1);
	ROS_INFO("Rosaria Motion Client Node is up and running!!!");
	rosaria_motion::SetVelocity set_velocity_cli;
	srand(time(NULL));
	while (nh.ok()) 
	{		
		set_velocity_cli.request.linear = random(MIN_LINEAR_VELOCITY, MAX_LINEAR_VELOCITY);
		set_velocity_cli.request.angular = random(MIN_ANGULAR_VELOCITY, MAX_ANGULAR_VELOCITY);
		if (client.call(set_velocity_cli))
		{
			ROS_INFO("Message: %s", set_velocity_cli.response.message.c_str());
		}
		else
		{
			ROS_ERROR("Failed to call service '/RosAria/set_velocity");
			return 1;
		}
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}
