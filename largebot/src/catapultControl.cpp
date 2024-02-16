#include "main.h"
#define max_analog 128.0 //maximum analog signal, used for scaling when driver input exceeds said value

int catapultPos = 0;
int launching = false;

void catapultControl(){
    // intake control code (for driver control)
    catapultMotorLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    catapultMotorRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        catapultPos += 100;
        if(abs(catapultMotorLeft.get_position()) < abs(catapultPos)){
            catapultMotorLeft.move_velocity(-100);
        }
        if(abs(catapultMotorRight.get_position()) < abs(catapultPos)){
            catapultMotorRight.move_velocity(100);
        }
    } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        catapultPos -= 100;
        if(abs(catapultMotorLeft.get_position()) > abs(catapultPos)){
            catapultMotorLeft.move_velocity(100);
        }
        if(abs(catapultMotorRight.get_position()) > abs(catapultPos)){
            catapultMotorRight.move_velocity(-100);
        }
    } else {
        catapultMotorLeft.move_velocity(0);
        catapultMotorRight.move_velocity(0);
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
        catapultMotorLeft.move_velocity(-max_analog);
        catapultMotorRight.move_velocity(max_analog);
        pros::delay(20);
    }
    catapultMotorLeft.move_velocity(0);
    catapultMotorRight.move_velocity(0);
}
void fire(){
    // fire catapult
    catapultMotorLeft.move_velocity(-max_analog);
    catapultMotorRight.move_velocity(max_analog);
    pros::delay(200);
    catapultMotorLeft.move_velocity(0);
    catapultMotorRight.move_velocity(0);
}