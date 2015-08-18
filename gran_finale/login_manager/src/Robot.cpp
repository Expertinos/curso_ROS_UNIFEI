/**
 *  Robot.cpp
 *
 *  Version: 0.0.0.0
 *  Created on: 17/08/2015
 *  Modified on: 17/08/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#include "login_manager/Robot.h"

/**
 * Construtor
 */
login_manager::Robot::Robot(const login_manager::Beacon::ConstPtr& beacon_msg)
{
	time_stamp_ = beacon_msg->time_stamp;
	name_ = beacon_msg->name;
	available_ = beacon_msg->available;
	x_ = beacon_msg->x;
	y_ = beacon_msg->y;
	theta_ = beacon_msg->theta;
}

/**
 * Destruidor
 */
login_manager::Robot::~Robot()
{
}

ros::Time login_manager::Robot::getTimeStamp()
{
	return time_stamp_;
}

std::string login_manager::Robot::getName()
{
	return name_;
}

bool login_manager::Robot::isAvailable()
{
	return available_;
}

double login_manager::Robot::getX()
{
	return x_;
}

double login_manager::Robot::getY()
{
	return y_;
}

double login_manager::Robot::getTheta()
{
	return theta_;
}

void login_manager::Robot::setTimeStamp(ros::Time time_stamp) 
{
	time_stamp_ = time_stamp;
}

void login_manager::Robot::setAvailable(bool available)
{
	available_ = available;
}

void login_manager::Robot::setPose(double x, double y, double theta)
{
	x_ = x;
	y_ = y;
	theta_ = theta;
}

bool login_manager::Robot::equals(login_manager::Robot robot)
{
	return name_ == robot.name_;
}

bool login_manager::Robot::operator==(const login_manager::Robot& robot)
{
	return name_ == robot.name_;
}

bool login_manager::Robot::operator!=(const login_manager::Robot& robot) 
{
	return name_ != robot.name_;
}
