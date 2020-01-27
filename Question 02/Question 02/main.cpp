#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// q denotes a state/node of the DFA graph

#define q_0 0
#define q_1 1
#define q_2 2
#define q_3 3

#define STARTING_STATE q_0
#define ACCEPTING_STATE q_1

#define REJECTING_STATE_0 q_0
#define REJECTING_STATE_2 q_2
#define REJECTING_STATE_3 q_3


int DFA(string binaryNumber)

// 1. The 2D Array "table" is the corresponding transition table of the DFA
// 2. States q_0, q_1, q_2, and q_3 are equal to 0, 1, 2, 3 respectively, this means
// 		that the current state affects the position within table by means
//		of controlling the x-dimension of the 2D array (i.e. the transition table)
// 3. Since input is a string, mod 48 is used to get 0 or 1. Anything else will prompt "Invalid.." msg
// 4. After exit of the for loop, currentState denotes the final state/position within the DFA graph

{
	int currentState = STARTING_STATE;
	int table[4][2] = { { q_0, q_1 },
						{ q_3, q_2 },
						{ q_2, q_2 },
						{ q_1, q_2 } };

	for (int i = 0; i < binaryNumber.length(); i++)
	{
		int digit = binaryNumber[i] % 48;

		if (digit > 1)
			return -1;
		else
			currentState = table[currentState][digit];
	}

	return currentState;
}


int main()

// 1. Decimals of Numbers in Text File: 4^3, 4^6, 2^3, 5^3, 6^2, 9^2
// 2. This DFA accepts only powers of 4, thus 
//			only the first two rows (4^3 and 4^6) will be accepted

{
	fstream inputFile("input.txt");
	string inputNumber;

	if (!inputFile)
	{
		cout << "Error Accessing File" << endl;
		return 0;
	}

	while(inputFile >> inputNumber)
	{
		cout << "Number Currently: " << inputNumber << endl;

		switch (DFA(inputNumber))
		{
		case -1:
			cout << "Invalid Input" << endl;
			break;
		case REJECTING_STATE_0:
		case REJECTING_STATE_2:
		case REJECTING_STATE_3:
			cout << "Rejected" << endl;
			break;
		case ACCEPTING_STATE:
			cout << "Accepted" << endl;
			break;
		default:
			cout << "Unforeseen Error." << endl;
			break;
		}

		cout << endl;
	}

	inputFile.close();

	return 0;
}










