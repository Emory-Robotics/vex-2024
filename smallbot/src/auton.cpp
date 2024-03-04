#include "main.h"

void auton(){
    // autonomous code
    chassis->setState({0_in, 0_in, 0_deg});
    pros::delay(50);

    //chassis->moveDistance(2_ft);
    //chassis->turnAngle(90_deg);

    //chassis->setMaxVelocity(chassis->getMaxVelocity() * 0.8);
    chassis->moveDistance(2_ft);
    intake();
    chassis->moveDistance(24_in);
    chassis->turnAngle(90_deg);
    chassis->moveDistance(24_in);
    chassis->turnAngle(90_deg);
    chassis->moveDistance(12_in);
    chassis->turnAngle(-90_deg);
    flapPiston.set_value(true);
    //chassis->moveDistance(12_in);
    pros::delay(40000); // -15 sec for actual tournament, 40 sec for skills
    chassis->moveDistance(24_in);
    chassis->turnAngle(-90_deg);
    chassis->moveDistance(20_in);
    score();
    flapPiston.set_value(false);
    chassis->moveDistance(-20_in);
}