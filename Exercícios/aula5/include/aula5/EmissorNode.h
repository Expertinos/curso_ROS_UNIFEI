/**
 *  This header file defines the EmissorNode class, which is also a
 *  Node class via enhancement.
 *
 *  Version: 1.0.0
 *  Created on: 05/10/2016
 *  Modified on: 05/10/2016
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Professores de ECA419 (eca419.unifei@gmail.com)
 */

#ifndef _EMISSOR_NODE_H_
#define _EMISSOR_NODE_H_

#include "Node.h"

namespace aula5
{

class EmissorNode : public Node
{
public:
  EmissorNode(ros::NodeHandle *nh);
  virtual ~EmissorNode();

private:
  void timerCallback(const ros::TimerEvent& event);
  ros::Timer timer_;
};

}

#endif // _EMISSOR_NODE_H_
