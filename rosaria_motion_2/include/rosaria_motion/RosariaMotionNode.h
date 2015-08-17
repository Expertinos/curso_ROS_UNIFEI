/**
 *  RosariaMotionNode.h
 *
 *  Version: 1.0.0.0
 *  Created on: 12/08/2015
 *  Modified on: 13/08/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef ROSARIA_MOTION_NODE_H_
#define ROSARIA_MOTION_NODE_H_

#include <string>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

#include "rosaria_motion/SetVelocity.h"

namespace rosaria_motion 
{

	class RosariaMotionNode 
	{

	public:

		/** Construtores */
		RosariaMotionNode(ros::NodeHandle nh);
		RosariaMotionNode(ros::NodeHandle nh, std::string robot_name);
		/** Destrutor */
		~RosariaMotionNode();

		/** métodos publicos relacionados ao gerenciamento do nó */
		void spin();

	private:
	
		/** atributos privados relacionados ao nó */
		ros::NodeHandle nh_;
		ros::Publisher cmd_vel_pub_;
		ros::ServiceServer set_velocity_srv_;

		/** atributos privados relacionados a identificação do robô */
		std::string robot_name_; // nome do robô

		/** atributos privados relacionados à velocidade do robô */
		double vel_x_; // velocidade linear calculada para o robô setar
		double vel_phi_; // velocidade angular calculada para o robô setar
		/** métodos privados relacionados à velocidade do robô */
		void publishVelocity();
		bool setVelocity(rosaria_motion::SetVelocity::Request  &req, rosaria_motion::SetVelocity::Response &res);

	};

}

#endif /* ROSARIA_MOTION_NODE_H_ */
