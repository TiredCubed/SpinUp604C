#include "main.h"


void tareMotorsPositions(){
    leftBack.tare_position();
    leftMiddle.tare_position();
    leftFront.tare_position();
    rightBack.tare_position();
    rightMiddle.tare_position();
    rightFront.tare_position();
    catapult.tare_position();
    intakeRoller.tare_position();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void powerCatapult(){

	bool state1 = 1;
	bool state2 = 1;

	while(state1 == 1){


			catapult = 127;

			if(limit.get_value() == 1 && state2 == 1){
				delay(1200);
				state2 = 0;
			}

			if(limit.get_value() == 1 && state2 == 0){
				delay(20);
				catapult = 0;
				state1 = 0;
			}

			if(limit.get_value() == 0){
				catapult = 127;
			}
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void powerIntake(double power){
	intakeRoller = power;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


void powerDrive(double power, double turn){
	leftBack = power + turn;
	leftMiddle = -power - turn;
	leftFront = power + turn;
	rightBack = power + turn;
	rightMiddle = -power - turn;
	rightFront = power + turn;
}






















