// include/state_pattern_demo/concrete_state_b.hpp
#ifndef STATE_PATTERN_DEMO_CONCRETE_STATE_B_HPP_
#define STATE_PATTERN_DEMO_CONCRETE_STATE_B_HPP_

#include "state_pattern_demo/state.hpp"

namespace state_pattern_demo {

class ConcreteStateB : public State {
public:
    void MainLoop() override;
};

} // namespace state_pattern_demo

#endif // STATE_PATTERN_DEMO_CONCRETE_STATE_B_HPP_