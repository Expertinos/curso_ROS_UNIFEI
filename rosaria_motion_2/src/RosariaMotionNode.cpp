/**
 *  RosariaMotionNode.cpp
 *
 *  Version: 1.0.0.0
 *  Created on: 12/08/2015
 *  Modified on: 13/08/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#include "rosaria_motion/RosariaMotionNode.h"

/**
 * Construtor padrão, carrega nome do robô através da leitura dos parâmetros do nó.
 */
rosaria_motion::RosariaMotionNode::RosariaMotionNode(ros::NodeHandle nh) :
	nh_(nh)
{
	nh_.param<std::string>("rosaria_motion_node/robot_name", robot_name_, "Robô da UNIFEI");

	/** 
	 * criação de um novo publicador do tópico 'cmd_vel', o qual
	 * transmitirá mensagens do tipo 'geometry_msgs/Twist'
	 */
	cmd_vel_pub_ = nh_.advertise<geometry_msgs::Twist>("/RosAria/cmd_vel", 1);

	/**
	 * criação de um novo servidor de serviço do tipo 'rosaria_motion/SetVelocity'
	 */
	set_velocity_srv_ = nh_.advertiseService("/RosAria/set_velocity", &RosariaMotionNode::setVelocity, this);
}

/**
 * Construtor opicional.
 */
rosaria_motion::RosariaMotionNode::RosariaMotionNode(ros::NodeHandle nh, std::string robot_name) :
	nh_(nh)
{	
	robot_name_ = robot_name;

	/** 
	 * criação de um novo publicador do tópico 'cmd_vel', o qual
	 * transmitirá mensagens do tipo 'geometry_msgs/Twist'
	 */
	cmd_vel_pub_ = nh_.advertise<geometry_msgs::Twist>("/RosAria/cmd_vel", 1);

	/**
	 * criação de um novo servidor de serviço do tipo 'rosaria_motion/SetVelocity'
	 */
	set_velocity_srv_ = nh_.advertiseService("/RosAria/set_velocity", &RosariaMotionNode::setVelocity, this);
}

/**
 * Destruidor
 */
rosaria_motion::RosariaMotionNode::~RosariaMotionNode()
{
	cmd_vel_pub_.shutdown();
}

/**
 * 
 */
void rosaria_motion::RosariaMotionNode::spin() 
{
	ROS_INFO("Rosaria Motion Node is up and running!!!");
	ros::Rate loop_rate(10.0);
	while (nh_.ok()) 
	{
		ros::spinOnce();
		loop_rate.sleep();
	}
}

/**
 * publica uma nova mensagem do tipo 'geometry_msgs/Twist'
 * no tópico 'cmd_vel'
 */
void rosaria_motion::RosariaMotionNode::publishVelocity() 
{
	geometry_msgs::Twist twist_msg;
	twist_msg.linear.x = vel_x_;
	twist_msg.angular.z = vel_phi_;
	cmd_vel_pub_.publish(twist_msg);
}

/**
 * Seta os valores de velocidade passados através dos requisitos e retorna uma mensagem
 */
bool rosaria_motion::RosariaMotionNode::setVelocity(rosaria_motion::SetVelocity::Request  &req, rosaria_motion::SetVelocity::Response &res)
{
	vel_x_ = req.linear;
	vel_phi_ = req.angular;
	ROS_INFO("New linear velocity: %f", vel_x_);
	ROS_INFO("New angular velocity: %f", vel_phi_);
	publishVelocity();
	return true;
}
