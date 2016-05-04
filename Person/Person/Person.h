#pragma once

#include <iomanip>

#include <iostream>
#include <string>

using namespace std;

class Person
{

public:
	//mutators
	void setFName(string inputFName);
	void setMName(string inoutMName);
	void setLName(string inputLName);
	
	//accessors
	void printName();
	void checkFName(string inputFName);
	void checkLName(string inputLName);

	//constructors
	Person();
	Person(string inputFName, string inputMName, string inputLName);

private:
	string fName;
	string mName;
	string lName;
	string fullName;

	string compileName(string fName, string mName, string lName); //local function

};

inline Person::Person(){} // default constructor

inline Person::Person(string inputFName, string inputMName, string inputLName) //overload to instantiate with a given name
{
	fName = inputFName;
	mName = inputMName;
	lName = inputLName;

	compileName(fName, mName, lName);
}

inline void Person::setFName(string inputFName) //set first name
{
	fName = inputFName;
}

inline void Person::setMName(string inputMName) //set middle name
{
	mName = inputMName;
}

inline void Person::setLName(string inputLName) //set last name
{
	lName = inputLName;
}

inline void Person::printName() //compile first, middle, and last names into a single string and ouput said string
{
	compileName(fName, mName, lName);
	cout << fullName << endl;
}

inline void Person::checkFName(string inputFName) //compare first name again input
{
	if (fName == inputFName)
	{
		cout << "The match" << endl;
	}
	else
	{
		cout << "They do not match" << endl;
	}
}

inline void Person::checkLName(string inputLName) //compare last name against input
{
	if (lName == inputLName)
	{
		cout << "The match" << endl;
	}
	else
	{
		cout << "The do not match" << endl;
	}
}

inline string Person::compileName(string fName, string mName, string lName) //local function to compile name
{
	if (mName == "") {
		fullName = fName + " " + lName;
	}
	else {
		fullName = fName + " " + mName + " " + lName;
	}
	return fullName;
}


