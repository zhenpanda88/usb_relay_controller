#include <ros/ros.h>
#include <stdlib.h>
#include <std_msgs/Int16.h>
#include <std_msgs/String.h>
#include <libusb-1.0/libusb.h>
#include <usb_relay_controller/usb_relay_device.h>
#include <usb_relay_controller/usb_relay_lib.h>

std_msgs::Int16 state;
std_msgs::String relayId;

extern "C" {
  int usb_relay_init(void);
}

void onOffStateCallback(const std_msgs::Int16& On_Off_State){
	ROS_INFO("Received RELAY State of (1 is on, 0 is off): %i", On_Off_State.data);
	state.data = On_Off_State.data;
}

void relayDeviceIdCallback(const std_msgs::String::ConstPtr& id){
	ROS_INFO("Received Relay ID of (1, 2, or ALL): %s", id->data.c_str());
	relayId.data = id->data.c_str();
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "usb_relay_controller"); //name this node 
    // when this compiled code is run, ROS will recognize it as a node called "minimal_simulator" 
    ros::NodeHandle n; // node handle 

    //initializes usb relay device. If device can't connect, node shuts down.
    int working = usb_relay_init();
    if(working != 0){
    	ROS_ERROR("Device Not Found: Shutting Down...");
    	ros::shutdown();
    }

    ros::Subscriber onOff_sub = n.subscribe("USB_On_Off_State", 1, onOffStateCallback);
    ros::Subscriber relayID_sub = n.subscribe("USB_Relay_ID", 1, relayDeviceIdCallback);
    //simulate accelerations and publish the resulting velocity; 
    ros::Rate naptime(1.0);
    


    while (ros::ok()) {
        
        



        ros::spinOnce(); //allow data update from callback 
        
        naptime.sleep(); // wait for remainder of specified period; this loop rate is faster than 
        
    }
    return 0; // should never get here, unless roscore dies 
} 