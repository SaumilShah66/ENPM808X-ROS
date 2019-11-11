[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
---

# ENPM808X-ROS
Ros publisher subscriber tutorial

# Dependencies

* Ubuntu 16.04
* ROS kinetic

You can install ROS kinetic by following steps from [this](http://wiki.ros.org/kinetic/Installation/Ubuntu) page.

# Clone and build package
You need to clone this package in your catkin_ws and then you can build this using catkin. In case you don't have catkin_ws follow this commands to create one.
```
mkdir catkin_ws && cd catkin_ws
mkdir src && cd_src
```
Once you are in src directory, you can clone this repository there.

```
git clone https://github.com/SaumilShah66/beginner_tutorials
cd ..
catkin_make

```

# Run test
```
cd catkin_ws/
catkin_make run_tests
```
# How to run nodes

After package is successfully built you can try running it. To run this package you need three terminals. Package has one publisher and one subscriber node.

### In terminal 1
```
roscore
```
### In terminal 2
Make sure you are in beginner_tutorials directory
```
cd beginner_tutorials 
source ./devel/setup.bash
rosrun first_pkg listener
```

### In terminal 3
Make sure you are in beginner_tutorials directory
```
cd beginner_tutorials 
source ./devel/setup.bash
rosrun first_pkg talker
```

### Run with roslaunch
Instead of opening different terminals you can run both nodes with one launch file.

```
roslaunch first_pkg first.launch
``` 

### Run with commandline arguments
```
roslaunch first_pkg first.launch publish_frequency:=10 publish_name:="Saumil" data_recorder:=0
```

# Record published data

You can record the data being published using rosbag. You can use following command to record it. Please make sure that nodes are running and publishing the data which you want to record.
```
rosbag record --duration=15 -a
```
This command will record all the data being published for 15 seconds only. You can also specify while launching first.launch file, whether you want to record or not.
```
roslauch first_pkg first.launch data_record:=1
```
When you set data_record:=1 it will record all the published data, until you kill the node. This data will be saved as record.bag file under results folder. You can use data_record:=0 if you don't want to record and just want to run nodes.

### Information about saved bag file

You can use "rosbag info" command to check details about that bag file. One bage file is provided in this repository and you can use following command to get it details.
```
cd catkin_ws
rosbag info results/2019-11-11-13-12-43.bag
```
It will give you following results
```
path:        results/2019-11-11-13-12-43.bag
version:     2.0
duration:    14.9s
start:       Nov 11 2019 13:12:43.05 (1573495963.05)
end:         Nov 11 2019 13:12:57.98 (1573495977.98)
size:        192.4 KB
messages:    893
compression: none [1/1 chunks]
types:       rosgraph_msgs/Log  [acffd30cd6b6de30f120938c17c593fb]
             std_msgs/String    [992ce8a1687cec8c8bd883ec73ca41d1]
             tf2_msgs/TFMessage [94810edda583a504dfda3829e70d7eec]
topics:      /chatter      148 msgs    : std_msgs/String   
             /rosout       301 msgs    : rosgraph_msgs/Log  (3 connections)
             /rosout_agg   296 msgs    : rosgraph_msgs/Log 
             /tf           148 msgs    : tf2_msgs/TFMessage
```
