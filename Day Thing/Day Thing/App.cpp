#include "stdafx.h"
#include <iostream>
#include "dayType.h"
using namespace std;

int main()
{

	dayType someDay;

	 dayType testDayOne;
	 dayType testDayTwo(3);

	 testDayOne.print();
	 testDayTwo.print();

	 cout << "The day after " << testDayOne.getDay() << " is " << testDayOne.nextDay() << endl;
	 cout << "The day before " << testDayOne.getDay() << " is " << testDayOne.previousDay() << endl;
	 cout << "Five days after " << testDayOne.getDay() << " it will be " << testDayOne.addDays(5) << endl;


	cin.get();
	return 0;
}