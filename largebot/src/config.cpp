#include "main.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Controller partner(pros::E_CONTROLLER_PARTNER);

pros::Motor frontRight(2, pros::E_MOTOR_GEARSET_06);
pros::Motor backRight(4, pros::E_MOTOR_GEARSET_06);
pros::Motor frontLeft(1, pros::E_MOTOR_GEARSET_06);
pros::Motor backLeft(3, pros::E_MOTOR_GEARSET_06);

pros::Motor intakeMotorLeft(5, pros::E_MOTOR_GEARSET_06);
pros::Motor intakeMotorRight(6, pros::E_MOTOR_GEARSET_06);

pros::Motor elevatorMotorLeft(7, pros::E_MOTOR_GEARSET_06);
pros::Motor elevatorMotorRight(8, pros::E_MOTOR_GEARSET_06);

pros::Motor armMotorLeft(9, pros::E_MOTOR_GEARSET_36);
pros::Motor armMotorRight(10, pros::E_MOTOR_GEARSET_36);

pros::ADIDigitalOut flapPiston ('A');

pros::Vision visionSensor(11);

std::shared_ptr<OdomChassisController> chassis =
      ChassisControllerBuilder()
        .withMotors({-1, -3}, {2, 4})
        // Blue gearset, 4 in in wheel diam, 26 cm in wheel track
        .withDimensions({AbstractMotor::gearset::blue, (84.0 / 36.0)}, {{4_in, 14.5_in}, imev5BlueTPR})
        /*.withSensors(
          RotationSensor{16, true}, // Left encoder in V5 port 16 (reversed, the rotation sensors are flipped)
          RotationSensor{6}  // Right encoder in V5 port 6
        )
    		.withOdometry({{4_in, 12.25_in}, quadEncoderTPR})*/
        .withOdometry()
        .withGains(
            /*{0.001, 0.0000001, 0.00001},
            {0.001, 0.0000001, 0.00001},
            {0.001, 0.0000001, 0.00001}*/
            {0.001, 0.0000001, 0.00001},
            {0.0008, 0.0000220, 0.00001},
            {0.0, 0.0, 0.0}
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
