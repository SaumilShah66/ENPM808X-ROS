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
#include <iostream>
#include <gtest/gtest.h>
#include "ros/ros.h"
#include "std_msgs/String.h"

/*
 * Declaring test fixture CheckTest that will subscribe to topic
 * "chatter" published by node under testing
 */
class CheckTest {
 public:
  ros::NodeHandle nh;
  std::string a;
  CheckTest();
  ~CheckTest();
  void SetUp() {
  	std::cout << "Came in setup\n";

    auto sub = nh.subscribe("chatter", 100, &CheckTest::testChatterCallback, this);
    int i = 1;
    ros::Rate rate(5);
    while (i < 10) {
      ros::spinOnce();
      ++i;
      rate.sleep();
    }
    std::cout << "Leaving setup\n";
  }
  void testChatterCallback(const std_msgs::String::ConstPtr &msg);
};

CheckTest::CheckTest(){
}
CheckTest::~CheckTest(){
}

void CheckTest::testChatterCallback(const std_msgs::String::ConstPtr &msg) {
  std::cout << "Came\n" ;
  a = msg->data;
  return;
}

TEST(CheckTest_, testTalker) {
	CheckTest tester;
	tester.SetUp();
	std::cout << "Instance\n";
  // std::cout << tester.a ;
  EXPECT_GT(tester.a.size(), 0);
}


int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	ros::init(argc, argv, "talkerTest");
	return RUN_ALL_TESTS();
}