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
    score();
    chassis->moveDistance(12_in);
    for(int i = 0; i < 5; i++){
        chassis->moveDistance(-12_in);
        chassis->moveDistance(12_in);
        score();
    }

    //chassis->moveDistance(12_in);

}