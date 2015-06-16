#ifdef DEBUG 
#include <iostream>
#include <iomanip>
#include <string>
#include "Report.h"
#include "InventoryModule.h"
#include "Cashier.h"


using namespace std;



void printMain()
{
	cout << "|================================|\n";
	cout << "|    Serendipity Booksellers     |\n";
	cout << "|           Main Menu            |\n";
	cout << "|  1. Cashier Module             |\n";
	cout << "|  2. Inventory Database Module  |\n";
	cout << "|  3. Report Module              |\n";
	cout << "|  4. Exit Program               |\n";
	cout << "|                                |\n";
	cout << "|  Enter Your Choice: ";
}

void printReportOptions()
{
	cout << "|================================|\n";
	cout << "|    Serendipity Booksellers     |\n";
	cout << "|             Reports            |\n";
	cout << "|  1. Inventory Listing          |\n";
	cout << "|  2. Inventory Wholesale Value  |\n";
	cout << "|  3. Inventory Retail Value     |\n";
	cout << "|  4. Listing by Quantity        |\n";
	cout << "|  5. Listing by Cost            |\n";
	cout << "|  6. Listing by Age             |\n";
	cout << "|  7. Return to Main Menu        |\n";
	cout << endl;
	cout << "|  Enter Your Choice: ";
}

int main()
{

	/*Pseudo Code
	-Initialize all the modules
	-In a while loop, ask the user for which module they want to enter
	- if they choose 1, then go into Cashier Module
	- if they chooes 2, then go into InventoryDataBase Module
	- if they choose 3, then go inside Report Module
	- if they choose 4, then exit the program
	*/
	//inline function
	void printMain();
	void printReportOptions();



	char cInput;
	string command = "";
	do{
		printMain();
		getline(cin, command);
		while ((cInput < '1') || (cInput > '4'))
			cout << "Invalid Input, Please enter a number between 1 and 4: ";
		if (cInput == '1'){
			cout << endl << endl;
			//cashier module
		}
		else if (cInput == '2'){
			cout << endl << endl;
			//Inventory Database Module
		}
		else if (cInput == '3')
		{
			Report r("books2.txt");
			cout << endl << endl;
			printReportOptions();
			getline(cin, command);
			int option = atoi(command.c_str());
			Sort d = static_cast<Sort>(option);
			r.printInventory(d);



		}
		else if (cInput = '4')
			cout << endl << endl;
	} while (cInput != '4');
	// exit
	return 0;
}
#endif //DEBUG