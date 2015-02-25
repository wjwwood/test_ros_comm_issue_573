#include <ros/ros.h>
#include <std_srvs/Empty.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "service_client");
  ros::NodeHandle nh;
  ros::ServiceClient client = nh.serviceClient<std_srvs::Empty>(
    "/empty_service",
    false  // Not persistent.
  );
  ros::Rate loop_rate(20);

  while (ros::ok())
  {
    ROS_INFO("Calling Empty service.");
    std_srvs::Empty emptyMsg;
    client.call(emptyMsg);
    loop_rate.sleep();
  }
  return 0;
}
