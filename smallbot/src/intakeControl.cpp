#include "main.h"
#define max_analog 84.0 //maximum analog signal, used for scaling when driver input exceeds said value (max is 128)

void intakeControl(){
    // intake control code (for driver control)
    intakeMotorLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    intakeMotorRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    elevatorMotorLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    elevatorMotorRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    armMotorLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    armMotorRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
        intakeMotorLeft.move(max_analog);
        intakeMotorRight.move(-max_analog);

        elevatorMotorLeft.move(-max_analog * 1.0);
        elevatorMotorRight.move(max_analog * 1.0);
    } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        intakeMotorLeft.move(-max_analog);
        intakeMotorRight.move(max_analog);

        elevatorMotorLeft.move(max_analog * 1.0);
        elevatorMotorRight.move(-max_analog * 1.0);
    } else {
        intakeMotorLeft.move_velocity(0);
        intakeMotorRight.move_velocity(0);

        elevatorMotorLeft.move_velocity(0);
        elevatorMotorRight.move_velocity(0);
    }

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        armMotorLeft.move(-max_analog);
        armMotorRight.move(max_analog);
    } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        armMotorLeft.move(max_analog);
        armMotorRight.move(-max_analog);
    } else {
        armMotorLeft.move_velocity(0);
        armMotorRight.move_velocity(0);
    }

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
        flapPiston.set_value(true); // extend
    }
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){
        flapPiston.set_value(false); // retract
    }
}
void intake(){
    // intake one ring (for autonomous)
    intakeMotorLeft.move(-max_analog);
    intakeMotorRight.move(max_analog);

    elevatorMotorLeft.move(max_analog);
    elevatorMotorRight.move(-max_analog);
    pros::delay(1000);
    intakeMotorLeft.move(0);
    intakeMotorRight.move(0);

    elevatorMotorLeft.move(0);
    elevatorMotorRight.move(0);
}
void score(){
    // scores one ring in the goal (for autonomous)
    intakeMotorLeft.move(-max_analog);
    intakeMotorRight.move(max_analog);

    elevatorMotorLeft.move(max_analog);
    elevatorMotorRight.move(-max_analog);
    pros::delay(1000);
    intakeMotorLeft.move(0);
    intakeMotorRight.move(0);

    elevatorMotorLeft.move(0);
    elevatorMotorRight.move(0);
}