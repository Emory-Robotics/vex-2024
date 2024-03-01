#include "main.h"
#define max_analog 128.0 //maximum analog signal, used for scaling when driver input exceeds said value

void intakeControl(){
    // intake control code (for driver control)
    intakeMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
        intakeMotor.move(max_analog);
    } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        intakeMotor.move(-max_analog);
    } else {
        intakeMotor.move_velocity(0);
    }

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
        flapPiston.set_value(true); // extend
    }
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){
        flapPiston.set_value(false); // retract
    }
}
void intake(){
    // intake one triball (for autonomous)
    intakeMotor.move(-max_analog);
    pros::delay(1000);
    intakeMotor.move(0);
}
void score(){
    // scores one triball in the goal (for autonomous)
    intakeMotor.move(max_analog);
    pros::delay(1000);
    intakeMotor.move(0);
}