
#include <cstdint>
#include <memory>

#include <ros/ros.h>
#include <std_msgs/Float32.h>
#include <rosgraph_msgs/Clock.h>
#include <nav_msgs/Path.h>
#include <visualization_msgs/Marker.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Point32.h>
#include <geometry_msgs/Polygon.h>
#include <std_msgs/String.h>
#include "third_party/subprocess/subprocess.hpp"


class Basavaraj {
 public:
  explicit Basavaraj();


  int32_t Initialize() ;

  int32_t setup();

  int32_t PublisherSetup();

  int32_t SubscriberSetup();

  int32_t stackkill();

  int32_t CallSuscribers();

  int32_t CallPublisher();

  int32_t KillPublisher();

  int32_t SetRate();

  int32_t ProcessTeardown();

 private:

  bool debug_ = false;


  // verison string.
  const std::string kStackVersion_ = "v1";

  // roscore process.
  std::unique_ptr<subprocess::Popen> roscore_process_;

  // ROS node.
  std::unique_ptr<ros::NodeHandle> node_;

  // ROS spinner.
  std::unique_ptr<ros::AsyncSpinner> spinner_;




  // Stack input
  std_msgs::Float32::ConstPtr throttle_percent_feedback_;
  std_msgs::Float32::ConstPtr brakes_percent_feedback_;
  std_msgs::Float32::ConstPtr steering_angle_feedback_;

  // Clock
  rosgraph_msgs::Clock::ConstPtr clock_;

  //Stack version
  std_msgs::String stack_version_;
 //Ros time
  ros::Time stamp_;

  //std_msgs::String stack_version_;

  //Ego speed
  std_msgs::Float32::ConstPtr ego_speed_;

  //Ego Pose
  geometry_msgs::Pose::ConstPtr ego_pose_;


  /*******************************************************************
   ************************* Subscribers *****************************
   *******************************************************************
   * ROS subscribers and callback functions to handle converting data
   * published from the fluxauto stack to Simian 
   */
  // Actuation
  ros::Subscriber test_topic_subscriber_;
  const std::string kTestTopicSubscriber = "/test/topic";
  void TestTopicSubscriberCallback(const std_msgs::Float32::ConstPtr& msg);



  /*******************************************************************
   ************************* Publishers ******************************
   *******************************************************************
   * ROS publishers to handle sending data recieved from Simian to the
   * fluxauto stack
   */
  // Clock
  const std::string kClockTopic = "/clock";
  ros::Publisher sim_clock_publisher_;

  // Sensor Data
  const std::string kThrottlePercentFeedbackTopic = "/sensors/ego/throttle";
  ros::Publisher throttle_percent_feedback_publisher_;


  //Stack verison
  const std::string kStackVersionTopic = "/stack/version";
  ros::Publisher stack_version_publisher_;

  //Ego speed
  const std::string kEgoSpeedTopic = "/ego/speed";
  ros::Publisher ego_speed_publisher_;

  //Ego pose
  const std::string kEgoPoseTopic = "/ego/pose";
  ros::Publisher ego_pose_publisher_;


  
};

