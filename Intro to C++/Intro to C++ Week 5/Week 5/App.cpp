/////////////////////////////////////////////////////////////////////////////////////////////////
//Program Name: Score Sorter
//Program Discription: Sort a list of values from a file into score ranges
//Programmed By: Bill Fulton of Baker College
//Course: CS217a Online - C++ Programming
//Date: 12 April 2016 - Spring 2016
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include <fstream>
#include<string>

using namespace std;

int main()
{
	string temp; //value taken from file
	int number = 0; //file value converted to an integer
	int counter = 0; //index iterator for array
	int input[26]; //array of values from file
	int scoresInRange[8]{ 0 }; //array to hold the number of scores in the specific ranges
	string scoreRanges[8] {"0 - 24: ", "25 - 49: ", "50 - 74: ", "75 - 99: ", "100 - 124: ", "125 - 149: ",
		"150 - 174: ", "175 - 200: "}; //array with score ranges for output

	ifstream scores; //new filestream object
	scores.open("testData.txt"); //open testData.txt file - contains the required input

	if (scores.fail()) //if unable to open file, display an error and exit
	{
		cerr << "Error" << endl;
		exit(1);
	} //end if


	while (!scores.eof() && scores.good()) //while not at the end of the file and no filestream errors
	{
		getline(scores, temp, ','); //get a line from the file - delimit at comma

		number = atoi(temp.c_str()); //convert file input string to an int
		input[counter] = number; //add the number to an array

		counter++; //itterate the counter for array index
	} //end while - start at line 25
	
	scores.close(); //close input file

	for (int i = 0; i < 26; i++) //iterate over the items in the input array and place them into their 
	{								// correct score range
		if (input[i] >= 0 && input[i] <= 24)
			scoresInRange[0] += 1;
		else if (input[i] >= 25 && input[i] <= 49)
			scoresInRange[1] += 1;
		else if (input[i] >= 50 && input[i] <= 74)
			scoresInRange[2] += 1;
		else if (input[i] >= 75 && input[i] <= 99)
			scoresInRange[3] += 1;
		else if (input[i] >= 100 && input[i] <= 124)
			scoresInRange[4] += 1;
		else if (input[i] >= 125 && input[i] <= 149)
			scoresInRange[5] += 1;
		else if (input[i] >= 150 && input[i] <= 174)
			scoresInRange[6] += 1;
		else if (input[i] >= 175 && input[i] <= 200)
			scoresInRange[7] += 1;
	} //end for

	for (int i = 0; i < 8; i++) //output the number of scores in the ranges
		cout << scoreRanges[i] << scoresInRange[i] << endl;
	
	cin.get();
	return 0;
}
