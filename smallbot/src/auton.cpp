#include "main.h"

void skillsAuton(){

}

void auton(){
    // autonomous code
    chassis->moveDistance(2_ft);
    chassis->turnAngle(90_deg);
    chassis->turnAngle(-90_deg);
    chassis->turnAngle(45_deg);
    chassis->turnAngle(-45_deg);
    pros::delay(25000);
    
}