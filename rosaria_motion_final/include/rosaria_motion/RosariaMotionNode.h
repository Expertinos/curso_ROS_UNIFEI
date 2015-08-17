/**
 *  RosariaMotionNode.h
 *
 *  Version: 2.0.0.0
 *  Created on: 12/08/2015
 *  Modified on: 13/08/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef ROSARIA_MOTION_NODE_H_
#define ROSARIA_MOTION_NODE_H_

#include <string>
#include <math.h> 
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_datatypes.h>

#include "rosaria_motion/SetVelocity.h"

#define PI 3.14159
#define sign(a) (((a) < 0) ? -1 : (((a) > 0) ? 1 : 0))

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
		ros::Subscriber pose_sub_;
		ros::Publisher cmd_vel_pub_;
		ros::ServiceServer set_velocity_srv_;

		/** atributos privados relacionados a identificação do robô */
		std::string robot_name_; // nome do robô

		/** atributos privados relacionados à velocidade do robô */
		double vel_x_; // velocidade linear calculada para o robô setar
		double vel_phi_; // velocidade angular calculada para o robô setar
		/** métodos privados relacionados à velocidade do robô */
		void publishVelocity();
		void calculateVelocity();
		bool setVelocity(rosaria_motion::SetVelocity::Request  &req, rosaria_motion::SetVelocity::Response &res);

		/** atributos privados relacionados à odometria do robô */ 
		bool pose_setted_;
		double start_x_, start_y_, start_phi_; // odometria considerada inicial
		double curr_x_, curr_y_, curr_phi_; // odometria atual
		double prev_x_, prev_y_, prev_phi_; // odometria a priori
		double disp_x_, disp_y_, disp_phi_; // odometria deslocada
		double prev_disp_x_, prev_disp_y_, prev_disp_phi_; // odometria deslocada a priori
 
		/** métodos privados relacionados à odometria do robô */
		void poseCallback(const nav_msgs::Odometry::ConstPtr& odometry_msg);
		void resetOdometry();

	};

}

#endif /* ROSARIA_MOTION_NODE_H_ */
