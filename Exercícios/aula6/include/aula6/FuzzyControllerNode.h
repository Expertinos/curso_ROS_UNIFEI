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

#include <math.h>
#include <fl/Headers.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/PointCloud.h>
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
  fl::Engine* engine_;
  fl::InputVariable* ambient_;
  fl::OutputVariable* power_;
  fl::RuleBlock* rule_block_;
  int counter_;

  ros::Publisher vel_pub_;
  ros::Subscriber sonar_sub_;
  std::vector<double> ultrassonics_;
  void publishVelocity(double vel_x,
                       double vel_theta);
  void sonarCb(const
               sensor_msgs::PointCloud::ConstPtr& msg);

};

}

#endif // _FUZZY_CONTROLLER_NODE_H_
