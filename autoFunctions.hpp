#ifndef _AUTOFUNCTIONS_HPP_
#define _AUTOFUNCTIONS_HPP_

void PIDDrive(double target, double kp, double ki, double kd, double integral_limit, int speedlimit);

void PIDTurn(double degree, double kp, double ki, double kd, double integral_limit);

void PIDDriveIntake(double target, double kp, double ki, double kd, double integral_limit, int speedlimit);


#endif                                          