#include <stdlib.h>
#include "aula4/EmissorNode.h"

int main(int argc, char **argv)
{
  // Set up ROS.
  ros::init(argc, argv, "emissor");
  aula4::EmissorNode node(new ros::NodeHandle());
  node.spin();
  return EXIT_SUCCESS;
}

