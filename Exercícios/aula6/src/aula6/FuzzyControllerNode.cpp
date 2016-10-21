/**
 *  This source file implements the FuzzyControllerNode class, which is also a
 *  Node class via enhancement.
 *
 *  Version: 1.0.0
 *  Created on: 21/10/2016
 *  Modified on: 21/10/2016
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Professores de ECA419 (eca419.unifei@gmail.com)
 */

#include "aula6/FuzzyControllerNode.h"

namespace aula6
{

FuzzyControllerNode::FuzzyControllerNode(ros::NodeHandle *nh)
  : Node(nh, 20)
{}

FuzzyControllerNode::~FuzzyControllerNode()
{}

void FuzzyControllerNode::controlLoop()
{
  ROS_WARN("Spinning FuzzyControllerNode!!!");
}

}
