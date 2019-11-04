[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
---

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
cd beginner_tutorials
catkin_make

```

After package is successfully built you can try running it. To run this package you need three terminals.

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
roslaunch first_pkg first.launch publish_frequency:=10 publish_name:="Saumil"
```
