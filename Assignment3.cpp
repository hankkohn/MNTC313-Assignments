//MNTC313 Assignment 3 Starter Code
//You will need to add headers, variables, calculations and print statements to complete the code
//Variables for user input have been provided already
//Do not alter the user input statement unless you are comfortable with user input already!

#include <stdio.h>
#include <cmath>

int main()
{
	float time, initVel,initAng,initH;

	scanf("%f, %f, %f, %f", &time, &initVel, &initAng, &initH);
	//In the console, enter time, initial velocity, initial angle and initial heigth values on a single line separated by a comma and space.

	float height, verticalVel;
	float g = 9.81; //define and initialize gravity

	height = -0.5*g*pow(time,2) + initVel*sin(initAng*(3.14/180))*time + initH; //define hight as a function of time, converting angle to radians
	verticalVel = -g*time + initVel*sin(initAng*(3.14/180)); //define vertical velocity as a function of time, angle in radians

//the rest of the code follows the design tree outlined in the assignment
//first check whether or not the projectile has been released
	if (time >= 0) { //the projectile has been released
		printf("Projectile released\n");
		printf("Position: %.2f meters\n", height);
		printf("Velocity value: %.2f meters/second\n", verticalVel);
	//now check whether the projectile is ascending or descending
		if (verticalVel >= 0) {
			printf("Projectile ascending\nProjectile above initial position\n"); //the projectile must be above its initial position if it is ascending
			} else if (verticalVel < 0) {
			printf("Projectile descending\n");
		//if the projectile is descending, it could be above or below its initial position. check which one is the case
			if (height >= initH) {
				printf("Projectile above initial position\n");
			} else {
				printf("Projectile below initial position\n");
			}
		}
	} else if (time < 0) { //the projectile has not been released
		printf("Projectile not released\n");
	}
}