#include "main.h"

void skillsAuton(){
    // autonomous code for skills
    chassis->setState({0_in, 0_in, 0_deg});
    pros::delay(50);

    intakeMotor.move(128);
    chassis->moveDistance(2_ft);
    intakeMotor.move(0);
    //intake();
    chassis->moveDistance(24_in);
    chassis->turnAngle(90_deg);
    chassis->moveDistance(16_in);
    chassis->turnAngle(45_deg);
    flapPiston.set_value(true);
    pros::delay(45000);
    chassis->moveDistance(36_in);
    chassis->turnAngle(-135_deg);
    chassis->moveDistance(24_in);
    //score();
    flapPiston.set_value(false);
    chassis->moveDistance(-24_in);
    chassis->turnAngle(90_deg);
    chassis->moveDistance(24_in);
    chassis->turnAngle(-90_deg);
    flapPiston.set_value(true);
    chassis->moveDistance(24_in);
    chassis->moveDistance(-24_in);
}

void auton(){
    // autonomous code
    //chassis->moveDistance(2_ft);
    /*chassis->turnAngle(90_deg);
    chassis->turnAngle(-90_deg);
    chassis->turnAngle(45_deg);
    chassis->turnAngle(-45_deg);
    pros::delay(25000);*/
    
    chassis->setState({0_in, 0_in, 0_deg});
    pros::delay(50);

    intakeMotor.move(128);
    chassis->moveDistance(2_ft);
    intake();
    chassis->moveDistance(24_in);
    chassis->turnAngle(-90_deg);
    chassis->moveDistance(24_in);
    chassis->turnAngle(-90_deg);
    chassis->moveDistance(12_in);
    chassis->turnAngle(90_deg);
    flapPiston.set_value(true);
    pros::delay(30000);
    chassis->moveDistance(24_in);
    chassis->turnAngle(90_deg);
    chassis->moveDistance(20_in);
    score();
    flapPiston.set_value(false);
    chassis->moveDistance(-20_in);
}