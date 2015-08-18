/**
 *  LoginManagerNode.h
 *
 *  Version: 0.0.0.0
 *  Created on: 17/08/2015
 *  Modified on: 17/08/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef LOGIN_MANAGER_NODE_H_
#define LOGIN_MANAGER_NODE_H_

#include <vector>
#include <string>
#include <ros/ros.h>
#include "login_manager/Robot.h"
#include "login_manager/Beacon.h" 

#define MAX_SILENCE_DURATION 5

namespace login_manager 
{

	class LoginManagerNode 
	{

	public:

		/** Construtores */
		LoginManagerNode(ros::NodeHandle nh);
		/** Destrutor */
		~LoginManagerNode();

		/** métodos publicos relacionados ao gerenciamento do nó */
		void spin();

	private:
	
		/** atributos privados relacionados ao nó */
		ros::NodeHandle nh_;
		ros::Subscriber beacon_sub_;

		std::vector<login_manager::Robot> robots_;

		bool isStillLogged(login_manager::Robot robot);
		void checkLoggedRobots();
		void beaconCallback(const login_manager::Beacon::ConstPtr& beacon_msg);

	};

}

#endif /* LOGIN_MANAGER_NODE_H_ */
