#include <gripper_actions/gripper_control_server.h>

using namespace gripper;
int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    auto gripper_control_server = std::make_shared<GripperControlServer>();
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(gripper_control_server);
    executor.spin();
    rclcpp::shutdown();

    return 0;
}