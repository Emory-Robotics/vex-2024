#include "main.h"

void auton(){
    // autonomous code
    chassis->setState({0_in, 0_in, 0_deg});
    pros::delay(50);

    //chassis->moveDistance(2_ft);
    //chassis->turnAngle(90_deg);

    chassis->moveDistance(2_ft);
    intake();
    chassis->moveDistance(24_in);
    chassis->turnAngle(-90_deg);
    chassis->moveDistance(60_in);
    chassis->turnAngle(90_deg);
    flapPiston.set_value(false);
    score();
    chassis->moveDistance(6_in);
    for(int i = 0; i < 5; i++){
        chassis->moveDistance(-24_in);
        chassis->moveDistance(24_in);
        score();
    }
    flapPiston.set_value(true);

    /*chassis->moveDistance(24_in);
    chassis->moveDistance(-24_in);
    chassis->turnAngle(90_deg);
    chassis->turnAngle(-45_deg);
    chassis->turnAngle(-45_deg);*/
}