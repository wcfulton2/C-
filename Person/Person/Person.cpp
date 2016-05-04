// Person.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

void showMenu();
void takeAction(Person p);

int main()
{
	Person p; //new instance of Person

	showMenu(); //void function to display menu
	takeAction(p); //where the magic happens!

	system("Pause");
	return 0;

}

void showMenu() //menu
{
	cout << "1: Set Full Name" << endl;
	cout << "2: Set First Name" << endl;
	cout << "3: Set Middle Name" << endl;
	cout << "4: Set Last Name" << endl;
	cout << "5: Check First Name" << endl;
	cout << "6: Check Last Name" << endl;
	cout << "7: Print Name" << endl;

	return;
}

void takeAction(Person p) //The meat and potatos
{
	string first;
	string middle;
	string last;
	string fullName;
	char goAgain = ' ';

	do {
		int selection = 0;
		cout << "Make a selection: ";
		cin >> selection;

		switch (selection) {

		case 1: //set full name
			cout << "Enter first, middle, and last names" << endl;
			cin >> first;
			cin >> middle;
			cin >> last;
			p.setFName(first);
			p.setMName(middle);
			p.setLName(last);
			break;
		case 2: //set first name
			cout << "Enter first name" << endl;
			cin >> first;
			p.setFName(first);
			break;
		case 3: //set middle name
			cout << "Enter middle name" << endl;
			cin >> middle;
			p.setMName(middle);
			break;
		case 4: //set last name
			cout << "Enter last name" << endl;
			cin >> last;
			p.setLName(last);
			break;
		case 5: //get input to check against Person first name
			cout << "Enter first name to check against" << endl;
			cin >> first;
			p.checkFName(first);
			break;
		case 6: //get input to check against Person last name
			cout << "Enter last name to check against" << endl;
			cin >> last;
			p.checkLName(last);
			break;
		case 7: //print name
			p.printName();
			break;
		default: //prompt for new selection it original is selection out of range
			cout << "Make a selection" << endl;
			cin >> selection;
			break;
		}

		cout << "Make another selection? "; //loop the switch
		cin >> goAgain;

	} while (goAgain == 'y' || goAgain == 'Y'); //loop sentinel

	return;
}
