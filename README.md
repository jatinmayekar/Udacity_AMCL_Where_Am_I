# Udacity_2_AMCL_Where_Am_I

![Output](https://github.com/gonfreces/Udacity_AMCL_Where_Am_I/blob/master/my_robot/video_pics/ezgif.com-gif-maker.gif)

### Launch

- Open three terminal windows
- Run `roslaunch my_robot world.launch` in the first terminal window to open the Gazebo world with robot and RViz
- Open the *amcl_rviz.rviz* file in Rviz. It is saved in the *my_robot/rviz/* directory
- Run `roslaunch my_robot amcl.launch` in the second terminal window
- Select *map* in the Rviz Global Options as the */map* topic is now available
- See the position of the robot in Gazebo and accordingly select the *2D Pose Estimate* in Rviz(Click on the button then click on the position in map in Rviz and hold to select the direction
- Then, select the *2D Navigation Goal* button and select any place in the map and wait for the robot to reach its goal!
- Added a video file and a screenshot in *my_robot/video_pics/* showing the localisation of the robot in the world with various goals
- In the third terminal, you can then use *teleop* by ruuning `rosrun teleop_twist_keyboard teleop_twist_keyboard.py`
- Control the robot and enjoy the action! You can see this step at the from 9:28 in my video



