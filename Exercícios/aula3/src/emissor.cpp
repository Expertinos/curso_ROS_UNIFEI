#include <ros/ros.h>

int main(int argc, char **argv)
{
  // Set up ROS.
  ros::init(argc, argv, "emissor");
  ros::NodeHandle nh;

  ros::Rate loop_rate(1);

  ROS_WARN("Hello world!");
  int counter(0);
  while (nh.ok())
  {
    if (counter++ == 5)
    {
      nh.shutdown();
    }
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}

