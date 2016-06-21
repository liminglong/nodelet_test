#include <ros/ros.h>
#include <nodelet/nodelet.h>
#include "std_msgs/String.h"
#include <iostream>

#include <pluginlib/class_list_macros.h>


namespace nodelet_test {
int count = 0;

class NodeletSub : public nodelet::Nodelet
{
    public:
    NodeletSub();
    ~NodeletSub();
    ros::Subscriber sub;
    virtual void onInit();
    void chatterCallback(const std_msgs::StringPtr & msg);
};
NodeletSub::NodeletSub(){std::cout << "sub constructore works" << std::endl;}
NodeletSub::~NodeletSub(){}

void NodeletSub::chatterCallback(const std_msgs::StringPtr & msg)
{
  std::cout << "chatter Callback start!" << std::endl;
  std::cout << count << std::endl;
  std::cout << "the use count of the subscribed msg is: " << msg.use_count() << std::endl;
  std::cout << "the address of the subscribed msg is: " << &(msg) << std::endl;
  std::cout << msg->data << std::endl;
  ++count;
}

void NodeletSub::onInit()
{   
    std::cout << "hello" << std::endl;
    ros::NodeHandle n = getNodeHandle();
    NodeletSub::sub = n.subscribe("chatter", 1000, &NodeletSub::chatterCallback, this);
    std::cout << "hello2" << std::endl;
}
}//namespace nodelet_test

// Register the nodelet

PLUGINLIB_EXPORT_CLASS(nodelet_test::NodeletSub, nodelet::Nodelet)
