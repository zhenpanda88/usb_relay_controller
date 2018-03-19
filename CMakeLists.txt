cmake_minimum_required(VERSION 2.8.3)
project(usb_relay_controller)

find_package(catkin_simple REQUIRED roscpp std_msgs)


catkin_simple()

# example boost usage
# find_package(Boost REQUIRED COMPONENTS system thread)

# C++0x support - not quite the same as final C++11!
# use carefully;  can interfere with point-cloud library
# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

# Libraries: uncomment the following and edit arguments to create a new library
# cs_add_library(my_lib src/my_lib.cpp)   

# Executables: uncomment the following and edit arguments to compile new nodes
# may add more of these lines for more nodes from the same package
# cs_add_executable(example src/example.cpp)
cs_add_executable(usb_relay_controller src/usb_relay_controller.cpp)
cs_add_executable(usb_relay_publisher src/usb_relay_publisher.cpp)

#the following is required, if desire to link a node in this package with a library created in this same package
# edit the arguments to reference the named node and named library within this package
target_link_libraries(usb_relay_controller usb_relay_device)
target_link_libraries(usb_relay_controller usb_relay_lib)

cs_install()
cs_export()
    