// include/state_pattern_demo/concrete_state_a.hpp
#ifndef STATE_PATTERN_DEMO_CONCRETE_STATE_A_HPP_
#define STATE_PATTERN_DEMO_CONCRETE_STATE_A_HPP_

#include "state_pattern_demo/state.hpp"
#include "std_msgs/msg/string.hpp"

namespace state_pattern_demo {

class ConcreteStateA : public State {
private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;
    size_t count_;
    size_t count_threshold_;
    std_msgs::msg::String latest_received_message_;

    void subscription_callback(const std_msgs::msg::String::SharedPtr msg);

public:
    ConcreteStateA();
    void initialize() override;
    void MainLoop() override;
};

} // namespace state_pattern_demo

#endif // STATE_PATTERN_DEMO_CONCRETE_STATE_A_HPP_