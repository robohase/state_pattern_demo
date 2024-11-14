#include "state_pattern_demo/concrete_state_b.hpp"
#include "state_pattern_demo/concrete_state_a.hpp"
#include "state_pattern_demo/context.hpp"

namespace state_pattern_demo {

ConcreteStateB::ConcreteStateB() : count_(0) {
    node_ = std::make_shared<rclcpp::Node>("state_b_node");
}

void ConcreteStateB::initialize() {
    publisher_ = node_->create_publisher<std_msgs::msg::String>("state_b/message", 10);
    RCLCPP_INFO(node_->get_logger(), "State B initialized");
}

void ConcreteStateB::MainLoop() {
    auto message = std_msgs::msg::String();
    message.data = "Message from State B: " + std::to_string(count_++);
    RCLCPP_INFO(node_->get_logger(), "Publishing: '%s'", message.data.c_str());
    publisher_->publish(message);

    if (count_ >= 3) {
        RCLCPP_INFO(node_->get_logger(), "State B completed, transitioning to State A");
        context_->TransitionTo(std::make_shared<ConcreteStateA>());
    }
}

} // namespace state_pattern_demo