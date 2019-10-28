# ENPM808X-ROS
Ros publisher subscriber tutorial

# Dependencies

* Ubuntu 16.04
* ROS kinetic

You can install ROS kinetic by following steps from [this](http://wiki.ros.org/kinetic/Installation/Ubuntu) page.

# Clone and build package

You need to run following commands to clone this repository and build the package present in this repository.

```
git clone https://github.com/SaumilShah66/beginner_tutorials
cd ENPM808x-ROS
catkin_make

```

After package is successfully built you can try running it. To run this package you need three terminals.

### In terminal 1
```
roscore
```
### In terminal 2
Make sure you are in ENPM808X-ROS directory
```
cd ENPM808X-ROS 
source ./devel/setup.bash
rosrun first_pkg listener
```

### In terminal 3
Make sure you are in ENPM808X-ROS directory
```
cd ENPM808X-ROS 
source ./devel/setup.bash
rosrun first_pkg talker
```
