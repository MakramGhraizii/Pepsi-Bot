#include <main/ensure_detection_ready.h>
#include <basic_navigation/move_forward.h>
#include <basic_navigation/rotate_right.h>
#include <basic_navigation/move_forward_right.h>
#include <basic_navigation/move_forward_left.h>
#include <basic_navigation/halt.h>
#include <yellow_ball_finder/find_yellow_ball.h>
#include <yellow_ball_finder/yellow_ball_at_center.h>
#include <yellow_ball_finder/yellow_ball_on_right.h>
#include <yellow_ball_finder/yellow_ball_on_left.h>
#include <object_finder/find_object.h>
#include <object_finder/object_at_center.h>
#include <object_finder/object_on_right.h>
#include <object_finder/object_on_left.h>
#include <distance_check/gripper_object_at_correct_distance.h>
#include <gripper_actions/close_gripper.h>
#include <gripper_actions/open_gripper.h>
#include <rclcpp/rclcpp.hpp>
#include <behaviortree_cpp_v3/behavior_tree.h>
#include <behaviortree_cpp_v3/bt_factory.h>

class MainNode : public rclcpp::Node {
public:
    MainNode() : rclcpp::Node("main_node") {
        // Register nodes
        factory_.registerNodeType<EnsureDetectionReady>("EnsureDetectionReady");
        factory_.registerNodeType<FindYellowBall>("FindYellowBall");
        factory_.registerNodeType<YellowBallAtCenter>("YellowBallAtCenter");
        factory_.registerNodeType<YellowBallOnRight>("YellowBallOnRight");
        factory_.registerNodeType<YellowBallOnLeft>("YellowBallOnLeft");
        factory_.registerNodeType<FindObject>("FindObject");
        factory_.registerNodeType<ObjectAtCenter>("ObjectAtCenter");
        factory_.registerNodeType<ObjectOnRight>("ObjectOnRight");
        factory_.registerNodeType<ObjectOnLeft>("ObjectOnLeft");
        factory_.registerNodeType<RotateRight>("RotateRight");
        factory_.registerNodeType<MoveForward>("MoveForward");
        factory_.registerNodeType<MoveForwardRight>("MoveForwardRight");
        factory_.registerNodeType<MoveForwardLeft>("MoveForwardLeft");
        factory_.registerNodeType<Halt>("Halt");
        factory_.registerNodeType<GripperObjectAtCorrectDistance>("GripperObjectAtCorrectDistance");
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
private:
    BT::BehaviorTreeFactory factory_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MainNode>());

    return 0;
}