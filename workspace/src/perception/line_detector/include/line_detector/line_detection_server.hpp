#ifndef LINE_DETECTION_SERVER_H_
#define LINE_DETECTION_SERVER_H_

#include <rclcpp/rclcpp.hpp>
#include <detection_interfaces/srv/detect_line.hpp>
#include <std_msgs/msg/int8.hpp>

namespace perception {
    class LineDetectionServer : public rclcpp::Node {
    public:
        LineDetectionServer();

    private:
        void scan_callback(const std_msgs::msg::Int8 & data);
        void get_front_distance_callback(const std::shared_ptr<detection_interfaces::srv::DetectLine::Request> request,
            std::shared_ptr<detection_interfaces::srv::DetectLine::Response> response);

        rclcpp::Subscription<std_msgs::msg::Int8>::SharedPtr scan_subscriber;
        rclcpp::Service<detection_interfaces::srv::DetectLine>::SharedPtr service;
    };
}

#endif