#include "dayType.h"
#include <string>
using namespace std;


//constructors
dayType::dayType() { currentDay = 0;}

dayType::dayType(int day){setDay(day);}

//Accessors
string dayType::getDay(){return DAYS_OF_THE_WEEK[currentDay];};

//Mutators
void dayType::setDay(int day)
{
	if(day >= 0 && day < NUMBER_OF_DAYS)
		currentDay = day;
	else //just need something to handle errors, I went with the simplest thing I could think of
		currentDay = 0;
}

void dayType::print()
{
	cout << DAYS_OF_THE_WEEK[currentDay] << endl;
}

string dayType::nextDay()
{
	return DAYS_OF_THE_WEEK[(currentDay + 1) % NUMBER_OF_DAYS];
}

string dayType::previousDay()
{
	return DAYS_OF_THE_WEEK[(currentDay + NUMBER_OF_DAYS - 1) % NUMBER_OF_DAYS];
}

string dayType::addDays(int numOfDays)
{
	return DAYS_OF_THE_WEEK[(currentDay + numOfDays) % NUMBER_OF_DAYS];
	}