# Pepsi-Bot

This ROS 2 project aims to define the behavior of a robot that searches for a Pepsi can, approaches and grabs it, then it searches for the target location indicated by a QR code, approaches it, and releases the can into the hole which is placed after a black line. The ROS 2 packages are meant to run a hardware robot which has four omni wheels, an ultrasonic sensor, a camera, an infrared sensor chip (to detect the black line), and a gripper hand (controlled using a servo motor).

![WhatsApp Image 2024-09-05 at 09 55 11_c38212a7](https://github.com/user-attachments/assets/f4f7e799-3764-4988-981d-dd2207cfb170)

However, this robot cannot be simulated accurately with Gazebo because it lacks the simulated equivalent of some hardware components. So, the code used for simulation would differ slightly from the code prepared for the hardware robot. As such, the gripper hand cannot be simulated, but there would be a message conveying that the gripper has been closed or opened.

## Requirements

The robot is assumed to have the following topics:

•	/cmd_vel of type geometry_msgs/msg/Twist for navigation

•	/distance_to_obstacle of type std_msgs/msg/Float32 for measuring the front distance to the nearest obstacle

•	/robot_interfaces/compressed of type sensor_msgs/msg/CompressedImage for image capturing

In addition, the robot has a custom action which is used to control the gripper hand. This action is of custom type robot_hardware_interfaces/action/GripperAction, and it is defined as follows:

•	Request: empty request

•	Result:
>o	bool result: indicates whether the gripper is closed or open

•	Feedback:
>o	int32 feedback: indicates the time left for the gripper to automatically open

The action server is called /gripper_action, and the way it works is that a node can send a request to the server, which will immediately close the gripper. To pose a challenge, the server will automatically open the gripper after 30 seconds, so the robot is supposed to reach the target location before this duration runs out lest the can is released before reaching the target. During this time, the server sends feedback to its client which indicates the time left for the gripper to open. To intentionally open the gripper, the sent goal must be canceled by the action client.

Additional requirements include the use of behavior trees for controlling the behavior of the robot and containerizing the project using Docker, which are provided in the repository.

## Behavior Tree

The behavior tree of the robot is illustrated in the following chart:

![tree drawio](https://github.com/user-attachments/assets/e9530504-c5fc-411b-b9aa-11ff4f68ebd6)

The behavior of the robot starts by ensuring that the image detection models are ready before continuing. Then it starts searching for the Pepsi can by rotating to the right and trying to find the can in the image provided by the camera. When the robot finds the can, it starts approaching it and adjusting its direction depending on the can’s position in the captured image. After each iteration, the robot checks whether it has reached the proper distance for grabbing the can. If so, it grabs the can and continues to the second part of the tree. If not, it continues to detect the can’s position and adjust its direction until it reaches it. After grabbing the can, the robot starts searching for the QR code in the same manner as searching for the can. When it detects it, it starts approaching it as with the can, and it periodically checks whether it has reached the black line. When it does reach the black line, the robot will release the can from the gripper, and the program is complete.

## Additional Nodes

An action server is created to store captured images and serve object detection requests incoming from the behavior tree. The action server is called /find_object_server, and its action is of custom type detection_interfaces/srv/FindObject which has the following structure:
•	Request:
>o	string object_type: specifies the type of object to be detected (Pepsi can or QR code)

•	Result:
>o	bool found: indicates whether the requested object was found

>o	int32 frame_width: specifies the width of the captured image in pixels

>o	int32 cx: specifies the x coordinate of the centroid of the found object in the image

>o	int32 cy: specifies the y coordinate of the centroid of the found object in the image

•	Feedback: empty feedback

The action server node also subscribes to the /robot_interfaces/compressed topic to receive and store the captured images.
The server uses the YOLO V8 image detection model to detect Pepsi cans, and the Pyzbar Python library to detect QR codes.

---

A service server is created to handle opening and closing the gripper hand. It is called /control_gripper, and its service is of custom type gripper_interfaces/srv/GripperControl which has the following structure:

•	Request:
>o	string action: specifies whether the incoming request is to open or close the gripper

•	Response: empty response

When this server receives a request to close the gripper, it sends an action goal to the /gripper_action action server and awaits its feedback to ensure that the gripper has closed. When the server receives a request to open the gripper, it cancels its previous goal causing the gripper to open.

---

A service server is created to receive and store the distance measurements, and it handles incoming requests by sending a response that contains the latest distance data. The server is called /get_front_distance and its service is of custom type distance_interfaces/srv/GetFrontDistance which has the following structure:

•	Request: empty request

•	Response:
>o	float32 front_distance: indicates front distance to the nearest object

The server node also subscribes to the /distanceToObstacle topic to receive and store the distance measurements.

---

A ROS 2 node called DistanceConverter is created for testing purposes. As stated before, there are some differences between the simulated robot and the actual hardware, one of which is the type of distance measurement. Since the simulated robot has an omnidirectional lidar sensor, there needs to be a mapping between its values and single distance value that is supposed to be published from the ultrasonic sensor of the actual robot. As such, this node is created to subscribe to the /scan topic, calculate and estimate of the front distance as a single number, and publish the result to the /distanceToObstacle topic. This node allows switching between the simulated and actual environments without any effort.

---

Finally, the MainNode ROS 2 node is created to register the created behavior tree nodes, initialize the Blackboard, and tick the root of the tree.

## Project Launch

To build and launch the project, clone the repository and run the following command:
```
ros2 launch launch/launch.py
```

## Simulation Results

For the simulation, a box with a Pepsi can image is used to replace an actual can. As stated previously, the gripper and infrared sensors take much time to implement in Gazebo, so they are not simulated.

When the simulation starts, the robot starts searching for the Pepsi can while rotating right. When it detects the can, the robot starts moving towards it until reaching a threshold distance. It stops for some time to simulate grabbing the can. After that, it starts rotating right until it detects the QR code then approaches it. When it reaches the threshold distance, it stops to simulate releasing the can.

In addition to simulating the robot in Gazebo, RQT is used to check the camera footage of the robot.

The following screenshots show different stages of the simulation of the Pepsi-Bot from the moment it searches for the Pepsi can to the moment it reaches the target location and is supposed to release it into the hole.

![Screenshot from 2024-09-05 16-15-42](https://github.com/user-attachments/assets/34bbba6f-3fb2-424b-8ff6-a3ec2dc2cfd2)

![Screenshot from 2024-09-05 16-16-48](https://github.com/user-attachments/assets/ba020893-38ea-4098-a4af-e9aba8095c53)

![Screenshot from 2024-09-05 16-18-37](https://github.com/user-attachments/assets/36823777-d429-46b5-9e28-7e1bc1c6a231)

![Screenshot from 2024-09-05 16-19-00](https://github.com/user-attachments/assets/c61b8dd0-0e1b-4ede-9bdf-1e2af15127e7)

![Screenshot from 2024-09-05 16-19-22](https://github.com/user-attachments/assets/148e3cc4-1d68-4be4-808a-add66ed76609)

![Screenshot from 2024-09-05 16-19-59](https://github.com/user-attachments/assets/c8ceb6b8-bea8-45b2-a19c-7f066c2c2e9c)



