cmake_minimum_required(VERSION 3.8)
project(main)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
find_package(behaviortree_cpp_v3 REQUIRED)
find_package(rclcpp REQUIRED)
find_package(basic_navigation REQUIRED)
find_package(object_finder REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)
find_package(detection_interfaces REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(distance_interfaces REQUIRED)
find_package(distance_check REQUIRED)
find_package(gripper_interfaces REQUIRED)
find_package(gripper_actions REQUIRED)
find_package(gripper_interfaces REQUIRED)
find_package(robot_hardware_interfaces REQUIRED)

include_directories(include)

add_executable(main_node src/main.cpp src/main_node.cpp)
ament_target_dependencies(main_node
  behaviortree_cpp_v3
  rclcpp
  basic_navigation
  object_finder
  sensor_msgs
  geometry_msgs
  cv_bridge
  OpenCV
  detection_interfaces
  rclcpp_action
  distance_interfaces
  distance_check
  gripper_interfaces
  gripper_actions
  robot_hardware_interfaces
)

install(TARGETS
  main_node
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
