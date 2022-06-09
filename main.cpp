#include "main.h"
using namespace pros;

Motor lf(2);
Motor lb(14);
Motor rf(10);
Motor rb(20);
IMU imu(15);

//PID functions

//Drive

void powerDrive(double target){
	
	lf.tare_position();
	
	double output;
	double error = target + lf.get_position();
	double past_error = 0;
	double integral = 0;
	double derivative = 0;

	double kp = 1;
	double ki= 0;
	double kd = 0;
	double integral_limit = 10;


	while(fabs(error) > 5){
		past_error = error;
		error = target + lf.get_position();

		if(fabs(error) < integral_limit){
			integral += error;

		}
		else{
			integral = 0;
		}

	derivative = error - past_error;

	output = (error * kp) + (integral * ki) + (derivative * kd);

	lf = -output;
	lb = -output;
	rf = output;
	rb = output;





	}

}

//turn

void powerTurn(double degree){
	
	imu.tare_rotation();

	double output;
	double error = degree - imu.get_rotation();
	double past_error = 0;
	double integral = 0;
	double derivative = 0;

	double kp = 1;
	double ki= 0;
	double kd = 0;
	double integral_limit = 10;


	while(fabs(error) > 5){
		past_error = error;
		error = degree - imu.get_rotation();

		if(fabs(error) < integral_limit){
			integral += error;

		}
		else{
			integral = 0;
		}

	derivative = error - past_error;

	output = (error * kp) + (integral * ki) + (derivative * kd);

	lf = output;
	lb = output;
	rf = output;
	rb = output;





	}

}

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {




}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

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
	powerDrive(2000);
	powerTurn(90);
	powerDrive(-1000);
	powerTurn(45);
	powerDrive(1000);


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
	
}
