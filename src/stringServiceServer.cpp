/**
*MIT License
*
*Copyright (c) 2019 Saumil Shah
*
*Permission is hereby granted, free of charge, to any person obtaining a copy
*of this software and associated documentation files (the "Software"), to deal
*in the Software without restriction, including without limitation the rights
*to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*copies of the Software, and to permit persons to whom the Software is
*furnished to do so, subject to the following conditions:
*
*The above copyright notice and this permission notice shall be included in all
*copies or substantial portions of the Software.
*
*THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*SOFTWARE.
*/

/*
 * @file  stringServiceServer.cpp
 * @author Saumil Shah
 * @date  28th Oct 2019
 *
 */
#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "first_pkg/stringService.h"

/**
 * Callback function for the service server
 */
bool changeOutput(first_pkg::stringService::request &req,
                  first_pkg::stringService::response &resp);

int main(int argc, char **argv) {
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "string_service");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle s;
  ros::ServiceServer service = s.advertiseService("change_string_output",
                                                  &changeOutput);
  ros::spin();
  return 0;
}

bool changeOutput(first_pkg::stringService::request &req,
                  first_pkg::stringService::response &resp) {
  /**
   * Based on the bool value passed by the client, an output string is selected
   */
  if (req.choice) {
    resp.name = "Saumil";
  } else {
    resp.name = "Shah";
  }
  return true;
}