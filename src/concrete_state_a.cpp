// src/concrete_state_a.cpp
#include "state_pattern_demo/concrete_state_a.hpp"
#include "state_pattern_demo/concrete_state_b.hpp"
#include "state_pattern_demo/context.hpp"

namespace state_pattern_demo {

ConcreteStateA::ConcreteStateA() 
    : count_(0)
    , count_threshold_(5)
{
    node_ = std::make_shared<rclcpp::Node>("state_a_node");
}

void ConcreteStateA::subscription_callback(const std_msgs::msg::String::SharedPtr msg) {
    RCLCPP_INFO(node_->get_logger(), "Received message'%s'", msg->data.c_str());
    latest_received_message_ = *msg;
}

void ConcreteStateA::initialize() {
    publisher_ = node_->create_publisher<std_msgs::msg::String>("state_a/message", 10);
    
    subscriber_ = node_->create_subscription<std_msgs::msg::String>(
        "/state_a/subscriber_topic", 10,
        std::bind(&ConcreteStateA::subscription_callback, this, std::placeholders::_1));
    
    RCLCPP_INFO(node_->get_logger(), "State A initialized");
}

void ConcreteStateA::MainLoop() {
    auto message = std_msgs::msg::String();
    message.data = "Message from State A: " + std::to_string(count_++);
    RCLCPP_INFO(node_->get_logger(), "Publishing: '%s'", message.data.c_str());
    publisher_->publish(message);
    if(latest_received_message_.data.empty()) {
        RCLCPP_INFO(node_->get_logger(), "Waiting for message");
    }else {
        RCLCPP_INFO(node_->get_logger(), "Processing received message: '%s'", 
                latest_received_message_.data.c_str());
    }

    if (count_ >= count_threshold_) {
        RCLCPP_INFO(node_->get_logger(), "State A completed, transitioning to State B");
        context_->TransitionTo(std::make_shared<ConcreteStateB>());
    }
}

} // namespace state_pattern_demo