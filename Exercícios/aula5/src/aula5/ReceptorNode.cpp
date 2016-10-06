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
  timer_ = nh->createTimer(ros::Duration(10), &ReceptorNode::timerCallback, this);
}

ReceptorNode::~ReceptorNode()
{}

void ReceptorNode::timerCallback(const ros::TimerEvent &event)
{
  Node::shutdown();
}

}

