#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;

//function prototypes
void displayMenu();
void makeSelection(int);
void createReport();
void readFile();
void initVectors();
void sortVectors();
void checkStock();
void sellAnItem();
void sellByName();
void sellByID();

//TEST FUNCTION PROTOTYPES START
int getInt(string);
void printInputPrompt(string);
//TEST FUNCTION PROTOTYPES END

//vectors for items
vector<int> itemID;
vector<string> itemName;
vector<int> piecesOrdered;
vector<int> piecesSold;
vector<int> numInStore;
vector<double> manufPrice;
vector<double> sellingPrice;

int main()
{	
	readFile(); //read input file
	initVectors(); //init empty vectors
	sortVectors(); //sort vectors
	displayMenu(); //display the main menu	


	cin.get();
	return 0;
}

void displayMenu() //show main menu
{
	int selection = 0;
	int number;

	system("CLS");

	cout << "Friendly Hardware Store" << endl;
	cout << "_______________________" << endl;
	cout << "1: Check if an item is in the store" << endl;
	cout << "2: Sell an Item" << endl;
	cout << "3: Print a report" << endl;
	cout << "9: Exit" << endl << endl;
	//cout << "Make a selection (1-3): ";
	//cin >> selection;
	selection = getInt("Enter a selection between 1 and 3 or 9 to exit");


	while (selection != 1 && selection != 2 && selection != 3 && selection != 9)
	{		
		cin.clear();

		cout << "\nThat is not a valid selection" << endl;
		cout << "Make a selection (1-3): ";
		cin >> selection;
	}

	makeSelection(selection);	
}

void makeSelection(int selection) //make a selection from the main menu
{
	switch (selection)
	{
		case 1:
			checkStock();
			break;
		case 2:
			sellAnItem();
			break;
		case 3:
			createReport();
			break;
		case 9:
			exit(1);
	/*	default:
			cout << "\nThat is not a valid selectionzz" << endl;
			displayMenu();*/
	}

	displayMenu();
}

void createReport() //create the output report
{
	ofstream outFile("Report.txt");

	outFile << "ItemID \tItemName \t pOrdered \t pInStore \t pSold \t manufPrice \t sellingPrice" << endl;
	//outFile << 4444 << "\tCircular Saw \t " << 1500 << "\t\t " << 1500 << "\t\t " << 140 << "\t   " << 450.99 << "\t      " << 125.99 << endl;

	for (int i = 0; i < itemName.size() - 1; i++)
	{
		//outFile << itemID[i] << "\t" << itemName[i] << " \t " << piecesOrdered[i] << "\t\t " << numInStore[i] << "\t\t " << piecesSold[i] << "\t   " << manufPrice[i] << "\t      " << sellingPrice[i] << endl;
		outFile << itemID[i] << "\t" << itemName[i] << "\t" << piecesOrdered[i] << "\t\t " << numInStore[i] << "\t\t " << piecesSold[i] << "\t" << manufPrice[i] << "\t" << sellingPrice[i] << endl;
	}


	outFile.flush();
	outFile.close();

	cout << "Report Created" << endl;
	cout << "Press any key to continue" << endl;
	cin.ignore(100000, '\n');
	cin.get();

}

void readFile() //read the input file and populate vectors
{
	ifstream inFile;
	inFile.open("inFile.txt");
	
	string tempString;
	int tempInt;
	double tempDouble;

	while (inFile.good() && !inFile.eof())
	{
		getline(inFile, tempString);
		tempInt = atoi(tempString.c_str());
		itemID.push_back(tempInt);


		getline(inFile, tempString);
		itemName.push_back(tempString);

		inFile >> tempInt;
		piecesOrdered.push_back(tempInt);

		inFile >> tempDouble;
		manufPrice.push_back(tempDouble);

		inFile >> tempDouble;
		sellingPrice.push_back(tempDouble);	

		inFile.ignore(100000, '\n');
		inFile.ignore(100000, '\n');
		tempString.clear();
	}
}

void initVectors() //set piecesInStore to numOrdered
{
	for (int i = 0; i < piecesOrdered.size(); i++)
	{
		numInStore.push_back(piecesOrdered[i]);
		piecesSold.push_back(0);
	}
}

void sortVectors() //sort the vectors
{
	for (int i = itemName.size() - 1; i > 0; i--)
	{
		string sTemp;
		int iTemp = 0;
		double dTemp = 0;

		for (int i = 0; i < itemName.size() - 1; i++)
		{
			if (itemName[i] > itemName[i + 1])
			{
				sTemp = itemName[i + 1];
				itemName[i + 1] = itemName[i];
				itemName[i] = sTemp;

				iTemp = itemID[i + 1];
				itemID[i + 1] = itemID[i];
				itemID[i] = iTemp;

				iTemp = piecesOrdered[i + 1];
				piecesOrdered[i + 1] = piecesOrdered[i];
				piecesOrdered[i] = iTemp;

				iTemp = numInStore[i + 1];
				numInStore[i + 1] = numInStore[i];
				numInStore[i] = iTemp;

				dTemp = manufPrice[i + 1];
				manufPrice[i + 1] = manufPrice[i];
				manufPrice[i] = dTemp;

				dTemp = sellingPrice[i + 1];
				sellingPrice[i + 1] = sellingPrice[i];
				sellingPrice[i] = dTemp;
			}
		}
	}
}

void checkStock() //check if an item is in the store
{
	string findMe;
	char searchAgain;

	do {
		system("CLS");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "What is the name of the item?\n";
		getline(cin, findMe);

		int pos = find(itemName.begin(), itemName.end(), findMe) - itemName.begin();

		if (pos > itemName.size() - 1 || pos < 0)
			cout << "\nItem not found" << endl;
		else
			cout << "\nItem Name: " << itemName[pos] << "\nItem ID: " << itemID[pos] << "\nNumber in Stock: " << numInStore[pos] << "\nCost Per Unit: " << sellingPrice[pos] << endl << endl;

		cout << "\nSearch for another Item? y/n: ";
		cin.get(searchAgain);

	} while (tolower(searchAgain) == 'y');

	displayMenu();
}

void sellAnItem() //sell an item menu
{
	int selection;

	system("CLS");

	selection = getInt("1: Sell Item by Name\n2: Sell Item by Item Id\n");

	switch (selection)
	{
		case 1:
			sellByName();
			break;
		case 2:
			sellByID();
			break;
		default:
			cout << "Error, that is not a valid selection. You will be returned to the main menu" << endl << endl;
	}
	system("PAUSE");
	displayMenu();
	//return; //return to makeSelection
}

//TEST-EXAMPLE START
int getInt(string message) {
	int input = 0;
	
	printInputPrompt(message);

	while (!(cin >> input)) {
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "\n\nYou may only input integers!" << endl << endl << endl;
		printInputPrompt(message);
	}

	return input;
}

void printInputPrompt(string message)
{
	cout << message << endl << endl
		<< "Input your selection: ";
}
//TEST-EXAMPLE END

void sellByName() //sell an item by name
{
	string itemToFind;
	char correct = ' ';
	char makeSale = ' ';
	double totalAmmount = 0;
	int numberToSell = 0;
	int pos = 0;
	bool found;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	system("CLS");

	do {		
		cout << "Enter the name of the item being sold" << endl;
		getline(cin, itemToFind);

		pos = find(itemName.begin(), itemName.end(), itemToFind) - itemName.begin();

		if (pos > itemName.size() - 1 || pos < 0)
		{
			cout << "\nThat is not a valid item. Please try again" << endl << endl;
			found = false;
		}
		else
			found = true;
		
		
	} while (!found);

	if (found)
	{
		cout << "\nItem Name: " << itemName[pos] << "\nItem ID: " << itemID[pos] << "\nNumber in Stock: " << numInStore[pos] << "\nCost Per Unit: " << sellingPrice[pos] << endl << endl;
		cout << "Is this the correct item? y/n: ";
		cin.get(correct);

		if (tolower(correct) != 'y')
			sellByName();
		else
		{
			cout << "\nHow many to sell? ";
			cin >> numberToSell;

			while (numberToSell <= 0 || numberToSell > numInStore[pos]) //here
			{
				cout << "That is not a valid ammount. Please enter a valid ammount" << endl;
				cin >> numberToSell;
			} //end while

			cout << "\nThe total Price of the sale will be: $" << sellingPrice[pos] * numberToSell << endl;
			cout << "Contiune with the sale? y/n: ";
			cin >> makeSale;

			if (tolower(makeSale) != 'y')
			{
				sellByName();
			}
			else
			{
				cout << "\nSale compleate\n" << endl;
				//cout << "Press enter to continue" << endl;

				piecesSold[pos] += numberToSell;
				numInStore[pos] -= numberToSell;


				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				//cin.get();
			}

		} //end else
	} //end if
		
	return; //return to sellAnItem
	
} //end function

void sellByID() //sell an item by item ID
{
	int itemToFind = 0;
	char correct = ' ';
	char makeSale = ' ';
	double totalAmmount = 0;
	int numberToSell = 0;
	int pos = 0;
	bool found;

	system("CLS");

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	do {
		itemToFind = getInt("Enter the ID of the item being sold");
		cout << endl;
		cin.clear();

		pos = find(itemID.begin(), itemID.end(), itemToFind) - itemID.begin();

		if (pos > itemID.size() - 1 || pos < 0)
		{
			found = false;
			cout << "That is not a valid item. Please try again" << endl;			
		}
		else
			found = true;

	} while (!found);

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (found)
	{
		cout << "Item Name: " << itemName[pos] << "\nItem ID: " << itemID[pos] << "\nNumber in Stock: " << numInStore[pos] << "\nCost Per Unit: " << sellingPrice[pos] << endl;
		cout << "\nIs this the correct item? y/n: ";
		cin.get(correct);

		if (tolower(correct) != 'y')
			sellByID();
		else
		{
			cout << "\nHow many to sell? ";
			cin >> numberToSell;

			while (numberToSell <= 0 || numberToSell > numInStore[pos]) //here
			{
				cout << "That is not a valid ammount. Please enter a valid ammount" << endl;;
				cin >> numberToSell;
			} //end while

			cout << "\nThe total Price of the sale will be: $" << sellingPrice[pos] * numberToSell << endl;
			cout << "Contiune with the sale? y/n: ";
			cin >> makeSale;

			if (tolower(makeSale) != 'y')
			{
				sellByID();
			}
			else
			{
				cout << "\nSale compleate" << endl;

				piecesSold[pos] += numberToSell;
				numInStore[pos] -= numberToSell;

				cin.ignore(numeric_limits<streamsize>::max(), '\n');

			}
		} //end else
	} //end if
	
	return; //return to sellAnItem
}

