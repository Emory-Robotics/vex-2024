#include "main.h"

void auton(){
    // autonomous code
    chassis->setState({0_in, 0_in, 0_deg});
    pros::delay(50);

    launching = 2; //lower();
    intakePiston.set_value(false);
    chassis->moveDistance(-1_ft);
    for(int i = 0; i < 15; i++){
        launching = 2; //lower();
        chassis->moveDistance(13_in);
        intake();
        chassis->moveDistance(-1_ft);
        launching = 1; //fire();
        pros::delay(1000);
    }
    

    /*chassis->moveDistance(2_ft);
    intake();
    chassis->moveDistance(-24_in);
    chassis->turnAngle(90_deg);
    chassis->moveDistance(60_in);
    chassis->turnAngle(90_deg);
    score();*/
    //chassis->moveDistance(12_in);

    //chassis->moveDistance(12_in);
    /*chassis->moveDistance(12_in);
    chassis->moveDistance(-12_in);
    chassis->turnAngle(90_deg);
    chassis->turnAngle(-45_deg);
    chassis->turnAngle(-45_deg);*/
}