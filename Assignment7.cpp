#include stdio.h
#include string

using namespace std;

int main(int argc, char argv)
{
	declare variables to be used when gathering inputs
	float rockUnitWeight, dFirst, kFirst, dIncrement, kIncrement;
	int numDepthValues, numKValues;
	
	
	gather required input variables, prompting the user with lines of outputted text
	printf(Input rock unit weight (kNm3)n);
	scanf(%f, &rockUnitWeight);
	printf(Input number of depth valuesn);
	scanf(%d, &numDepthValues);
	printf(Input first depth value (m)n);
	scanf(%f, &dFirst);
	printf(Input depth increment (m)n);
	scanf(%f, &dIncrement);
	printf(Input number of k valuesn);
	scanf(%d, &numKValues);
	printf(Input first k value (m)n);
	scanf(%f, &kFirst);
	printf(Input k increment (m)n);
	scanf(%f, &kIncrement);
	
	
	declare arrays that will be filled in a later block of code
	use variable array sizes
	float dValues[numDepthValues];
	float verticalStress[numDepthValues];
	float kValues[numKValues];
	float horizontalStress[numDepthValues][numKValues]; use 2d array for horizontal stress
	
	
	label the upcoming list
	printf(Vertical stress values (kPa)n);
	
	for (int i = 0; i  numDepthValues; i++) {
		dValues[i] = dFirst + idIncrement; calculate each depth value based on the first depth value and the increment, storing the result in the previously declared array
		verticalStress[i] = rockUnitWeightdValues[i]; calculate each vertical stress value based on the depth values just calculated
		printf(%.0fn, verticalStress[i]); output the calculated vertical stress values
	}
	
	calculate and store the k values the same way that was done with the depth values
	for (int i = 0; i  numKValues; i++) {
		kValues[i] = kFirst + ikIncrement;
	}
	
	use nested for loops to populate the horizontal stress array row by row, left to right based on the given formula
	for (int i = 0; i  numDepthValues; i++) {
		for (int j = 0; j  numKValues; j++) {
			horizontalStress[i][j] = verticalStress[i]kValues[j];
		}
	}
	

	string filename = outputFileA.txt; store the name of the file in a string type variable
	FILEfileOutput = fopen(filename.c_str(), w); open the text file
	
	write to the text file
	for (int i = 0; i  numKValues; i++) {
		fprintf(fileOutput, %.0f,, dValues[i]); print the first column of the desired text file output
		
		print the horizontal stress array next to the column of depth values using a nested for loop
		for (int j = 0; j  numKValues; j++) {
			if (j  numKValues - 1) {
				fprintf(fileOutput, %.0f,, horizontalStress[i][j]);
			} else {
				fprintf(fileOutput, %.0f, horizontalStress[i][j]); the last entry on each row is not followed by a comma
			}
		}
		fprintf(fileOutput, n); begin a new line before moving on to the next value of i
	}
	fclose(fileOutput); close the text file
}
