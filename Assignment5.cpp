//MNTC313 Assignment 5 Starter Code
//You will need to add headers, variables, calculations and print statements to complete the code
//Variables for user input have been provided already
//Do not alter the user input statement unless you are comfortable with user input already!
#include <stdio.h>
#include <math.h>

#define N 12 //Number of coordinate values

int main()
{
	float coordinates[N][2]; //Initialize array
	
	for (int i = 0; i < N; i++)
	{
		scanf("%f, %f", &coordinates[i][0],&coordinates[i][1]);
	}
	//In the console, enter the 12 coordinate values on a single line separated by comma and by spaces (ie. 1.1,5.6 5.5,8.2 etc.)
	//2.1,10.0 5.5,8.2 5.5,10.1 10.8,3.6 4.0,11.3 2.8,7.5 6.3,10.0 6.3,1.1 8.0,4.0 4.3,7.0 6.3,5.1 10.8,3.3
	
	
	//this block of code prints the inputs
	for (int i = 0; i < N/2; i ++)
	{
		printf("(%.1f,%.1f),", coordinates[i][0], coordinates[i][1]); //print first 6 coordinates before line break
	}
	printf("\n");
	for (int i = N/2; i < N - 1; i++)
	{
		printf("(%.1f,%.1f),", coordinates[i][0], coordinates[i][1]); //print next 5 coordinates after line break
	}
	printf("(%.1f,%.1f)\n\n", coordinates[N - 1][0], coordinates[N - 1][1]); //print final coordrinates on same line  without comma
	
	
	//now compute and print the average coordinates
	float averageX = 0; 
	float averageY = 0; //initialize these values to 0 as we will be adding to them in following loop
	for (int i = 0; i < N; i++)
	{
		averageX += (coordinates[i][0])/N; //distributive property allows us to calculate average like this (sum of 12 numbers)
		averageY += (coordinates[i][1])/N;
	}
	printf("Average center: (%.1f,%.1f)\n\n", averageX, averageY);
	
	
	//compute distances from each coordinate and average distances
	float distances[N][N];
	float avgDistances[N] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //initialize 1D array to have values all equal to 0 b/c we will be adding to them
	for (int i = 0; i < N; i++) //populate 12x12 table vertically
	{
		for (int j = 0; j < N; j++) //populate 12x12 table horizontally
		{
			distances[i][j] = sqrt(pow((coordinates[j][0] - coordinates[i][0]),2) + pow((coordinates[j][1] - coordinates[i][1]),2)); //use pythagorean theorem to compute distance from each point to each other one
			avgDistances[i] += (distances[i][j])/(N - 1); //compute average distances in same manner as on lines 40 and 41, indexing them in the array avgDistances
		}
	}
	
	
	//print the computed distances
	for (int i = 0; i < N; i++) //populate the table vertically
		{
			int fromPointNumber = i + 1; //this variable is necessary since i starts from 0 - we want to start from point 1
			printf("Distance from point %d to\n", fromPointNumber);
			for (int j = 0; j < N - 1; j++) //populate each row of the table
			{
				int toPointNumber = j + 1; //start from 1, not 0
				printf("%d.- %.1f, ", toPointNumber, distances[i][j]);
			}
			int j = N - 1; //subtract 1 from N to align with the indexing system which goes from 0-11
			int toPointNumber = j + 1;
			printf("%d.- %.1f\n", toPointNumber, distances[i][j]); //last entry in each row must be printed separately (no comma)
		}
	printf("\n");
	
	
	//print average distances
	for (int i = 0; i < N; i++)
	{
		int fromPointNumber = i + 1;
		printf("Average distance from point %d: %.1f km\n", fromPointNumber, avgDistances[i]);
	}
}