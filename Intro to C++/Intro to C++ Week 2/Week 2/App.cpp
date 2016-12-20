/////////////////////////////////////////////////////////////////////////////////////////////////
//Program Name: Right Triangle Calculator
//Program Discription: Asks the user to input the lenghts of sides of a triangle and 
//					   calculates if it is a right triangle or not and displays as such.
//Programmed By: Bill Fulton of Baker College
//Course: CS217a Online - C++ Programming
//Date: 01 April 2016 - Spring 2016
/////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main()
{
	double a, b, c; //declare three variables of the type double
	char goAgain; //char variable required for do/while loop

	do {
		system("CLS"); //clear screen at begining of each loop

		cout << "This program will ask for the length of three sides in order to determine \nif they make up a right triangle" << endl << endl; 

		cout << "Enter the length of side a" << endl;
		cin >> a; //get input for side a
		cout << "Enter the length of side b" << endl;
		cin >> b; //get input for side b
		cout << "Enter the length of side c" << endl;
		cin >> c; //get input for side c
		cout << endl; //line break to improve user readability

		if ((pow(a, 2) + pow(b, 2)) == pow(c, 2)) //if a^2 + b^2 = c^2
			cout << "This is a right triangle" << endl << endl; //Output stating this is a right triangle
		else
			cout << "This is not a right triangle" << endl << endl; //if the input is not a right triangle, output a line stating so.

		cout << "Do you want to go again? y or n" << endl; //ask the user if they wish to repeat the program
		cin >> goAgain;	

	} while (tolower(goAgain) == 'y'); //loop while user input is 'y' - ignore case - loop to line 10

	cout << "\nThank you for using this program!" << endl; //end of program execution output
	
	system("PAUSE"); //keep windown open after execution
	return 0;
}