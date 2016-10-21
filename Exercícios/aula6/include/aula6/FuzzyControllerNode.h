/**
 *  This header file defines the FuzzyControllerNode class, which is also a
 *  Node class via enhancement.
 *
 *  Version: 1.0.0
 *  Created on: 21/10/2016
 *  Modified on: 21/10/2016
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Professores de ECA419 (eca419.unifei@gmail.com)
 */

#ifndef _FUZZY_CONTROLLER_NODE_H_
#define _FUZZY_CONTROLLER_NODE_H_

#include "Node.h"

#define PI 3.14159

namespace aula6
{

class FuzzyControllerNode : public Node
{
public:
  FuzzyControllerNode(ros::NodeHandle *nh);
  virtual ~FuzzyControllerNode();

private:
  virtual void controlLoop();

};

}

#endif // _FUZZY_CONTROLLER_NODE_H_
