#include "main.h"

pros::task_t catapultTaskAuton = (pros::task_t)NULL;
pros::task_t catapultTaskOP = (pros::task_t)NULL;

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();

	pros::Task guiTask(gui);
	pros::delay(20);

	intakeMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	catapult.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
	catapult.tare_position();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
	chassis->stop();
	if(catapultTaskAuton){
		pros::Task(catapultTaskAuton).remove();
	}
	if(catapultTaskOP){
		pros::Task(catapultTaskOP).remove();
	}
	pros::delay(20);
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	pros::Task catapultTaskAuton(catapultControlAuton);
	auton();
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::Task catapultTaskOP(catapultControlOP);

	while (true) {
		driveControl();
		intakeControl();
		//catapultControl();
		//gui();

		pros::delay(20);
	}
}
