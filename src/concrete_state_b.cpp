// src/concrete_state_b.cpp
#include "state_pattern_demo/concrete_state_b.hpp"
#include "state_pattern_demo/concrete_state_a.hpp"
#include "state_pattern_demo/context.hpp"

namespace state_pattern_demo {

void ConcreteStateB::MainLoop() {
    auto node = std::dynamic_pointer_cast<Context>(context_);
    if (node) {
        RCLCPP_INFO(node->get_logger(), "ConcreteStateB main loop running");
        RCLCPP_INFO(node->get_logger(), "ConcreteStateB transitioning to StateA");
        context_->TransitionTo(std::make_shared<ConcreteStateA>());
    }
}

} // namespace state_pattern_demo