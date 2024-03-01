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
    chassis->moveDistance(24_in);
    chassis->turnAngle(-90_deg);
    chassis->moveDistance(12_in);
    chassis->turnAngle(90_deg);
    flapPiston.set_value(true);
    chassis->moveDistance(12_in);
    pros::delay(50000);
    chassis->moveDistance(24_in);
    chassis->turnAngle(90_deg);
    chassis->moveDistance(24_in);
    score();
    flapPiston.set_value(false);
}