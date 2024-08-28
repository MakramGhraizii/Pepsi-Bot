#ifndef GRIPPER_OBJECT_AT_CORRECT_DISTANCE_H_
#define GRIPPER_OBJECT_AT_CORRECT_DISTANCE_H_

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float32.hpp>
#include <distance_interfaces/srv/get_front_distance.hpp>

namespace perception {
    class DistanceSensorServer : public rclcpp::Node {
    public:
        DistanceSensorServer();

    private:
        void scan_callback(const std_msgs::msg::Float32 & data);

        void get_front_distance_callback(const std::shared_ptr<distance_interfaces::srv::GetFrontDistance::Request> request,
            std::shared_ptr<distance_interfaces::srv::GetFrontDistance::Response> response);

        rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr scan_subscriber;
        rclcpp::Service<distance_interfaces::srv::GetFrontDistance>::SharedPtr service;
        float front_distance;
    };
}

#endif
