#ifndef FINISHED_STATE_HPP_
#define FINISHED_STATE_HPP_

#include "state_base.hpp"

class FinishedState : public StateBase
{
public:
    FinishedState() {}

    void execute() override
    {
        RCLCPP_INFO(rclcpp::get_logger("FinishedState"), "All states completed.");
    }
};

#endif  // FINISHED_STATE_HPP_
