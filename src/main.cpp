// src/main.cpp
#include "rclcpp/rclcpp.hpp"
#include "state_pattern_demo/context.hpp"
#include "state_pattern_demo/concrete_state_a.hpp"

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    
    auto context = std::make_shared<state_pattern_demo::Context>();
    context->TransitionTo(std::make_shared<state_pattern_demo::ConcreteStateA>());
    
    rclcpp::spin(context);
    rclcpp::shutdown();
    
    return 0;
}