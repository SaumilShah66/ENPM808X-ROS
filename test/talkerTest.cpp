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
 * @file  talkerTest.cpp
 * @author Saumil Shah
 * @date  11th Nov 2019
 *
 */

#include <string>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <gtest/gtest.h>


/*
 * Declaring test fixture NodeTest to subscribe to topic
 * "chatter" and test is it publishing or not
 */
class NodeTest : public ::testing::Test {
 protected:
  ros::NodeHandle nh;
  std::string testString;
  NodeTest() {
    auto sub = nh.subscribe("chatter", 100, &NodeTest::testCallback, this);
    int i = 0;
    ros::Rate rate(10);
    /// Will read 30 messages
    while (i < 30) {
      ros::spinOnce();
      ++i;
      rate.sleep();
    }
  }
  void testCallback(const std_msgs::String::ConstPtr &msg);
};

void NodeTest::testCallback(const std_msgs::String::ConstPtr &msg) {
  testString = msg->data;
  return;
}

TEST_F(NodeTest, testTalker) {
  /// Should have read more than zero characters
  EXPECT_GT(testString.size(), 0);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "talkerTest");
  return RUN_ALL_TESTS();
}
