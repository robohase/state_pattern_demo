cmake_minimum_required(VERSION 3.5)
project(state_pattern_demo)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find necessary packages
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_srvs REQUIRED)

# Include the include directory
include_directories(include)

# Add the executable and specify all source files
add_executable(state_pattern_node 
    src/main.cpp
    src/state.cpp
    src/context.cpp
    src/concrete_state_a.cpp
    src/concrete_state_b.cpp
)

# Link against the necessary libraries
ament_target_dependencies(state_pattern_node 
    rclcpp 
    std_srvs
)

# Install the executable
install(TARGETS
    state_pattern_node
    DESTINATION lib/${PROJECT_NAME}
)

# Install the include directory
install(DIRECTORY include/
    DESTINATION include/${PROJECT_NAME}
)

# ament package
ament_package()