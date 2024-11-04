#include "rclcpp/rclcpp.hpp"
#include "state_base.hpp"
#include "count_10_seconds_state.hpp"
#include "count_5_seconds_state.hpp"
#include "finished_state.hpp"

class RobotController : public rclcpp::Node
{
public:
    RobotController()
        : Node("robot_controller"), current_state_(std::make_shared<Count10SecondsState>())
    {
        timer_ = this->create_wall_timer(
            std::chrono::seconds(1), std::bind(&RobotController::run, this));
    }

    void set_state(std::shared_ptr<StateBase> new_state)
    {
        current_state_ = new_state;
    }

    void run()
    {
        current_state_->execute();

        // Check for state transitions
        if (std::dynamic_pointer_cast<Count10SecondsState>(current_state_))
        {
            auto count10_state = std::dynamic_pointer_cast<Count10SecondsState>(current_state_);
            if (count10_state->is_completed())
            {
                RCLCPP_INFO(this->get_logger(), "Transitioning to Count5SecondsState.");
                set_state(std::make_shared<Count5SecondsState>());
            }
        }
        else if (std::dynamic_pointer_cast<Count5SecondsState>(current_state_))
        {
            auto count5_state = std::dynamic_pointer_cast<Count5SecondsState>(current_state_);
            if (count5_state->is_completed())
            {
                RCLCPP_INFO(this->get_logger(), "Transitioning to finished_state.");
                set_state(std::make_shared<FinishedState>());
            }
        }
    }

private:
    rclcpp::TimerBase::SharedPtr timer_;
    std::shared_ptr<StateBase> current_state_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotController>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}