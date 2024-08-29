#ifndef MOVE_FORWARD_LEFT_H_
#define MOVE_FORWARD_LEFT_H_

#include <behaviortree_cpp_v3/behavior_tree.h>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>

namespace navigation {
    // Action Node to move left
    class MoveForwardLeft : public BT::SyncActionNode, public rclcpp::Node {
    public:
        MoveForwardLeft(const std::string& name, const BT::NodeConfiguration& config) : BT::SyncActionNode(name, config), rclcpp::Node("move_forward_left") {
            cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
        }

        static BT::PortsList providedPorts()
        {
            return {BT::InputPort<int>("error_x")};
        }

        BT::NodeStatus tick() override {
            BT::Optional<int> errorXOptional = getInput<int>("error_x");
            if (!errorXOptional) {
                throw BT::RuntimeError("Invalid required input message: ", errorXOptional.error());
            }
            int error_x = errorXOptional.value();

            geometry_msgs::msg::Twist msg;
            msg.linear.x = 0.3;
            msg.angular.z = 0.004 * error_x;
            msg.linear.y = 0;
            msg.linear.z = 0;
            msg.angular.x = 0;
            msg.angular.y = 0;
            cmd_vel_pub_->publish(msg);
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Move forward left.");
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            return BT::NodeStatus::SUCCESS;
        }
    private:
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
    };
}

#endif