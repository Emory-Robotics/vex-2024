#include "main.h"
#define max_analog 128.0 //maximum analog signal, used for scaling when driver input exceeds said value

int launching = 0;

void catapultControlAuton(){
    // overall catapult control, for simultaneos  movement
    while(true){
        if(launching == 2){
            lower();
            launching = 0;
        } else if(launching == 1){
            fire();
            launching = 0;
        }
        pros::delay(20);
    }
}

void catapultControlOP(){
    // catapult control code (for driver control)
    while(true){
        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
            catapult.move_velocity(100);
        } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
            catapult.move_velocity(-100);
        } else {
            catapult.move_velocity(0);
        }

        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A)){
            launching = 2;
        }
        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
            launching = 1;
        }
        if(launching == 2){
            launching = 0;
            lower();
        }
        if(launching == 1){
            launching = 0;
            fire();
        }
        pros::delay(20);
    }
}
void lower(){
    // prep catapult for launch
    while(buttonSensor.get_value() == 0){
        catapult.move_velocity(100);
        pros::delay(20);
    }
    catapult.move_velocity(0);
}
void fire(){
    // fire catapult
    catapult.move_velocity(100);
    pros::delay(500);
    catapult.move_velocity(0);
    lower();
}