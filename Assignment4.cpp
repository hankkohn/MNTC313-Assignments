//MNTC313 Assignment 4 Starter Code
//You will need to add headers, variables, calculations and print statements to complete the code
//Variables for user input have been provided already
//Do not alter the user input statement unless you are comfortable with user input already!
#include <stdio.h>
#include <math.h>

int main()
{
	float initialHeight, tankRad, pipeRad;
	int finalT;
	
	scanf("%f, %f, %f, %d", &initialHeight, &tankRad, &pipeRad, &finalT);
	//In the console, enter initial height, tank radius, pipe radius and final time separated by a comma and a space
	
	float g = 9.81; //for ease of use in future calculations
//declare variables that will be used throughout the rest of the code
	float V;
	float volLost;
	float volume;
	float h = initialHeight;
	float velocitySum; //counter that will be added to each velocity is calculated - to help calculate average velocity
	float averageV;
	float halfHeight; //to access the height at t = 1800s

	for (int t = 0; t <= finalT; t++) //start at t = 0, end when t is the final time, add 1 second to time each iteration
	{
		V = 0.5*sqrt(2*g*h); //use height to calculate velocity
		volLost = V*3.14*pow(pipeRad,2);
		h -= volLost/(3.14*pow(tankRad,2)); //subtract change in height from previous height
		volume = h*3.14*pow(tankRad,2); //use updated value for height to calculate volume
		velocitySum += V; //sum all velocity values to calculate average velocity later on
		
		if (t == 1800)
		{
			halfHeight = h; //here is where we access the height value at t = 30 min
		}
	}

	averageV = velocitySum/finalT; //calculate average velocity
	printf("Average velocity value: %.2f m/s\nHeight value after 30 min: %.2f m\nHeight value after 3600 seconds: %.2f m\n", averageV, halfHeight, h);
	
	if (volume <= (initialHeight*3.14*pow(tankRad,2))/2) //determine whether or not tank is half drained and output the corresponding text
	{
		printf("Tank half drained\n");
	} else {
		printf("Tank still not half drained\n");
	}
		
	
}