#ifndef STATE_PATTERN_DEMO_CONCRETE_STATE_B_HPP_
#define STATE_PATTERN_DEMO_CONCRETE_STATE_B_HPP_

#include "state_pattern_demo/state.hpp"
#include "std_msgs/msg/string.hpp"

namespace state_pattern_demo {

class ConcreteStateB : public State {
private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;

public:
    ConcreteStateB();
    void initialize() override;
    void MainLoop() override;
};

} // namespace state_pattern_demo

#endif // STATE_PATTERN_DEMO_CONCRETE_STATE_B_HPP_