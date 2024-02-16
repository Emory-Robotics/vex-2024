#include "main.h"

void gui(){
    while(true){
        pros::lcd::clear_line(0);
        pros::lcd::clear_line(1);
        pros::lcd::clear_line(2);
        pros::lcd::clear_line(3);
        pros::lcd::clear_line(4);
        pros::lcd::clear_line(5);
        pros::lcd::clear_line(6);
        pros::lcd::clear_line(7);

        pros::lcd::print(0, "fL I: %d, fR I: %d", frontLeft.get_current_draw(), frontRight.get_current_draw());
        pros::lcd::print(1, "bL I: %d, bR I: %d", backLeft.get_current_draw(), backRight.get_current_draw());

        pros::lcd::print(2, "fL C: %f, fR C: %f", frontLeft.get_temperature(), frontRight.get_temperature());
        pros::lcd::print(3, "bL C: %f, bR C: %f", backLeft.get_temperature(), backRight.get_temperature());

        //pros::lcd::print(4, "frontLeft W: %i, frontRight W: %i", frontLeft.get_power(), frontRight.get_power());
        //pros::lcd::print(5, "backLeft W: %i, backRight W: %i", backLeft.get_power(), backRight.get_power());

        pros::lcd::print(4, chassis->getState().str().c_str());
        pros::lcd::print(5, " ");

        pros::lcd::print(6, "Battery: %f", pros::battery::get_capacity());
        pros::lcd::print(7, "Controller Battery: %d", master.get_battery_level());
        pros::delay(20);
    }
}