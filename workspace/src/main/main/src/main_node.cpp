#include <main/main_node.h>

namespace main_namespace {
    MainNode::MainNode() : rclcpp::Node("main_node") {
        // Register nodes
        factory_.registerNodeType<EnsureDetectionReady>("EnsureDetectionReady");
        factory_.registerNodeType<perception::FindObject>("FindObject");
        factory_.registerNodeType<perception::ObjectAtCenter>("ObjectAtCenter");
        factory_.registerNodeType<perception::ObjectOnRight>("ObjectOnRight");
        factory_.registerNodeType<perception::ObjectOnLeft>("ObjectOnLeft");
        factory_.registerNodeType<navigation::RotateRight>("RotateRight");
        factory_.registerNodeType<navigation::MoveForward>("MoveForward");
        factory_.registerNodeType<navigation::MoveForwardRight>("MoveForwardRight");
        factory_.registerNodeType<navigation::MoveForwardLeft>("MoveForwardLeft");
        factory_.registerNodeType<navigation::Halt>("Halt");
        factory_.registerNodeType<perception::GripperObjectAtCorrectDistance>("GripperObjectAtCorrectDistance");
        factory_.registerNodeType<gripper::CloseGripper>("CloseGripper");
        factory_.registerNodeType<gripper::OpenGripper>("OpenGripper");
        auto tree = factory_.createTreeFromFile("./src/main/main/include/main/main_behavior_tree.xml");
        tree.rootBlackboard()->set<std::string>("ObjectType", "can");
        tree.rootBlackboard()->set<int>("FrameWidth", 0);
        tree.rootBlackboard()->set<int>("CX", 0);
        tree.rootBlackboard()->set<int>("CY", 0);
        tree.rootBlackboard()->set<int>("ErrorX", 0);
        BT::NodeStatus status = tree.tickRootWhileRunning();
        rclcpp::shutdown();
    }
}