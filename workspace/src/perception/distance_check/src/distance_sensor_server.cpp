#include <distance_check/distance_sensor_server.h>

namespace perception {
    DistanceSensorServer::DistanceSensorServer(): Node("distance_sensor_server") {
        scan_subscriber = this->create_subscription<std_msgs::msg::Float32>
            ("/distanceToObstacle", 10, std::bind(&DistanceSensorServer::scan_callback, this, std::placeholders::_1));
        service = this->create_service<distance_interfaces::srv::GetFrontDistance>
            ("get_front_distance", std::bind(&DistanceSensorServer::get_front_distance_callback, this, std::placeholders::_1, std::placeholders::_2));
        front_distance = 0.0;
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "GetFrontDistance server started. Ready for requests.");
    }

    void DistanceSensorServer::scan_callback(const std_msgs::msg::Float32 & data) {
        front_distance = data.data;
        std::cout << front_distance << std::endl;
    }

    void DistanceSensorServer::get_front_distance_callback(const std::shared_ptr<distance_interfaces::srv::GetFrontDistance::Request> request,
            std::shared_ptr<distance_interfaces::srv::GetFrontDistance::Response> response) {
        response->front_distance = front_distance;
    }
}
