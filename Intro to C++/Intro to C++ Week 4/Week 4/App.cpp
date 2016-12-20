#include <iostream>
#include <string>

using namespace std;

//function prototypes
void getData();
void calculateTaxableIncome(string, double, double, int);
double taxAmount(double);
void displayTax(double);

int main()
{
	char goAgain; //variable required for do/while
	do {
		
		system("CLS"); //clear console on program repeat

		getData(); //call getData function

		cout << "Do you want to run the program again?" << endl; //prompt for program repeat
		cin >> goAgain;

	} while (tolower(goAgain) == 'y'); //if user enters y, loop to line 15

	system("PAUSE"); //keep console open 
	return 0;
} //end main

void getData()
{
	string maritalStatus = " ";
	double grossIncome = 0;
	double pensionFundPercent = 0;
	int numberOfChildren = 0;
	

	cout << "What is your marital status? married or single?" << endl; //prompt for marital status
	cin >> maritalStatus;
		

	if (tolower(maritalStatus[0]) == 'm') //if married
	{		
		cout << "How many children do you have that are under the age of 14?" << endl; //ask for number of children under 14
		cin >> numberOfChildren;
	}

	cout << "What is your gross income?" << endl << "note: if you are married, enter the combined income of you and your spouse." << endl; //prmpt for gross income
	cin >> grossIncome;


	cout << "What percent of your gross income (up to 6%) did you put in your pension fund?" << endl; //prompt for pension funcd contribution
	cin >> pensionFundPercent;
		

	while(pensionFundPercent > 6 || pensionFundPercent < 0) //ensure pension fund input in range
	{
		cout << "You can contribute a miximum of 6% to your pension fund each year. Please enter a valid number (up to 6%)" << endl; //if not, reprompt
		cin >> pensionFundPercent;		
	}

	calculateTaxableIncome(maritalStatus, grossIncome, pensionFundPercent, numberOfChildren); //call to calculateTaxableIncome with the required variabls from user input

}

void calculateTaxableIncome(string maritalStatus, double grossIncome, double pensionFundPercent, int numberOfChildren)
{
	int SINGLE_EXEMPT = 4000; //single tax exemption constant
	int MARRIED_EXEMPT = 7000; //married tax exemption constant
	double pensionFundAmmout;
	double taxableIncome;

	pensionFundAmmout = grossIncome * (pensionFundPercent / 100); //calculate ammout added to pension fund

	if (tolower(maritalStatus[0]) == 'm')
		taxableIncome = grossIncome - (pensionFundAmmout + MARRIED_EXEMPT + (numberOfChildren * 1500) + 3000); //calculate married taxable income

	else
		taxableIncome = grossIncome - (pensionFundAmmout + SINGLE_EXEMPT + 1500); //calculate single taxable income

	displayTax(taxableIncome); //
}

void displayTax(double taxableIncome)
{

	if (taxableIncome <= 0) //display appropriate message if taxable income is below the taxable level (a negative number)
		printf("Your taxable income of $%.2f is below the taxable level. \nYour Federal Tax is $0.00\n\n", taxableIncome);
	else  //else display the taxable income and tax ammout
	{
		printf("\nCalculating your Federal Tax based on your taxable income of: $%.2f\n\n", taxableIncome);
		double federalTaxAmount = taxAmount(taxableIncome); //call to taxAmount function
		printf("Your Federal Tax is: $%.2f\n\n", federalTaxAmount);
	}
}

double taxAmount(double taxableIncome)
{
	double overIncome;
	double federalTax;

	if (taxableIncome >= 0 && taxableIncome <= 15000) //tax rate between 0 and 15000 taxable income
		federalTax = taxableIncome * .15;
	else if (taxableIncome >= 15001 && taxableIncome <= 40000) //tax rate between 15001 and 40000 taxable income
	{
		overIncome = (taxableIncome - 15000) * .25; //calculate amount of income above 15000
		federalTax = 2250 + overIncome;
	}
	else if (taxableIncome > 40000) //tax rate above 40000 taxable income
	{
		overIncome = (taxableIncome - 40000) * .35; //calculate amount of income above 40000
		federalTax = 8460 + overIncome;
	}

	return federalTax;
}