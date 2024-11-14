#include "state_pattern_demo/context.hpp"

namespace state_pattern_demo {

Context::Context()
    : Node("state_pattern_manager") {
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(100),
        std::bind(&Context::timer_callback, this));
}

void Context::TransitionTo(std::shared_ptr<State> state) {
    // 現在のノードを削除（存在する場合）
    if (state_) {
        executor_.remove_node(state_->get_node());
    }

    // 新しい状態を設定
    state_ = state;
    state_->set_context(std::dynamic_pointer_cast<Context>(this->shared_from_this()));
    
    // 新しい状態を初期化
    state_->initialize();
    
    // 新しいノードをexecutorに追加
    executor_.add_node(state_->get_node());
    
    RCLCPP_INFO(this->get_logger(), "Transitioned to new state");
}

void Context::timer_callback() {
    if (state_) {
        state_->MainLoop();
    }
}

} // namespace state_pattern_demo