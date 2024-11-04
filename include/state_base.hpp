#ifndef STATE_BASE_HPP_
#define STATE_BASE_HPP_

#include <memory>
#include "rclcpp/rclcpp.hpp"

class StateBase
{
public:
    virtual ~StateBase() = default;
    virtual void execute() = 0;
};

#endif  // STATE_BASE_HPP_