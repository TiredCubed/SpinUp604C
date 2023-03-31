#include "autoFunctions.hpp"
#include "main.h"


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void PIDDrive(double target, double kp, double ki, double kd, double integral_limit, int speedlimit){
	
	tareMotorsPositions();
	
	double output;
	double error = target - ((rightFront.get_position() + leftFront.get_position())/2);
	double past_error = 0;
	double integral = 0;
	double derivative = 0;



	while(fabs(error) > 5){
		past_error = error;
		error = target - rightFront.get_position();

		if(fabs(error) < integral_limit){
			integral += error;

		}
		else{
			integral = 0;
		}

	derivative = error - past_error;


	
	output = (error * kp) + (integral * ki) + (derivative * kd);

	
	if(output > speedlimit){
		output = speedlimit;
	}
	if(output < -speedlimit){
		output = -speedlimit;
	}


	leftFront = -output;
	leftBack = -output;
    leftMiddle = output; //stacked motor reverses directions
	rightFront = output;
	rightBack = output;
    rightMiddle = -output; //stacked motor reverses directions





	}
	

}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void PIDTurn(double degree, double kp, double ki, double kd, double integral_limit){
	
	imu.tare_rotation();

	double output;
	double error = degree - imu.get_rotation();
	double past_error = 0;
	double integral = 0;
	double derivative = 0;



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

	

	leftFront = -output;
	leftBack = -output;
	leftMiddle = output;
	rightFront = -output;
	rightBack = -output;
	rightMiddle = output;





	}

}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




  
void PIDDriveIntake(double target, double kp, double ki, double kd, double integral_limit, int speedlimit){
	
	tareMotorsPositions();
	
	double output;
	double error = target - rightFront.get_position();
	double past_error = 0;
	double integral = 0;
	double derivative = 0;



	while(fabs(error) > 5){
		powerIntake(-127);
		past_error = error;
		error = target - rightFront.get_position();

		if(fabs(error) < integral_limit){
			integral += error;

		}
		else{
			integral = 0;
		}

	derivative = error - past_error;


	
	output = (error * kp) + (integral * ki) + (derivative * kd);

	
	if(output > speedlimit){
		output = speedlimit;
	}

	

	leftFront = -output;
	leftBack = -output;
    leftMiddle = output; //stacked motor reverses directions
	rightFront = output;
	rightBack = output;
    rightMiddle = -output; //stacked motor reverses directions





	}

}

