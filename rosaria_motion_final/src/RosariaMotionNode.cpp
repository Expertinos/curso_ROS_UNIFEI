/**
 *  RosariaMotionNode.cpp
 *
 *  Version: 2.0.0.0
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
	pose_setted_ = false;

	/** 
	 * criação de um novo publicador do tópico 'cmd_vel', o qual
	 * transmitirá mensagens do tipo 'geometry_msgs/Twist'
	 */
	cmd_vel_pub_ = nh_.advertise<geometry_msgs::Twist>("/RosAria/cmd_vel", 1);

	/** 
	 * criação de um novo assinante do tópico 'pose', o qual 
	 * receberá mensagens do tipo 'nav_msgs/Odometry'
         */
	pose_sub_ = nh_.subscribe("/RosAria/pose", 1, &rosaria_motion::RosariaMotionNode::poseCallback, this);

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
	pose_setted_ = false;

	/** 
	 * criação de um novo publicador do tópico 'cmd_vel', o qual
	 * transmitirá mensagens do tipo 'geometry_msgs/Twist'
	 */
	cmd_vel_pub_ = nh_.advertise<geometry_msgs::Twist>("/RosAria/cmd_vel", 1);

	/** 
	 * criação de um novo assinante do tópico 'pose', o qual 
	 * receberá mensagens do tipo 'nav_msgs/Odometry'
         */
	pose_sub_ = nh_.subscribe("/RosAria/pose", 1, &rosaria_motion::RosariaMotionNode::poseCallback, this);

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
	pose_sub_.shutdown();
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
		calculateVelocity();
		ros::spinOnce();
		loop_rate.sleep();
	}
}

/**
 * 
 */
void rosaria_motion::RosariaMotionNode::calculateVelocity() 
{
	if (prev_disp_x_ < 0 && disp_x_ > 0)
	{
		vel_phi_ = -vel_phi_;
		resetOdometry();
		publishVelocity();
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
	if (req.linear == 0 && req.angular == 0) 
	{
		res.message = "Jah jah que para. rsrsrs";
	}
	else if (req.linear == 0) 
	{
		res.message = "Vai ficar rodopiando.";
	}
	else if (req.angular == 0) 
	{
		res.message = "Ao infinito e aleinh!!!";
	}
	else if (req.linear < 0) 
	{
		res.message = "Fala serio!! Andar de reh??? Sinto muito, soh vale pra frente.";
	}
	else
	{
		res.message = "Xah comigo!!!";
	}
	vel_x_ = fabs(req.linear);
	vel_phi_ = req.angular;
	ROS_INFO("New linear velocity: %f", vel_x_);
	ROS_INFO("New angular velocity: %f", vel_phi_);
	resetOdometry();
	publishVelocity();
	return true;
}

/**
 * zera a odometria do robô
 */
void rosaria_motion::RosariaMotionNode::resetOdometry() 
{
	start_x_ = curr_x_;
	start_y_ = curr_y_;
	start_phi_ = curr_phi_;
}

/**
 * Esta rotina é executada quando uma nova mensagem 'nav_msgs/Odometry'
 * é disponibilizada no tópico 'pose'
 */
void rosaria_motion::RosariaMotionNode::poseCallback(const nav_msgs::Odometry::ConstPtr& odometry_msg) 
{
	curr_x_ = odometry_msg->pose.pose.position.x;
	curr_y_ = odometry_msg->pose.pose.position.y;
	curr_phi_ = tf::getYaw(odometry_msg->pose.pose.orientation);
	if (!pose_setted_) 
	{
		ROS_INFO("%s's odometry initialized!!!", robot_name_.c_str());
		pose_setted_ = true;
		prev_x_ = curr_x_;
		prev_y_ = curr_y_;
		prev_phi_ = curr_phi_;
		prev_disp_x_ = 0;
		prev_disp_y_ = 0;
		prev_disp_phi_ = 0;
	}
	prev_disp_x_ = disp_x_;
	prev_disp_y_ = disp_y_;
	prev_disp_phi_ = disp_phi_;
	disp_x_ = (curr_x_ - start_x_) * cos(-start_phi_) - (curr_y_ - start_y_) * sin(-start_phi_);
	disp_y_ = (curr_y_ - start_y_) * cos(-start_phi_) + (curr_x_ - start_x_) * sin(-start_phi_);
	while (curr_phi_ - prev_phi_ < PI) 
	{
		curr_phi_ += 2 * PI;
	}
	while (curr_phi_ - prev_phi_ > PI) 
	{
		curr_phi_ -= 2 * PI;
	}
	disp_phi_ += curr_phi_ - prev_phi_;
	prev_x_ = curr_x_;
	prev_y_ = curr_y_;
	prev_phi_ = curr_phi_;
}


