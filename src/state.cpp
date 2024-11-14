// src/state.cpp
#include "state_pattern_demo/state.hpp"
#include "state_pattern_demo/context.hpp"

namespace state_pattern_demo {

void State::set_context(std::shared_ptr<Context> context) {
    context_ = context;
}

} // namespace state_pattern_demo