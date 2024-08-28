#include <main/main_node.h>

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<main_namespace::MainNode>());

    return 0;
}