#include <ros/ros.h>
#include <stdlib.h>
#include <std_msgs/Bool.>
#include <libusb-1.0/libusb.h>
#include <usb_relay_device.h>
#include <usb_relay_lib.h>


int main(int argc, char **argv)
{
	ros::init(argc, argv, "usb_relay_publisher");
	ros::NodeHandle n;

	ros::Publisher relay_on_off = n.advertise<std_msgs::Bool>("On_Off_State", 1);


	bool OnOff;
	string relay_device_id;

	std::cout << "Enter relay id (1, 2 or ALL): ";
	std::cin >> relay_device_id;

	std::cout << "Enter Relay State (1 is on, 0 is off): ";
	std::cin >> OnOff;

	while(ros::ok())
	{

		ros::Duration(1).sleep();
	}

}