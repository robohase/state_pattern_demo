// src/concrete_state_a.cpp
#include "state_pattern_demo/concrete_state_a.hpp"
#include "state_pattern_demo/concrete_state_b.hpp"
#include "state_pattern_demo/context.hpp"

namespace state_pattern_demo {

void ConcreteStateA::MainLoop() {
    auto node = std::dynamic_pointer_cast<Context>(context_);
    if (node) {
        RCLCPP_INFO(node->get_logger(), "ConcreteStateA main loop running");
        RCLCPP_INFO(node->get_logger(), "ConcreteStateA transitioning to StateB");
        context_->TransitionTo(std::make_shared<ConcreteStateB>());
    }
}

} // namespace state_pattern_demo