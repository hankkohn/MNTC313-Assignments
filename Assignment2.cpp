#include <stdio.h>
#include <cmath>

int main()
{
	
	float pLength, pWidth, pDepth, pRadius; //define input variables
	
	scanf("%f, %f, %f, %f", &pLength, &pWidth, &pDepth, &pRadius);
	//In the console, enter length, width, depth and radius on a single line, each separated by a comma and space
	
	float surfaceArea, volume, materialCost, batteryCost; //define output variables
	
	surfaceArea = (pLength*pWidth - (pow(pRadius,2) - 3.14*(pow(pRadius, 2))/4)*4)*2 + pDepth*(pWidth - 2*pRadius)*2 + pDepth*(pLength - 2*pRadius)*2 + pDepth*((3.14*pRadius)/2)*4; //sum of front, back, side and corner surface areas
	volume = (pLength*pWidth - (pow(pRadius,2) - 3.14*(pow(pRadius, 2))/4)*4)*pDepth; //front surface area*depth
	materialCost = volume*0.0183;
	batteryCost = volume*0.45*0.0095;
	
	printf("iPhone surface area:\n%.0f mm2\n", surfaceArea); //output results to screen, 0 decimal places
	printf("iPhone volume:\n%.0f mm3\n", volume);
	printf("iPhone material cost:\n$%.0f\n", materialCost);
	printf("battery cost:\n$%.0f\n", batteryCost);
	
}