#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <std_msgs/Float64.h>
#include "geometry_msgs/Twist.h"
#include <sensor_msgs/Image.h>

class ps_2
{
	public:
		ps_2()
			{
				// Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    		sub1 = n2.subscribe("/camera/rgb/image_raw", 10, &ps_2::process_image_callback,this);

				//Define client
			  client1 = n2.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");
			}
			
		void process_image_callback(const sensor_msgs::Image img)
			{
						
						int white_pixel = 255;
						int l=img.step;
						int r = 0;
						int n1 = 0, n2 = 0, n3 =0;// count the no of white pixels in three sections and compare them later
						
						ROS_INFO("Detecting the position of the white ball");
						//ps_2::drive_robot(0.5,0.5);
					

						// Loop through each pixel in the image and check if its equal to the first one
    				for (int i = 0; i < img.height * img.step; i++) 
							{
        				if ((img.data[i] == white_pixel) && (img.data[i+1] == white_pixel) && (img.data[i+2] == white_pixel))	// each element has three
// values - corresponding to RGB - aligned here columnwise - therefore check all the three RGB channels. White = 255;255;255 
									{
										r = i % l; //remainder - passing through the undesired rows and then checking where the white pixel lies								
																				
										if(r < (l/3))//on left  
											{ 
												n1 = n1 +1;
    				 					}
										else if(r > (2*l/3))//on right  
											{     				
												n2 = n2 +1;
            					}
										else if(r >= (l/3) && r<= (2*l/3))//in center 
											{     				
												n3 = n3 +1;
            					}
									}
							}
						// Debug
						ROS_INFO_STREAM("1_" << n1);
						ROS_INFO_STREAM("2_" << n2);
						ROS_INFO_STREAM("3_" << n3);
					
						// stop when you don't see white ball
						if (n1 < 500 && n2 < 500 && n3 < 500)
						{
							ps_2::drive_robot(0.0,0.0);	
							ROS_INFO("Stop! No white ball");
						}	else{			
						if(n1 > n2 > n3) // on left 
						{
							ps_2::drive_robot(0.2,0.2);
							ROS_INFO("Left");
						}
						else if(n1 < n2 < n3) // on right 
						{
							ps_2::drive_robot(0.2,0.2);
							ROS_INFO("Right");
						}
						else if(n1 < n2 > n3) // in center
						{
							ps_2::drive_robot(0.2,0.2);
							ROS_INFO("Center");
						}}
						//return true;			
			}

		void drive_robot(float lin_x, float ang_z)
			{
				ROS_INFO("Moving towards the white ball");

				// Create an object of service				
				ball_chaser::DriveToTarget srv1;

				// Assign the requested velocities to the robot				
				srv1.request.linear_x = lin_x;
				srv1.request.angular_z = ang_z;

				// Call the ball_chaser drive_robot service and pass the requested velocities
    		if (!client1.call(srv1))
					{	
        	ROS_ERROR("Failed to call service drive_robot");
					}
				
				// Give time for robto to move and complete the on-going action
				ros::Duration(3).sleep();

			}


	private:
		ros::NodeHandle n2;
		ros::Subscriber sub1;
		ros::ServiceClient client1;
};
		

int main(int argc, char** argv)
{
	//Initiate node
	ros::init(argc, argv, "process_image");
	
//	while(ros::ok()){	
	//Create object of ps_1 class
	ps_2 mr1;

	ROS_INFO("Chase the ball!");

	//ros::Duration(3).sleep();
	//}
	ros::spin();
	
	return 0;
}
