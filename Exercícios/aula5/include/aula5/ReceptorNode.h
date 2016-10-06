/**
 *  This header file defines the ReceptorNode class, which is also a
 *  Node class via enhancement.
 *
 *  Version: 1.0.0
 *  Created on: 05/10/2016
 *  Modified on: 05/10/2016
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Professores de ECA419 (eca419.unifei@gmail.com)
 */

#ifndef _RECEPTOR_NODE_H_
#define _RECEPTOR_NODE_H_

#include "Node.h"

namespace aula5
{

class ReceptorNode : public Node
{
public:
  ReceptorNode(ros::NodeHandle *nh);
  virtual ~ReceptorNode();

private:
  void timerCallback(const ros::TimerEvent& event);
  ros::Timer timer_;
};

}

#endif // _RECEPTOR_NODE_H_
