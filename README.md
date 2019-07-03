# Udacity_2_AMCL_Where_Am_I

### Launch

- Open three terminal windows
- Run `roslaunch my_robot world.launch` in the first terminal window to open the Gazebo world with robot and RViz
- Open the *amcl_rviz.rviz* file in Rviz. It is saved in the *my_robot/rviz/* directory
- Run `roslaunch my_robot amcl.launch` in the second terminal window
- Select *map* in the Rviz Global Options as the */map* topic is now available
- See the position of the robot in Gazebo and accordingly select the *2D Pose Estimate* in Rviz(Click on the button then click on the position in map in Rviz and hold to select the direction
- Then, select the *2D Navigation Goal* button and select any place in the map and wait for the robot to reach its goal!
- Added a video file in *my_robot/video_pics/* showing the localisation of the robot in the world with various goals


