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

#include <aula5_msgs/Robo.h>
#include "Node.h"
#include "aula5/distancias/DistanciaConverter.h"

#define PI 3.14159

namespace aula5
{

class ReceptorNode : public Node
{
public:
  ReceptorNode(ros::NodeHandle *nh);
  virtual ~ReceptorNode();

private:
  void infoCallback(const aula5_msgs::Robo::ConstPtr& info_msg);
  ros::Subscriber robo_info_sub_;

};

}

#endif // _RECEPTOR_NODE_H_
