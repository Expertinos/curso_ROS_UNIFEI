#include <stdlib.h>
#include "aula5/EmissorNode.h"

int main(int argc, char **argv)
{
  // Set up ROS.
  ros::init(argc, argv, "emissor");
  aula5::EmissorNode node(new ros::NodeHandle());
  node.spin();
  return EXIT_SUCCESS;
}

