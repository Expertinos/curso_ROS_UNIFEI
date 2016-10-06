#include <stdlib.h>
#include "aula5/ReceptorNode.h"

int main(int argc, char **argv)
{
  // Set up ROS.
  ros::init(argc, argv, "receptor");
  aula5::ReceptorNode node(new ros::NodeHandle());
  node.spin();
  return EXIT_SUCCESS;
}

