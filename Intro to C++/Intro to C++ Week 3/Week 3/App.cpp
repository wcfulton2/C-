/////////////////////////////////////////////////////////////////////////////////////////////////
//Program Name: Palindorme Finder
//Program Discription: Asks the user to input a word and determines if it is a palindorme or not
//Programmed By: Bill Fulton of Baker College
//Course: CS217a Online - C++ Programming
//Date: 01 April 2016 - Spring 2016
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string);

int main()
{
	string input;
	bool palindrome;
	char goAgain;
	
	do {
		system("CLS"); //clear screen after each loop

		cout << "This program will determine if an entered word is a palindrome." << endl << endl;
		cout << "Enter a word to test:" << endl; //propt user to enter a word to test
		cin >> input;
		cout << endl; //line break to improve user readability

		palindrome = isPalindrome(input); //call the isPalindrome function passing the input argument. Assign the boolean result to the palidorome variable

		if (palindrome) //if the word was a palidrome state as such
			cout << "This word is a palindrome." << endl << endl;
		else
			cout << "This word is not a palindrome." << endl << endl; //if the word was not a palindrome state as such.

		cout << "Go Again? y/n" << endl; //ask the user if they wish to re-run the program
		cin >> goAgain; //get char input and assign it to the goAgain variable

	} while(tolower(goAgain) == 'y'); //while the input was 'y', repeat - ignore case - loop to line 13

	cout << "\nThank you for using this program!" << endl; //end of program execution output

	system("PAUSE"); //keep window open until user hits a key
}

bool isPalindrome(string input) //isPalindrome function - 1 string argument - boolean return type
{
	int length = input.length(); //set the length of the input string to the length int variable

	for (int i = 0; i < length / 2; i++) // for loop to iterate through the first half of the word
		if (tolower(input[i]) != tolower(input[length - 1 - i]))	 //compare the letters in the first half of the word to the letters in the last half - ignore case
			return false; //if a pair of ltters do not match, return false
	
		return true; //if all letters mach, return true
}