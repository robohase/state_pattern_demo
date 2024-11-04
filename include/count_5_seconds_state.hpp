#ifndef COUNT_5_SECONDS_STATE_HPP_
#define COUNT_5_SECONDS_STATE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "state_base.hpp"

class Count5SecondsState : public StateBase
{
public:
    Count5SecondsState()
        : count_(0), completed_(false) {}

    void execute() override
    {
        if (count_ < 5)
        {
            RCLCPP_INFO(rclcpp::get_logger("Count5SecondsState"), "Counting: %d", count_);
            ++count_;
        }
        else
        {
            RCLCPP_INFO(rclcpp::get_logger("Count5SecondsState"), "5 seconds completed.");
            completed_ = true;
        }
    }

    bool is_completed() const { return completed_; }

private:
    int count_;
    bool completed_;
};

#endif  // COUNT_5_SECONDS_STATE_HPP_