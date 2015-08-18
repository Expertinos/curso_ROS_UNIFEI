/**
 *  main.cpp
 *
 *  Version: 0.0.0.0
 *  Created on: 17/08/2015
 *  Modified on: 17/08/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#include "login_manager/LoginManagerNode.h"

int main(int argc, char** argv)
{
	ros::init(argc, argv, "login_manager_node");
	ros::NodeHandle nh;
	login_manager::LoginManagerNode node(nh);
	node.spin();
	return 0;
}
