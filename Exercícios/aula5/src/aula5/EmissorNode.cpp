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

#include "aula5/EmissorNode.h"

namespace aula5
{

EmissorNode::EmissorNode(ros::NodeHandle *nh)
  : Node(nh, 10)
{
  timer_ = nh->createTimer(ros::Duration(6.75), &EmissorNode::timerCallback, this);
  robo_info_pub_ = nh->advertise<aula5_msgs::Robo>("robo_info", 1);
}

EmissorNode::~EmissorNode()
{
  robo_info_pub_.shutdown();
}

void EmissorNode::timerCallback(const ros::TimerEvent &event)
{
  aula5_msgs::Robo msg;
  msg.nome = "robo1";
  msg.header.stamp = ros::Time::now();
  msg.distancia = aula5::distancias::MUITO_LONGE;

  /**
   *
   * dado um objeto nav_msgs::Odometry odom:
   *
   *    msg.postura.x = msg->pose.pose.position.x; // em milimetros
   *    msg.postura.y = msg->pose.pose.position.y; // em milimetros
   *    msg.postura.theta = tf::getYaw(msg->pose.pose.orientation); // em radianos
   *
   * lembrando que tf::getYaw e definido no cabecalho:
   *
   *    tf/transform_datatypes.h
   *
   */

  robo_info_pub_.publish(msg);
}

}

