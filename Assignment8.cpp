//I was confused by the wording of the assignment. I am going to assume that by "revenue" the assignment means to say "profit" - i.e. the company must generate an annual profit of $36000 to remain profitable.

#include <stdio.h>
#include <iostream>

using namespace std;

//create struct according to assignment instructions
struct centrePayload {
	int numCustomers;
	float avgPrice;
	float avgWeight;
};

class profitAnalysis {
public:
	float costPerKg;
	float targetRev;

//this is the class constructor that allows me to assign values of 4.70 and 36000 to my fields
	profitAnalysis (float cost, float rev) {
		costPerKg = cost;
		targetRev = rev;
	}

	int numCustomers(int numCentres, centrePayload centre[]) {
		float totalCustomers;
		for (int i = 0; i < numCentres; i++) {
			totalCustomers += centre[i].numCustomers; //add the number of customers at each centre to the variable totalCustomers
		}
		return totalCustomers;
	}

	float weight(int numCentres, centrePayload centre[]) {
		float totalWeight;
		for (int i = 0; i < numCentres; i++) {
			totalWeight += centre[i].avgWeight*centre[i].numCustomers;
		}
		return totalWeight;
	}

	float revenue(int numCentres, centrePayload centre[]) {
		float totalRevenue;
		for (int i = 0; i < numCentres; i++) {
			totalRevenue += centre[i].avgPrice*centre[i].numCustomers - costPerKg*centre[i].numCustomers; //this is where I was confused by the difference between revenue and profit. In the end I decided to subtract off cost to get profit, not revenue
		}
		return totalRevenue;
	}		
};

int main() {
	int numCentres;
	centrePayload centre[numCentres]; //initialize an array of structs of variable length (to allow the program to accept any number of centres, not just 5
	profitAnalysis company(4.70, 36000); define a variable of type profitAnalysis

	//printf desired commands and accept desired inputs
	cout << "Input number of centers:" << endl;
	cin >> &numCentres;	
	cout << "Input customer data for all centers:" << endl;
	for (int i = 0; i < numCentres; i++) {
		cin >> centre[i].numCustomers;	
	}
	cout << "Input item average price data for all centers:" << endl;
	for (int i = 0; i < numCentres; i++) {
		cin >> centre[i].avgPrice;	
	}
	cout <<	"Input item average weight data for all centers:" << ends;
	for (int i = 0; i < numCentres; i++) {
		cin >> centre[i].avgWeight;
	}
	
	
//now output the last 4 desired values, calling them from the class "company"
	int totalCustomers;
	totalCustomers = company.numCustomers(numCentres, centre);
	printf("Total customers: %d\n", totalCustomers);

	float totalWeight;
	totalWeight = company.weight(numCentres, centre);
	printf("Total weight: %.0f\n", totalWeight);

	float totalRevenue;
	totalRevenue = company.revenue(numCentres, centre);
	printf("Total revenue: %.0f\n", totalRevenue);
	
	float averageRevenue;
	averageRevenue /= numCentres;
	if (averageRevenue >= company.targetRev) { //determine whether or not the company has met its $36000 target
		printf("Company is profitable\n");
	} else {
		printf("Company is not profitable\n");
	
}