// src/concrete_state_b.cpp
#include "state_pattern_demo/concrete_state_b.hpp"
#include "state_pattern_demo/concrete_state_a.hpp"
#include "state_pattern_demo/context.hpp"

namespace state_pattern_demo {

ConcreteStateB::ConcreteStateB() : count_(0) {
}

void ConcreteStateB::MainLoop() {
    auto node = std::dynamic_pointer_cast<rclcpp::Node>(context_);
    if (node) {
        if (!publisher_) {
            publisher_ = node->create_publisher<std_msgs::msg::String>("state_b/message", 10);
        }

        auto message = std_msgs::msg::String();
        message.data = "Message from State B: " + std::to_string(count_++);
        RCLCPP_INFO(node->get_logger(), "Publishing: '%s'", message.data.c_str());
        publisher_->publish(message);

        if (count_ >= 3) {
            context_->TransitionTo(std::make_shared<ConcreteStateA>());
        }
    }
}

} // namespace state_pattern_demo