#include <ros/ros.h>
#include <nodelet/nodelet.h>
#include "std_msgs/String.h"

#include <pluginlib/class_list_macros.h>


namespace nodelet_test {

class NodeletSub : public nodelet::Nodelet
{
    public:
    NodeletSub(){};
    ~NodeletSub(){}
    virtual void onInit();
    void chatterCallback(const std_msgs::StringPtr& msg);
};

void NodeletSub::chatterCallback(const std_msgs::StringPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

void NodeletSub::onInit()
{   
    NODELET_DEBUG("Initializing nodelet...");
    ros::NodeHandle n = getNodeHandle();
    ros::Subscriber sub = n.subscribe("chatter", 1000, &NodeletSub::chatterCallback, this);
}
}//namespace nodelet_test

// Register the nodelet

PLUGINLIB_EXPORT_CLASS(nodelet_test::NodeletSub, nodelet::Nodelet)
