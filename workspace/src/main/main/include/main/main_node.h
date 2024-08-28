#include <main/ensure_detection_ready.h>
#include <basic_navigation/move_forward.h>
#include <basic_navigation/rotate_right.h>
#include <basic_navigation/move_forward_right.h>
#include <basic_navigation/move_forward_left.h>
#include <basic_navigation/halt.h>
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

namespace main_namespace {
    class MainNode : public rclcpp::Node {
    public:
        MainNode();
    private:
        BT::BehaviorTreeFactory factory_;
    };
}
