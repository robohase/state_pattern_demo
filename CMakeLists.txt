cmake_minimum_required(VERSION 3.5)
project(state_pattern_demo)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find necessary packages
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# Include the include directory
include_directories(include)

# Add the executable and specify the source file
add_executable(state_pattern_demo_node src/state_pattern_demo_node.cpp)

# Link against the necessary libraries
ament_target_dependencies(state_pattern_demo_node rclcpp)

# Install the executable
install(TARGETS
  state_pattern_demo_node
  DESTINATION lib/${PROJECT_NAME}
)

# Install the include directory
install(DIRECTORY include/
  DESTINATION include/${PROJECT_NAME}
)

# ament package
ament_package()
