//MNTC313 Assignment 6 Starter Code
//You will need to add headers, variables, calculations and print statements to complete the code
//Variables for user input have been provided already
//Do not alter the user input statement unless you are comfortable with user input already!

#include <stdio.h>

void bridgeDeckFailure(float modulus, float strain); //declare function so program knows to expect it

int main()
{
	float elasticMod, strain;
	
	scanf("%f, %f", &elasticMod, &strain);
	//In the console, enter elastic modulus (MPa) and strain values on a single line separated by a comma and space.

bridgeDeckFailure(elasticMod, strain); //call function
//the value for elasticMod is copied to modulus and the value for strain is copied to strain before bridgeDeckFailure runs
	
}


//define function - use void type as we do not need to return an output
void bridgeDeckFailure(float modulus, float strain) {
	float stress;
	stress = modulus*strain; //define stress to to be the product of the function's inputs
	printf("Stress value: %.2f MPa\n", stress); //although this function doesn't return stress, this line prints the value of stress

//now print the condition of the bridge deck and any warnings if necessary - nested for loops are used below to do this	
	if (stress > 0) {
		printf("Bridge deck in tension\n");
		if (stress > 5) {
			printf("Danger: tensile strength exceeded\n");
		} else {
			printf("Bridge deck safe\n");
		}
	} else if (stress < 0) {
		printf("Bridge deck in compression\n");
		if (stress < -30) {
			printf("Danger: compressive strength exceeded\n");
		} else {
			printf("Bridge deck safe\n");
		}
	} else {
		printf("No stress in bridge\n");
	}
}