#include <ros/ros.h>
#include <std_srvs/Empty.h>

bool
service_callback(std_srvs::Empty::Request& req, std_srvs::Empty::Response& res)
{
  // Does nothing, returns true.
  ROS_INFO("Empty service callback.");
  return true;
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "service_server");
  ros::NodeHandle nh;

  // Create a service callback
  ros::ServiceServer serviceServer = nh.advertiseService(
    "empty_service",
    &service_callback
  );

  ros::spin();

  ROS_INFO("Service server shutting down.");

  return 0;
}