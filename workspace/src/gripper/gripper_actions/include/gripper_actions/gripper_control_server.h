#ifndef GRIPPER_CONTROL_SERVER_H_
#define GRIPPER_CONTROL_SERVER_H_

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float32.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <gripper_interfaces/srv/gripper_control.hpp>
#include <robot_hardware_interfaces/action/gripper_action.hpp>

namespace gripper {
    using GripperAction = robot_hardware_interfaces::action::GripperAction;
    using GoalHandleGripperAction = rclcpp_action::ClientGoalHandle<GripperAction>;

    class GripperControlServer : public rclcpp::Node {
    public:
        GripperControlServer();

    private:
        void gripper_control_callback(const std::shared_ptr<gripper_interfaces::srv::GripperControl::Request> request,
            std::shared_ptr<gripper_interfaces::srv::GripperControl::Response> response);

        void goal_response_callback(const GoalHandleGripperAction::SharedPtr & goal_handle);

        void feedback_callback(
            GoalHandleGripperAction::SharedPtr,
            const std::shared_ptr<const GripperAction::Feedback> feedback
        );

        void result_callback(const GoalHandleGripperAction::WrappedResult & result);

        void cancel_callback(const GoalHandleGripperAction::WrappedResult & result);

        rclcpp::Service<gripper_interfaces::srv::GripperControl>::SharedPtr service;
        rclcpp_action::Client<GripperAction>::SharedPtr action_client;
        std::shared_ptr<gripper::GoalHandleGripperAction> goal_handle;
        rclcpp_action::Client<GripperAction>::SendGoalOptions send_goal_options;
        rclcpp::CallbackGroup::SharedPtr cb_group;

        bool closed;
        bool goal_sent;
    };
}

#endif