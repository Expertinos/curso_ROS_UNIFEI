#include <stdlib.h>
#include "aula6/FuzzyControllerNode.h"

int main(int argc, char **argv)
{
  // Set up ROS.
  ros::init(argc, argv, "fuzzy_controller_node");
  aula6::FuzzyControllerNode node(new ros::NodeHandle());
  node.spin();
  return EXIT_SUCCESS;
}

