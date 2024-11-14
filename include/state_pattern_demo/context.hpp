#ifndef STATE_PATTERN_DEMO_CONTEXT_HPP_
#define STATE_PATTERN_DEMO_CONTEXT_HPP_

#include "rclcpp/rclcpp.hpp"
#include "state_pattern_demo/state.hpp"
#include <memory>

namespace state_pattern_demo {

/**
 * @brief ステート管理を行うコンテキストクラス
 */
class Context : public rclcpp::Node {
private:
    rclcpp::executors::MultiThreadedExecutor executor_;
    std::shared_ptr<State> state_;
    rclcpp::TimerBase::SharedPtr timer_;
    
    void timer_callback();

public:
    Context();
    
    /**
     * @brief 状態を遷移する
     * @param state 遷移先の状態
     */
    void TransitionTo(std::shared_ptr<State> state);

    /**
     * @brief 実行を開始する
     */
    void spin() {
        executor_.add_node(shared_from_this());
        executor_.spin();
    }
};

} // namespace state_pattern_demo

#endif // STATE_PATTERN_DEMO_CONTEXT_HPP_