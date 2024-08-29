#include <gripper_actions/gripper_control_server.h>

namespace gripper{
    GripperControlServer::GripperControlServer() : Node("gripper_control_server") {
        closed = false;
        goal_sent = false;

        cb_group = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);

        this->action_client = rclcpp_action::create_client<GripperAction>(
            this,
            "/gripper_action"
        );
        using namespace std::placeholders;
        send_goal_options = rclcpp_action::Client<GripperAction>::SendGoalOptions();
        send_goal_options.goal_response_callback = std::bind(
            &GripperControlServer::goal_response_callback,
            this,
            _1
        );
        send_goal_options.feedback_callback = std::bind(
            &GripperControlServer::feedback_callback,
            this,
            _1,
            _2
        );
        send_goal_options.result_callback = std::bind(
            &GripperControlServer::result_callback,
            this,
            _1
        );
        service = this->create_service<gripper_interfaces::srv::GripperControl> (
            "/control_gripper",
            std::bind(&GripperControlServer::gripper_control_callback, this, _1, _2),
            rmw_qos_profile_services_default,
            cb_group
        );
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "GripperControlServer started. Ready for requests.");
    }

    void GripperControlServer::gripper_control_callback(const std::shared_ptr<gripper_interfaces::srv::GripperControl::Request> request,
        std::shared_ptr<gripper_interfaces::srv::GripperControl::Response> response) {
        auto action = request->action;
        if (action == "close") {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Received request to close gripper.");
            // // Send action request
            // auto goal_msg = GripperAction::Goal();
            // closed = false;
            // goal_handle = action_client->async_send_goal(goal_msg, send_goal_options).get();
            // goal_sent = true;
            // while (!closed) {
            //     std::this_thread::sleep_for(std::chrono::milliseconds(50));
            // }
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        } else if (action == "open") {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Received request to open gripper.");
            // // Cancel action request
            // if (goal_sent) {
            //     action_client->async_cancel_goal(goal_handle);
            //     goal_sent = false;
            // }
        } else {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Invalid request.");
        }
    }

    void GripperControlServer::goal_response_callback(const GoalHandleGripperAction::SharedPtr & goal_handle) {
            // if (!goal_handle) {
            //     RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Goal rejected.");
            // } else {
            //     RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Goal accepted.");
            // }
        }

    void GripperControlServer::feedback_callback(
        GoalHandleGripperAction::SharedPtr,
        const std::shared_ptr<const GripperAction::Feedback> feedback
    ) {
        if (feedback->feedback >= 2) {
            closed = true;
        }
    }

    void GripperControlServer::result_callback(const GoalHandleGripperAction::WrappedResult & result) {
        switch (result.code) {
            case rclcpp_action::ResultCode::SUCCEEDED:
                break;
            case rclcpp_action::ResultCode::ABORTED:
                RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Goal aborted.");
                return;
            case rclcpp_action::ResultCode::CANCELED:
                RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Goal canceled.");
                return;
            default:
                RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Unkown result.");
                return;
        }
        closed = false;
        goal_sent = false;
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Gripper timeout.");
    }
}