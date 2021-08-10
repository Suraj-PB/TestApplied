#include "stack.h"
#define SUCCESS_RETURN_CODE 0
#define ERROR_RETURN_CODE -1
#define ROS_HISTORY_DEPTH 10

//implement the default constructor
Basavaraj::Basavaraj(){}

int32_t Basavaraj::Initialize(){
  printf("Initialize()\n");
  fflush(stdout);

  // Start roscore in our container (must be done before ros::init())
  roscore_process_.reset(new subprocess::Popen("roscore"));

  // Initialize ROS
  int argc = 0;
  char **argv = NULL;
  ros::init(argc, argv, "stack", ros::init_options::NoSigintHandler);
  node_.reset(new ros::NodeHandle());
  spinner_.reset(new ros::AsyncSpinner(4));
  spinner_->start();
  return SUCCESS_RETURN_CODE;
}


//this function can be used to init variables.
int32_t setup(){
  std:: cout << "setup()" << std::endl;
	return SUCCESS_RETURN_CODE;
}

int32_t Basavaraj::PublisherSetup(){
	    stack_version_publisher_ = node_->advertise<std_msgs::String>(
        kStackVersionTopic, ROS_HISTORY_DEPTH);
	return SUCCESS_RETURN_CODE;
}

int32_t Basavaraj::SubscriberSetup(){
	
	return SUCCESS_RETURN_CODE;
}




void Basavaraj::TestTopicSubscriberCallback(const std_msgs::Float32::ConstPtr& msg) {
  std::cout << "TestTopicSubscriberCallback --> " << msg->data   << std::endl;
  
  return;
}

int32_t Basavaraj::CallSuscribers(){
    test_topic_subscriber_ = node_->subscribe(
    kTestTopicSubscriber, ROS_HISTORY_DEPTH, &Basavaraj::TestTopicSubscriberCallback, this);
	return SUCCESS_RETURN_CODE;
}

int32_t Basavaraj::CallPublisher(){
  std::cout << "CallPublisher called()\n" <<std::endl;
  stack_version_.data = "asd";
	stack_version_publisher_.publish(stack_version_);
	return SUCCESS_RETURN_CODE;
}

int32_t Basavaraj::KillPublisher(){
  std::cout << "killPublisher called()\n" <<std::endl;
  stack_version_publisher_.shutdown();
  test_topic_subscriber_.shutdown();
	return SUCCESS_RETURN_CODE;
}

// TOD : use this function to set rate(loop rate)
int32_t SetRate(){
	return SUCCESS_RETURN_CODE;
}


// kill roscore, rosnode
int32_t Basavaraj::ProcessTeardown() {
  printf("Process killed..()\n");
  fflush(stdout);

  spinner_->stop();
  ros::shutdown();

  // kill roscore using SIGINT (Ctrl-C)
  roscore_process_->kill(2);

  return SUCCESS_RETURN_CODE;
}

//implementation






