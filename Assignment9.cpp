#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

//Implement the data structure here
//use two classes because the starter code includes operations.push_back and ids.push_back - one class for operations and one for ids
class stackOps {
public:
	char array[10000]; //define the array to have a very large size - this will not slow down my runtime as most of these slots will be empty
	int top;

	stackOps() {
		top = 0; //initialize the top of the empty array
	}

//write a basic push function to load the array
//pop and empty functions are not needed
	void push_back(char element) {
		array[top] = element;
		top++;
	}
};

//the id class is almost identical to the char class except that it accepts ints instead of chars
class stackIDs {
public:
	int array[10000];
	int top;

	stackIDs() {
		top = 0;
	}

	void push_back(int element) {
		array[top] = element;
		top++;
	}
};
	

int main(int argc, const char * argv[]) {

	int numberOfHROperations;
	stackOps operations;
	stackIDs ids;
   
	//Ask for the number of HR operations and read
 	printf("Enter the number of HR operations:\n");
 	scanf("%d", &numberOfHROperations);

   
	//Ask for the operations and IDs
	printf("Input the operations and IDs:\n");

	//Read the operations and IDs from stdin
	for (int i = 0; i < numberOfHROperations; i++) {
        	char operation;
        	int id;
        	scanf(" %c%d", &operation, &id);
        	operations.push_back(operation);
        	ids.push_back(id);
	}
   
	//Solve the question
	
	int j = 1; //this counter is used later
	int k; //this counter is also used later
	bool followsRules = true; //use this to check if the decisions were conducted in accordance with John Smith's principles

	for (int i = 0; i < numberOfHROperations; i++) {
	    if (operations.array[i] == '-') {
	        k = i; //k saves the position of the most
	    }
		while (operations.array[i] == '-') {
			if (ids.array[i] != ids.array[k - j]) { //check if the int value at i is the same as the int value at the index at the first firing minus the number of firings from k to j
				followsRules = false;
				break; //the rest of the operations do not need to be checked
			}
			i++;
			j++; //j is the number of firings that have occurred since the first firing in that block of firings
		}
		j = 1; //reset the value of j while searching for the next block of firings
	}

	if (followsRules == true) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
	}

	return 0;
}