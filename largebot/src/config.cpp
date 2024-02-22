#include "main.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Controller partner(pros::E_CONTROLLER_PARTNER);

pros::Motor frontLeft(1, pros::E_MOTOR_GEARSET_06);
pros::Motor frontRight(2, pros::E_MOTOR_GEARSET_06);
pros::Motor midLeft(3, pros::E_MOTOR_GEARSET_06);
pros::Motor midRight(4, pros::E_MOTOR_GEARSET_06);
pros::Motor backLeft(5, pros::E_MOTOR_GEARSET_06);
pros::Motor backRight(6, pros::E_MOTOR_GEARSET_06);

pros::Motor intakeMotor(7, pros::E_MOTOR_GEARSET_18);
pros::ADIDigitalOut intakePiston ('B');

pros::Motor catapultMotorLeft(8, pros::E_MOTOR_GEARSET_36, true);
pros::Motor catapultMotorRight(9, pros::E_MOTOR_GEARSET_36);
pros::Motor_Group catapult({catapultMotorLeft, catapultMotorRight});

pros::Vision visionSensor(11);

pros::ADIDigitalIn buttonSensor ('A');

std::shared_ptr<OdomChassisController> chassis =
      ChassisControllerBuilder()
        .withMotors({-1, -3, -5}, {2, 4, 6})
        // Blue gearset, 4 in in wheel diam, 40 cm in wheel track
        .withDimensions({AbstractMotor::gearset::blue, (84.0 / 36.0)}, {{4_in, 16_in}, imev5BlueTPR})
        /*.withSensors(
          RotationSensor{16, true}, // Left encoder in V5 port 16 (reversed, the rotation sensors are flipped)
          RotationSensor{6}  // Right encoder in V5 port 6
        )
    		.withOdometry({{4_in, 12.25_in}, quadEncoderTPR})*/
        .withOdometry()
        .withGains(
            {0.001, 0.0000001, 0.00001}, // Distance controller gains
            {0.003, 0.00000015, 0.0001}, // Turn controller gains
            {0.001, 0.0000001, 0.00001} // Angle controller gains (helps drive straight)
          )
        /*.withDerivativeFilters(
            std::make_unique<AverageFilter<3>>(), // Distance controller filter
            std::make_unique<AverageFilter<3>>(), // Turn controller filter
            std::make_unique<AverageFilter<3>>()  // Angle controller filter
          )*/
        .withLogger(
            std::make_shared<Logger>(
                TimeUtilFactory::createDefault().getTimer(), // It needs a Timer
                "/ser/sout", // Output to the PROS terminal
                Logger::LogLevel::debug // Most verbose log level
            )
          )
        //.withClosedLoopControllerTimeUtil(50, 5, 250_ms)
    		.buildOdometry();
