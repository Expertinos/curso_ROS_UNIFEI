/**
 *  Robot.h
 *
 *  Version: 0.0.0.0
 *  Created on: 17/08/2015
 *  Modified on: 17/08/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include <string>
#include <ros/ros.h>
#include "login_manager/Beacon.h" 

namespace login_manager  
{

	class Robot 
	{

	public:

		Robot(const login_manager::Beacon::ConstPtr& beacon_msg);
		~Robot();

		ros::Time getTimeStamp();
		std::string getName();
		bool isAvailable();
		double getX();
		double getY();
		double getTheta();

		void setTimeStamp(ros::Time time_stamp);
		void setAvailable(bool available);
		void setPose(double x, double y, double theta);

		bool equals(Robot robot);

		bool operator==(const Robot& robot);
		bool operator!=(const Robot& robot);

	private:
	
		ros::Time time_stamp_;
		std::string name_;
		bool available_;
		double x_, y_, theta_;
		
	};

}

#endif /* ROBOT_H_ */
