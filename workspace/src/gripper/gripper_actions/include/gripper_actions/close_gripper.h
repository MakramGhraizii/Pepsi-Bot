#ifndef CLOSE_GRIPPER_H_
#define CLOSE_GRIPPER_H_

#include <behaviortree_cpp_v3/behavior_tree.h>
#include <rclcpp/rclcpp.hpp>
#include <gripper_interfaces/srv/gripper_control.hpp>

namespace gripper {
    // Action Node to close the gripper
    class CloseGripper : public BT::SyncActionNode, public rclcpp::Node {
    public:
        CloseGripper(const std::string& name) : BT::SyncActionNode(name, {}), rclcpp::Node("close_gripper") {
            client = this->create_client<gripper_interfaces::srv::GripperControl>("/control_gripper");
            request = std::make_shared<gripper_interfaces::srv::GripperControl::Request>();
            request->action = "close";

            using namespace std::chrono_literals;
            while (!client->wait_for_service(1s)) {
                if (!rclcpp::ok()) {
                    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
                    return;
                }
                RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Service not available, waiting again...");
            }
        }

        BT::NodeStatus tick() override{
            auto result = client->async_send_request(request);
            // Wait for the result.
            if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), result) ==
                rclcpp::FutureReturnCode::SUCCESS)
            {
                return BT::NodeStatus::SUCCESS;
            } else {
                return BT::NodeStatus::FAILURE;
            }
        }

    private:
        rclcpp::Client<gripper_interfaces::srv::GripperControl>::SharedPtr client;
        std::shared_ptr<gripper_interfaces::srv::GripperControl::Request> request;
    };
}

#endif