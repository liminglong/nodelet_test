#include <ros/ros.h>
#include <nodelet/nodelet.h>
#include "std_msgs/String.h"
#include <sstream>
#include <iostream>

#include <pluginlib/class_list_macros.h>

namespace nodelet_test {
//int count = 0;

class NodeletPub : public nodelet::Nodelet
{
    public:
    NodeletPub();
    ~NodeletPub();
    ros::Publisher chatter_pub;
    ros::Timer timer;
    ros::NodeHandle n;
    //void timerCallback(const ros::TimerEvent&);
    virtual void onInit();
};
NodeletPub::NodeletPub()
{
    std::cout << "Constructor works."  << std::endl;
}
NodeletPub::~NodeletPub()
{
    std::cout << "Deconstructor works." << std::endl;
}
/*
void NodeletPub::timerCallback(const ros::TimerEvent&)
{
    //std::cout << "hello in timerCallback" << std::endl;
    std_msgs::String msg;
    NodeletPub::chatter_pub = NodeletPub::n.advertise<std_msgs::String>("chatter", 1000);
    msg.data = "hello world";
    chatter_pub.publish(msg); 
}*/

void NodeletPub::onInit()
{   
    std::cout << "Initializing nodelet 1..." << std::endl;
    NODELET_DEBUG("Initializing nodelet 2...");
    NodeletPub::n = getNodeHandle();
    
    chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
    
    ros::Rate loop_rate(1);
    while (ros::ok())
    {
        //std::cout << "loop in while()" << std::endl;
        std_msgs::String msg;
        msg.data = "hello world";
        chatter_pub.publish(msg);

        loop_rate.sleep();
        ros::spinOnce();
    }
    
    std::cout << "Initializing nodelet 3..." << std::endl;
    //NodeletPub::timer = n.createTimer(ros::Duration(0.1), &NodeletPub::timerCallback, this);
    std::cout << "Initializing nodelet 4..." << std::endl;
}


}//namespace nodelet_test

// Register the nodelet
PLUGINLIB_EXPORT_CLASS(nodelet_test::NodeletPub, nodelet::Nodelet)
