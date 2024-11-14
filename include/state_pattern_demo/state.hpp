// include/state_pattern_demo/state.hpp
#ifndef STATE_PATTERN_DEMO_STATE_HPP_
#define STATE_PATTERN_DEMO_STATE_HPP_

#include <memory>

namespace state_pattern_demo {

class Context;

class State {
protected:
    std::shared_ptr<Context> context_;

public:
    virtual ~State() = default;
    void set_context(std::shared_ptr<Context> context) {
        context_ = context;
    }
    virtual void MainLoop() = 0;
};

} // namespace state_pattern_demo

#endif // STATE_PATTERN_DEMO_STATE_HPP_