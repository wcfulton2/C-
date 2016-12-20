#ifndef DAYTYPE_H
#define DAYTYPE_H

#include <string>
#include <iostream>
using namespace std;

class dayType
{
public:
	//constructors
	dayType();
	dayType(int);

	//Accessors
	string getDay();
	//Mutators
	void setDay(int);

	void print();
	string nextDay();
	string previousDay();
	string addDays(int);

private:
	int currentDay;
	const int NUMBER_OF_DAYS = 7;
	string DAYS_OF_THE_WEEK[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
};

#endif
