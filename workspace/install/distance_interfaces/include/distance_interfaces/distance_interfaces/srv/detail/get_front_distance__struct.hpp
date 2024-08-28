// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from distance_interfaces:srv/GetFrontDistance.idl
// generated code does not contain a copyright notice

#ifndef DISTANCE_INTERFACES__SRV__DETAIL__GET_FRONT_DISTANCE__STRUCT_HPP_
#define DISTANCE_INTERFACES__SRV__DETAIL__GET_FRONT_DISTANCE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__distance_interfaces__srv__GetFrontDistance_Request __attribute__((deprecated))
#else
# define DEPRECATED__distance_interfaces__srv__GetFrontDistance_Request __declspec(deprecated)
#endif

namespace distance_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetFrontDistance_Request_
{
  using Type = GetFrontDistance_Request_<ContainerAllocator>;

  explicit GetFrontDistance_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit GetFrontDistance_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    distance_interfaces::srv::GetFrontDistance_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const distance_interfaces::srv::GetFrontDistance_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<distance_interfaces::srv::GetFrontDistance_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<distance_interfaces::srv::GetFrontDistance_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      distance_interfaces::srv::GetFrontDistance_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<distance_interfaces::srv::GetFrontDistance_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      distance_interfaces::srv::GetFrontDistance_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<distance_interfaces::srv::GetFrontDistance_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<distance_interfaces::srv::GetFrontDistance_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<distance_interfaces::srv::GetFrontDistance_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__distance_interfaces__srv__GetFrontDistance_Request
    std::shared_ptr<distance_interfaces::srv::GetFrontDistance_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__distance_interfaces__srv__GetFrontDistance_Request
    std::shared_ptr<distance_interfaces::srv::GetFrontDistance_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetFrontDistance_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetFrontDistance_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetFrontDistance_Request_

// alias to use template instance with default allocator
using GetFrontDistance_Request =
  distance_interfaces::srv::GetFrontDistance_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace distance_interfaces


#ifndef _WIN32
# define DEPRECATED__distance_interfaces__srv__GetFrontDistance_Response __attribute__((deprecated))
#else
# define DEPRECATED__distance_interfaces__srv__GetFrontDistance_Response __declspec(deprecated)
#endif

namespace distance_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetFrontDistance_Response_
{
  using Type = GetFrontDistance_Response_<ContainerAllocator>;

  explicit GetFrontDistance_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->front_distance = 0.0f;
    }
  }

  explicit GetFrontDistance_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->front_distance = 0.0f;
    }
  }

  // field types and members
  using _front_distance_type =
    float;
  _front_distance_type front_distance;

  // setters for named parameter idiom
  Type & set__front_distance(
    const float & _arg)
  {
    this->front_distance = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    distance_interfaces::srv::GetFrontDistance_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const distance_interfaces::srv::GetFrontDistance_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<distance_interfaces::srv::GetFrontDistance_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<distance_interfaces::srv::GetFrontDistance_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      distance_interfaces::srv::GetFrontDistance_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<distance_interfaces::srv::GetFrontDistance_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      distance_interfaces::srv::GetFrontDistance_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<distance_interfaces::srv::GetFrontDistance_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<distance_interfaces::srv::GetFrontDistance_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<distance_interfaces::srv::GetFrontDistance_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__distance_interfaces__srv__GetFrontDistance_Response
    std::shared_ptr<distance_interfaces::srv::GetFrontDistance_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__distance_interfaces__srv__GetFrontDistance_Response
    std::shared_ptr<distance_interfaces::srv::GetFrontDistance_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetFrontDistance_Response_ & other) const
  {
    if (this->front_distance != other.front_distance) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetFrontDistance_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetFrontDistance_Response_

// alias to use template instance with default allocator
using GetFrontDistance_Response =
  distance_interfaces::srv::GetFrontDistance_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace distance_interfaces

namespace distance_interfaces
{

namespace srv
{

struct GetFrontDistance
{
  using Request = distance_interfaces::srv::GetFrontDistance_Request;
  using Response = distance_interfaces::srv::GetFrontDistance_Response;
};

}  // namespace srv

}  // namespace distance_interfaces

#endif  // DISTANCE_INTERFACES__SRV__DETAIL__GET_FRONT_DISTANCE__STRUCT_HPP_
