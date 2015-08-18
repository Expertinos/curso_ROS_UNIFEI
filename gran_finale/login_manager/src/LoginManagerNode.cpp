/**
 *  LoginManagerNode.cpp
 *
 *  Version: 0.0.0.0
 *  Created on: 17/08/2015
 *  Modified on: 17/08/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#include "login_manager/LoginManagerNode.h"

/**
 * Construtor
 */
login_manager::LoginManagerNode::LoginManagerNode(ros::NodeHandle nh) :
	nh_(nh)
{
	/** 
	 * criação de um novo assinante do tópico '/beacon', o qual 
	 * receberá mensagens do tipo 'login_manager/Beacon'
         */
	beacon_sub_ = nh_.subscribe("/beacon", 10, &login_manager::LoginManagerNode::beaconCallback, this);
}

/**
 * Destruidor
 */
login_manager::LoginManagerNode::~LoginManagerNode()
{
	nh_.deleteParam("number_of_logged_robots");
	beacon_sub_.shutdown();
}

/**
 * 
 */
void login_manager::LoginManagerNode::spin() 
{
	ROS_INFO("Longin Manager Node is up and running!!!");
	ros::Rate loop_rate(10.0);
	while (nh_.ok()) 
	{
		checkLoggedRobots();
		ros::spinOnce();
		loop_rate.sleep();
	}
}

bool login_manager::LoginManagerNode::isStillLogged(login_manager::Robot robot)
{
	
	return (ros::Time::now() - robot.getTimeStamp()).toSec() < MAX_SILENCE_DURATION;
}

void login_manager::LoginManagerNode::checkLoggedRobots() 
{
	for (int i = 0; i < robots_.size(); i++) 
	{
		if(!isStillLogged(robots_.at(i)))
		{
			std::string robot_name = robots_.at(i).getName();
			robots_.erase(robots_.begin() + i);
			ROS_INFO("%s is not logged anymore!!!", robot_name.c_str());
		}
	}
	int number_of_logged_robots = robots_.size();
	nh_.setParam("/number_of_logged_robots", number_of_logged_robots);
	ROS_INFO("Number of logged robots: %d", number_of_logged_robots);
}

/**
 * Esta rotina é executada quando uma nova mensagem 'login_manager/Beacon'
 * é disponibilizada no tópico '/beacon'
 */
void login_manager::LoginManagerNode::beaconCallback(const login_manager::Beacon::ConstPtr& beacon_msg) 
{
	login_manager::Robot robot(beacon_msg);
	ROS_DEBUG("Beacon signal of : %s", robot.getName().c_str());
	for (int i = 0; i < robots_.size(); i++) 
	{
		if (robot == robots_.at(i)) 
		{
			robots_.erase(robots_.begin() + i);
			robots_.push_back(robot);
			return;
		}
	}
	robots_.push_back(robot);
}


