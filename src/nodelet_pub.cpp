#include <ros/ros.h>
#include <nodelet/nodelet.h>
#include "std_msgs/String.h"
#include <sstream>

namespace nodelet_pub {
int count = 0;

class NodeletPub : public nodelet::Nodelet
{
    public:
    ros::Publisher chatter_pub;
    void timerCallback(const ros::TimerEvent&);
    virtual void onInit();
};

void NodeletPub::timerCallback(const ros::TimerEvent&)
{
    std_msgs::String msg;
    std::stringstream ss;
    ss << "hello world" << count;
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());    
    chatter_pub.publish(msg);
    ++count;
}

void NodeletPub::onInit()
{   
    ros::NodeHandle n = getNodeHandle();
    chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
    ros::Timer timer = n.createTimer(ros::Duration(0.1), &NodeletPub::timerCallback, this);
}


}//namespace nodelet_pub

// Register the nodelet
#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(nodelet_pub::NodeletPub, nodelet::Nodelet)
