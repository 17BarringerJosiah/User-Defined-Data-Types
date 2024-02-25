// Project6.cpp : This file contains the 'main' function. Program execution begins and ends there.

// <Project6> -- Programming: User-Defined Data Types Assignment
// CSIS111-<B01>

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Function to calculate board feet
double calculateBoardFeet(int width, int height, int length) {
	return (width * height * length) / 12.0;
}

//Function to calculate for wood type and board feet
double calculateCost(char woodType, int quantity, int width, int height, int length) {
	double boardFeet = calculateBoardFeet(width, height, length);
	double costPerBoardFoot;

//switch statement to determine the price based on wood type
	switch (woodType) {
	case 'P':
		costPerBoardFoot = 0.08;
		break;
	case 'F':
		costPerBoardFoot = 1.09;
		break;
	case 'C':
		costPerBoardFoot = 2.26;
		break;
	case 'M':
		costPerBoardFoot = 4.50;
		break;
	case 'O':
		costPerBoardFoot = 3.10;
		break;
	default:
		costPerBoardFoot = 0.0;
		break;
	}

	return quantity * boardFeet * costPerBoardFoot;
}

int main()
{
	cout << "Josiah Barringer -- CSIS111_B01" << endl << endl;

//Declare varibles
	char woodType;
	int quantity, width, height, length;
	double totalCost = 0.0;

//Output instructions to user
	cout << "Welcome" << endl;
	cout << "Input desired order in the following format: Woodtype (P, F, C, M, or O) Quantity Width Height Length" << endl;
	cout << "Once you have finished adding items, enter 'T' to get your order total." << endl;
	
//while loop that prompts user to enter items until they are complete and ready to input 'T'
	while (true) {
		cout << "Enter here: ";
		cin >> woodType;

		if (woodType == 'T') {
			break;
		}

	//user inout here
		cin >> quantity >> width >> height >> length;

	//calculate item cost for each input using calculateCost function
		double itemCost = calculateCost(woodType, quantity, width, height, length);
	//add to the total cost
		totalCost += itemCost;

	//print details of items ordered
		cout << fixed << setprecision(2);
		cout << quantity << " " << width << "x" << height << "x" << length << " " << woodType << " at a cost of " << itemCost << endl;

	}

	//print order total if prompted with user input of 'T"
	cout << "The total for your order is: " << totalCost << endl;
	
	return 0;
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
