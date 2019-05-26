#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <std_msgs/Float64.h>
#include "geometry_msgs/Twist.h"

class ps_1
{
	public:
		ps_1()
			{
				//Inform the ROS master that we will be publishing on the cmd/vel topic to drive the motor 				
				motor_command_publish = n1.advertise<geometry_msgs::Twist>("/cmd_vel",10);

				//Create service
				service = n1.advertiseService("/ball_chaser/command_robot", &ps_1::command_robot_service,this);
			}

			
		bool command_robot_service(ball_chaser::DriveToTarget::Request& req, ball_chaser::DriveToTarget::Response& res)
			{

						ROS_INFO("Robot is moving");
						//Define a object of geometry_msgs::Twist
						geometry_msgs::Twist motor;

						//Assign the requested velocities
						motor.linear.x = req.linear_x;
						motor.angular.z = req.angular_z;

						//Publish the velocities to drive the robot
						motor_command_publish.publish(motor);

						//Return a reponse msg
						res.msg_feedback = "Robot's linear velocity in x: "+std::to_string(req.linear_x)+" angular velocity in z: "+std::to_string(req.angular_z);
						ROS_INFO_STREAM(res.msg_feedback);

						return true;			
			}

	private:
		ros::NodeHandle n1;
		ros::Publisher motor_command_publish;
		ros::ServiceServer service;
};
		

int main(int argc, char** argv)
{
	//Initiate node
	ros::init(argc, argv, "drive_bot");
	
	//Create object of ps_1 class
	ps_1 mr;

	ROS_INFO("Chase the ball!");

	ros::spin();
	
	return 0;
}

				

















