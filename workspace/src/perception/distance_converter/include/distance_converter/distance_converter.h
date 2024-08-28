#ifndef DISTANCE_CONVERTER_H_
#define DISTANCE_CONVERTER_H_

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float32.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>

namespace perception {
    class DistanceConverter : public rclcpp::Node {
    public:
        DistanceConverter();

    private:
        void scan_callback(const sensor_msgs::msg::LaserScan & data);

        rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr scan_subscriber;
        rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr distance_publisher;
    };
}

#endif