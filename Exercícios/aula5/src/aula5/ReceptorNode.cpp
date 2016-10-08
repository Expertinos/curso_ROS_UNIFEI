/**
 *  This source file implements the EmissorNode class, which is also a
 *  Node class via enhancement.
 *
 *  Version: 1.0.0
 *  Created on: 05/10/2016
 *  Modified on: 05/10/2016
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Professores de ECA419 (eca419.unifei@gmail.com)
 */

#include "aula5/ReceptorNode.h"

namespace aula5
{

ReceptorNode::ReceptorNode(ros::NodeHandle *nh)
  : Node(nh, 20)
{
  robo_info_sub_ = nh->subscribe("robo_info", 10, &ReceptorNode::infoCallback, this);
}

ReceptorNode::~ReceptorNode()
{
  robo_info_sub_.shutdown();
}

void ReceptorNode::infoCallback(const aula5_msgs::Robo::ConstPtr& info_msg)
{
  aula5::distancias::DistanciaConverter converter(info_msg->distancia);
  ROS_INFO("Infos de %s: %s @(%f [mm], %f [mm], %f [deg])", info_msg->nome.c_str(), converter.c_str(),
           info_msg->postura.x, info_msg->postura.y, info_msg->postura.theta * 180 / PI);
}

}
