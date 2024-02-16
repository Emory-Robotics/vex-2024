#include "main.h"
#define max_analog 128.0 //maximum analog signal, used for scaling when driver input exceeds said value

void driveControl(){
    // drive train control code (for driver control)
    int forward = - master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int lateral = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
    int left = forward - lateral;
    int right = - forward - lateral;

    frontLeft.move_velocity(left * 600.0 / 128.0);
    midLeft.move_velocity(left * 600.0 / 128.0);
	backLeft.move_velocity(left * 600.0 / 128.0);
	frontRight.move_velocity(right * 600.0 / 128.0);
    midRight.move_velocity(right * 600.0 / 128.0);
	backRight.move_velocity(right * 600.0 / 128.0);
    
}