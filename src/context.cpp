// src/context.cpp
#include "state_pattern_demo/context.hpp"

namespace state_pattern_demo {

Context::Context()
    : Node("state_pattern_node") {
    timer_ = this->create_wall_timer(
        std::chrono::seconds(1),
        std::bind(&Context::timer_callback, this));
}

void Context::TransitionTo(std::shared_ptr<State> state) {
    state_ = state;
    state_->set_context(std::dynamic_pointer_cast<Context>(this->shared_from_this()));
}

void Context::timer_callback() {
    if (state_) {
        state_->MainLoop();
    }
}

} // namespace state_pattern_demo