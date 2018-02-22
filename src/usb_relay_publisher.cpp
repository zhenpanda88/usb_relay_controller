#include <ros/ros.h>
#include <stdlib.h>
#include <std_msgs/Int16.h>
#include <std_msgs/String.h>
//#include <libusb-1.0/libusb.h>
//#include <usb_relay_device.h>
//#include <usb_relay_lib.h>


int main(int argc, char **argv)
{
	ros::init(argc, argv, "usb_relay_publisher");
	ros::NodeHandle n;

	ros::Publisher relay_on_off = n.advertise<std_msgs::Int16>("On_Off_State", 1);
	ros::Publisher relay_device_id = n.advertise<std_msgs::String>("Relay_ID", 1);

	std_msgs::Int16 OnOff;
	int state;
	std_msgs::String id;

	std::cout << "Enter relay id (1, 2 or ALL): ";
	std::cin >> id.data;

	std::cout << "Enter Relay State (1 is on, 0 is off): ";
	std::cin >> state;

	OnOff.data = state;	

	while(ros::ok())
	{
		relay_on_off.publish(OnOff);
		relay_device_id.publish(id);

		ros::Duration(1).sleep();
	}

}