# Udacity_2_Chase_Ball

### Aim

- Learn basic features of ROS
- Learn to create **nodes** and subscribe/publish to topics
- Learn to create **services** and **topics** and understand their difference
- Learn to create **custom messages** 
- Learn to write code in **C++**
- Learn to create **catkin** workspaces
- Learn to build catkin packages and understand catkin_make
- Learn to parse images in ROS
- Learn to integrate ROS and Gazebo
- Learn to integrate and use **sensors** 
- Learn to create and use **Gazebo plugins**

### Description

- Build a small robot to navigate in a world and a white ball for the robot to chase
- Process the image and identify the position of the white ball in the image
- Drive the robot towards the white ball
- Ensure that the robot should stop when it does not see the white ball

### Installation

- For [Linux users](http://wiki.ros.org/kinetic/Installation). Here, I am using the most common installation of ROS, i.e., *Kinetic Kame*. It work well on Ubuntu 16.0.4.
- For windows user, install a [VM](https://www.virtualbox.org/) (virtual machine) with linux and then follow the previous step
- For Mac users, ROS is not yet supported by some OS. So, I would suggest you to install VM as the windows user
- Install [Rviz](http://wiki.ros.org/rviz)

### Launch

- Open two command terminal window
- Navigate to the catkin workspace named something like this `catkin_ws`
- Execute `roslaunch my_robot world.launch`
- This opens the Rviz and gazebo world with the robot housed in the world
- Setup the Rviz
  1. Select `odom` for **fixed frame**
  2. Click the **Add** button
  3. add `RobotModel` - Robot model should load up in Rviz
  4. add `Camera` and select the **Image topci** that was defined in the camera Gazebo plugin
  5. add `LaserScan` and select the **topic** that was defined in the Hokuyo Gazebo plugin
- Execute `roslaunch ball_chaser ball_chaser.launch`
- Move the white ball such that it is visible to the robot and enjoy the action!

### License

Udacity_2_Chase_Ball is Copyright © 2008-2019 Jatin Mayekar. It is free software, and may be redistributed under the terms specified in the LICENSE file.
