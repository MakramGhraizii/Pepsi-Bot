cmake_minimum_required(VERSION 3.8)
project(gripper_actions)

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
find_package(gripper_interfaces REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp_action REQUIRED)

include_directories(
  include
)

add_executable(gripper_control_server src/gripper_control_server_launcher.cpp src/gripper_control_server.cpp)
ament_target_dependencies(gripper_control_server rclcpp std_msgs gripper_interfaces rclcpp_action)

install(
  DIRECTORY include/
  DESTINATION include/
)

install(TARGETS
  gripper_control_server
  DESTINATION lib/${PROJECT_NAME}
)

ament_export_include_directories(include)

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
