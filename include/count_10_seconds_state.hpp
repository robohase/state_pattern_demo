#ifndef COUNT_10_SECONDS_STATE_HPP_
#define COUNT_10_SECONDS_STATE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "state_base.hpp"

class Count10SecondsState : public StateBase
{
public:
    Count10SecondsState()
        : count_(0), completed_(false) {}

    void execute() override
    {
        if (count_ < 10)
        {
            RCLCPP_INFO(rclcpp::get_logger("Count10SecondsState"), "Counting: %d", count_);
            ++count_;
        }
        else
        {
            RCLCPP_INFO(rclcpp::get_logger("Count10SecondsState"), "10 seconds completed.");
            completed_ = true;
        }
    }

    bool is_completed() const { return completed_; }

private:
    int count_;
    bool completed_;
};

#endif  // COUNT_10_SECONDS_STATE_HPP_
