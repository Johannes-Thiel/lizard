#pragma once

#include "module.h"
#include "roboclaw.h"

class RoboClawMotor;
using RoboClawMotor_ptr = std::shared_ptr<RoboClawMotor>;

class RoboClawMotor : public Module {
private:
    const unsigned int motor_number;
    const RoboClaw_ptr roboclaw;

public:
    RoboClawMotor(const std::string name, const RoboClaw_ptr roboclaw, const unsigned int motor_number);
    void step() override;
    void call(const std::string method_name, const std::vector<ConstExpression_ptr> arguments) override;

    int get_position() const;
    void power(double value);
    void speed(int value);
};
