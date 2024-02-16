#include "main.h"
#define max_analog 128.0 //maximum analog signal, used for scaling when driver input exceeds said value

int launching = false;

void catapultControl(){
    // intake control code (for driver control)
    catapult.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        catapult.move_velocity(100);
    } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        catapult.move_velocity(-100);
    } else {
        catapult.move_velocity(0);
    }

    if(!launching){
        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A)){
            lower();
            launching = true;
        }
    } else {
        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
            fire();
            launching = false;
        }
    }

}
void lower(){
    // prep catapult for launch
    while(buttonSensor.get_value() == 0){
        catapult.move_velocity(100);
        pros::delay(20);
    }
    launching = false;
    catapultMotorLeft.move_velocity(0);
    catapultMotorRight.move_velocity(0);
}
void fire(){
    // fire catapult
    catapult.move_velocity(100);
    pros::delay(200);
    catapultMotorLeft.move_velocity(0);
    catapultMotorRight.move_velocity(0);
}