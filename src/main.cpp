#include "rclcpp/rclcpp.hpp"
#include "state_pattern_demo/state_pattern.hpp"

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    
    auto context = std::make_shared<state_pattern_demo::Context>();
    
    context->TransitionTo(std::make_shared<state_pattern_demo::ConcreteStateA>());
    
    context->spin();
    
    rclcpp::shutdown();
    return 0;
}