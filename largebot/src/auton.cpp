#include "main.h"

void auton(){
    // autonomous code
    chassis->setState({0_in, 0_in, 0_deg});
    pros::delay(50);

    /*chassis->moveDistance(-1_ft);
    for(int i = 0; i < 5; i++){
        lower();
        chassis->moveDistance(1_ft);
        intake();
        chassis->moveDistance(-1_ft);
        fire();
        pros::delay(1000);
    }*/
    

    /*chassis->moveDistance(2_ft);
    intake();
    chassis->moveDistance(-24_in);
    chassis->turnAngle(90_deg);
    chassis->moveDistance(60_in);
    chassis->turnAngle(90_deg);
    score();*/
    //chassis->moveDistance(12_in);

    //chassis->moveDistance(12_in);
    chassis->moveDistance(12_in);
    chassis->moveDistance(-12_in);
    chassis->turnAngle(90_deg);
    chassis->turnAngle(-45_deg);
    chassis->turnAngle(-45_deg);
}