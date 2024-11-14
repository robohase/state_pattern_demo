#ifndef STATE_PATTERN_DEMO_STATE_HPP_
#define STATE_PATTERN_DEMO_STATE_HPP_

#include <memory>
#include "rclcpp/rclcpp.hpp"

namespace state_pattern_demo {

class Context;

/**
 * @brief ステートパターンの基底クラス
 * @details ROSノードの機能を持つ状態を表現する基底クラス
 */
class State {
protected:
    std::shared_ptr<Context> context_;
    std::shared_ptr<rclcpp::Node> node_;  // ROSノードへの参照

public:
    virtual ~State() = default;

    // コンテキストとの関連付け
    void set_context(std::shared_ptr<Context> context) {
        context_ = context;
    }

    // ノードの取得
    std::shared_ptr<rclcpp::Node> get_node() {
        return node_;
    }

    // 状態固有の初期化処理
    virtual void initialize() = 0;

    // メインループ処理
    virtual void MainLoop() = 0;
};

} // namespace state_pattern_demo

#endif // STATE_PATTERN_DEMO_STATE_HPP_