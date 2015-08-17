/**
 *  RosariaMotionNode.h
 *
 *  Version: 0.0.0.0
 *  Created on: 12/08/2015
 *  Modified on: 13/08/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef ROSARIA_MOTION_NODE_H_
#define ROSARIA_MOTION_NODE_H_

#include <ros/ros.h>

namespace rosaria_motion 
{

	class RosariaMotionNode 
	{

	public:

		/** Construtor */
		RosariaMotionNode(ros::NodeHandle nh, std::string robot_name);
		/** Destrutor */
		~RosariaMotionNode();

		/** métodos publicos relacionados ao gerenciamento do nó */
		void spin();

	private:
	
		/** atributos privados relacionados ao nó */
		ros::NodeHandle nh_;

		/** atributos privados relacionados a identificação do robô */
		std::string robot_name_; // nome do robô

	};

}

#endif /* ROSARIA_MOTION_NODE_H_ */
