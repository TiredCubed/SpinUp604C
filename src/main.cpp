#include "main.h"
#include "baseFunctions.hpp"
#include "pros/motors.h"
#include <string>
using namespace pros;

Motor leftFront(1);
Motor rightFront(6);
Motor leftBack(14);
Motor rightBack(13);
Motor leftMiddle(11);
Motor rightMiddle(19);
Motor intakeRoller(7);
Motor catapult(20);
Imu imu(5);

ADIDigitalOut strings1(4);
ADIDigitalOut strings2(5);
ADIDigitalIn limit(3);
Controller master(E_CONTROLLER_MASTER);




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	//imu reset
	imu.reset();

	delay(2000);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~














void disabled() {}





void competition_initialize() {}


void autonomous() {

rightFront.set_brake_mode(E_MOTOR_BRAKE_HOLD);
rightMiddle.set_brake_mode(E_MOTOR_BRAKE_HOLD);
rightBack.set_brake_mode(E_MOTOR_BRAKE_HOLD);
leftFront.set_brake_mode(E_MOTOR_BRAKE_HOLD);
leftBack.set_brake_mode(E_MOTOR_BRAKE_HOLD);
leftMiddle.set_brake_mode(E_MOTOR_BRAKE_HOLD);

//PROG ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

PIDDrive(50, 1.2, 0, 0, 0, 30);
delay(400);
powerIntake(127);
delay(140);
powerIntake(0);
PIDDrive(-200, 1.1, 0, 0, 0, 80);
PIDTurn(128, 1.2, 0, 0, 0);
PIDDriveIntake(1400, 1, 0, 0, 0, 80);


//AUTO ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




/* 

tareMotorsPositions();
delay(100);
PIDDrive(805, 1.9, 0, 0, 0, 60);
delay(100);
PIDTurn(90, 1.2, 0, 0, 0);
delay(100);
PIDDrive(140, 1.2, 0, 0, 0, 30);
delay(400);
powerIntake(127);
delay(50);
powerIntake(0);
PIDDrive(-200, 1.1, 0, 0, 0, 80);
delay(100);
PIDTurn(-50, 1.4, 0, 0, 0);
delay(100);
PIDDrive(-2991, 1.3, 0, 0, 0, 80);
delay(100);
PIDTurn(84, 1.2, 0, 0, 0);
delay(100);
PIDDrive(-310, 1.2, 0, 0, 0, 80);
delay(100);
powerCatapult();
delay(200);
PIDDrive(200, 1.4, 0, 0, 0, 80);
delay(100);
PIDTurn(60, 1.6, 0, 0, 0);
delay(100);
PIDDriveIntake(1200, 1, 0, 0, 0, 80);
delay(1200);
powerIntake(0);
PIDDrive(-1210, 1.4, 0, 0, 0, 80);
delay(100);
PIDTurn(-65, 1.6, 0, 0, 0);
delay(100);
PIDDrive(-80, 1.4, 0, 0, 0, 80);
powerCatapult();

*/

















}



void opcontrol() {

rightFront.set_brake_mode(E_MOTOR_BRAKE_COAST);
rightMiddle.set_brake_mode(E_MOTOR_BRAKE_COAST);
rightBack.set_brake_mode(E_MOTOR_BRAKE_COAST);
leftFront.set_brake_mode(E_MOTOR_BRAKE_COAST);
leftBack.set_brake_mode(E_MOTOR_BRAKE_COAST);
leftMiddle.set_brake_mode(E_MOTOR_BRAKE_COAST);


int startt = 0;
bool driveToggle = 0;
bool stringToggle = 0;
int catState=0;
	while(true){

//drive ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		double leftX = master.get_analog(ANALOG_LEFT_X);
		double leftY = master.get_analog(ANALOG_LEFT_Y);

		if(master.get_digital_new_press(DIGITAL_A) == 1){
			driveToggle = !driveToggle;
		}



		if(driveToggle == 0){
			leftFront = -leftY + -leftX;
			leftBack = -leftY + -leftX;
			leftMiddle = leftY + leftX;
			rightFront = leftY + -leftX;
			rightBack = leftY + -leftX;
			rightMiddle = -leftY + leftX;
		}
		else if(driveToggle == 1){
			leftFront = leftY + -leftX;
			leftBack = leftY + -leftX;
			leftMiddle = -leftY + leftX;
			rightFront = -leftY + -leftX;
			rightBack = -leftY + -leftX;
			rightMiddle = leftY + leftX;
		}





//Roller and Intake ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


		if(master.get_digital(DIGITAL_L1) == 1 && catState == 1){
			intakeRoller = -127;
		}
		else if(master.get_digital(DIGITAL_L2)==1){
			intakeRoller = 127;

		}
		else{
			intakeRoller = 0;
		}

//Catapult ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

catState = 0;

if (limit.get_value() == true){
		catState = 1;
}
if(master.get_digital(DIGITAL_R2) == 1 && catState == 1){
		catState = 2;
		
	}



if (catState == 0) {
	catapult = 127;
}
if (catState == 1){
	catapult = 0;
}
if (catState == 2){

	catapult = 127;
	delay(50);
	catState = 0;
	

	if (limit.get_value() == 0){
	catState = 0;
	}
}

//String launcher ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



if(master.get_digital(DIGITAL_RIGHT) == 1){
	
	strings1.set_value(1);
	strings2.set_value(1);
}
else {

	strings1.set_value(0);
	strings2.set_value(0);
	
}



		 //delay
		 pros::delay(10);




}

}

