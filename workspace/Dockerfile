# Step 1: Use a ROS 2 Galactic base image
FROM ros:galactic-ros-base

# Step 2: Set non-interactive frontend to avoid interactive prompts
ENV DEBIAN_FRONTEND=noninteractive

# Step 3: Install necessary tools, dependencies
RUN apt-get update && apt-get install -y \
    python3-pip \
    python3-colcon-common-extensions \
    ros-galactic-desktop \
    ros-galactic-behaviortree-cpp-v3 \
    && rm -rf /var/lib/apt/lists/*


# Step 4: Install Python dependencies that are not related to ROS 2
RUN pip install torch==2.4.0 
RUN pip install torchvision==0.19.0 ultralytics
RUN pip install numpy==1.21.0
RUN apt-get update && apt-get install -y libzbar0


# Step 5: Copy your ROS 2 project into the container
WORKDIR /root/workspace
COPY . /root/workspace/

# Step 6: Ensure correct permissions
RUN chown -R root:root /root/workspace

# Step 7: Remove ROS 2 related dependencies from requirements.txt and install the rest
RUN sed -i '/rclpy/d;/sensor_msgs/d' /root/workspace/requirements.txt && pip3 install --no-cache-dir -r /root/workspace/requirements.txt || true

RUN apt-get update && \
    apt-get install -y ros-galactic-image-transport-plugins

# Step 8: Clean the workspace to avoid CMake cache issues
RUN rm -rf /root/workspace/build /root/ros2_ws/install /root/workspace/log

# Step 9: Build the ROS 2 workspace with parallel jobs
RUN . /opt/ros/galactic/setup.sh && colcon build --parallel-workers $(nproc)

# Step 10: Set the default command to run your ROS 2 launch file
CMD ["bash", "-c", "source /opt/ros/galactic/setup.bash && source /root/workspace/install/setup.bash && ros2 launch launch/launch.py"]