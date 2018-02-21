#include <ros/ros.h>
#include <stdlib.h>
#include <std_msgs/Bool.>
#include <libusb-1.0/libusb.h>
#include <usb_relay_device.h>
#include <usb_relay_lib.h>

std_msgs::Bool state;

void myCallback(const std_msgs::Bool& On_Off_State){

	ROS_INFO("Received RELAY State of (1 is on, 0 is off): ", On_Off_State.data);
	state.data = On_Off_State.data;

}

int main(int argc, char **argv) {
    ros::init(argc, argv, "usb_relay_controller"); //name this node 
    // when this compiled code is run, ROS will recognize it as a node called "minimal_simulator" 
    ros::NodeHandle n; // node handle 
    //create a Subscriber object and have it subscribe to the topic "force_cmd" 
    ros::Subscriber my_subscriber_object = n.subscribe("On_Off_State", 1, myCallback);
    //simulate accelerations and publish the resulting velocity; 
    
    while (ros::ok()) {
        ROS_INFO("velocity = %f", g_velocity.data);
        
        ros::spinOnce(); //allow data update from callback 
        
        naptime.sleep(); // wait for remainder of specified period; this loop rate is faster than 
        
    }
    return 0; // should never get here, unless roscore dies 
} 