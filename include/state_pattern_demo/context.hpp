// include/state_pattern_demo/context.hpp
#ifndef STATE_PATTERN_DEMO_CONTEXT_HPP_
#define STATE_PATTERN_DEMO_CONTEXT_HPP_

#include "rclcpp/rclcpp.hpp"
#include "state_pattern_demo/state.hpp"
#include <memory>

namespace state_pattern_demo {

class Context : public rclcpp::Node {
private:
    std::shared_ptr<State> state_;
    rclcpp::TimerBase::SharedPtr timer_;
    void timer_callback();

public:
    Context();
    void TransitionTo(std::shared_ptr<State> state);
};

} // namespace state_pattern_demo

#endif // STATE_PATTERN_DEMO_CONTEXT_HPP_