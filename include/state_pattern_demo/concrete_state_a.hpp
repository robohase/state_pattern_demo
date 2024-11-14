// include/state_pattern_demo/concrete_state_a.hpp
#ifndef STATE_PATTERN_DEMO_CONCRETE_STATE_A_HPP_
#define STATE_PATTERN_DEMO_CONCRETE_STATE_A_HPP_

#include "state_pattern_demo/state.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace state_pattern_demo {

class ConcreteStateA : public State {
private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;

public:
    ConcreteStateA();
    void MainLoop() override;
};

} // namespace state_pattern_demo

#endif // STATE_PATTERN_DEMO_CONCRETE_STATE_A_HPP_