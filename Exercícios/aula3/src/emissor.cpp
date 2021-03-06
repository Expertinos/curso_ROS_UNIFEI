#include <ros/ros.h>

int main(int argc, char **argv)
{
  // Set up ROS.
  ros::init(argc, argv, "emissor");
  ros::NodeHandle nh;

  ros::Rate loop_rate(1);

  ROS_INFO("Eu sou o emissor!!!");
  int counter(0);
  while (nh.ok())
  {
    if (counter++ == 5)
    {
	 ROS_WARN("Desligando o emissor!!!");
      nh.shutdown();
    }
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}

