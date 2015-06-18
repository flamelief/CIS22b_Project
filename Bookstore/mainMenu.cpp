#ifdef DEBUG 
#include <iostream>
#include <iomanip>
#include <string>
#include "Report.h"
#include "InventoryModule.h"
#include "Interface.h"
#include "Cashier.h"
using namespace std;


// function for mainmenu screen display
void  printMain()
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

// function for report menu display
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
// function for inventory screen display
void printInventoryModule()
{
	cout << "|================================|\n";
	cout << "|     InventoryDatabase Module   |\n";
	cout << "|                                |\n";
	cout << "|  1. Look Up a Book             |\n";
	cout << "|  2. Add a Book                 |\n";
	cout << "|  3. Edit a Book's Record       |\n";
	cout << "|  4. Delete a Book              |\n";
	cout << "|  5. Return to the Main Menu    |\n";
	cout << "|                                |\n";
	cout << "|  Enter Your Choice: ";

}


/*Pseudo Code
-Initialize all the modules
-In a while loop, ask the user for which module they want to enter
- if they choose 1, then go into Cashier Module
- if they chooes 2, then go into InventoryDataBase Module
- if they choose 3, then go inside Report Module
- if they choose 4, then exit the program
*/
int main()
{



	//inline function
	void printMain();
	void printReportOptions();
	void printInventoryModule();

	int tempOption = 0;
	string command = "";

	do{
		printMain();
		getline(cin, command);

		tempOption = static_cast<int>(atoi(command.c_str()));



		if ((tempOption< 1) || (tempOption> 4))
		{
			cout << "Invalid Input, Please enter a number between 1 and 4: ";
			continue;
		}

		if (tempOption == 1){
			cout << endl << endl;
			//cashier module
		}
		else if (tempOption == 2){
			cout << endl << endl;
			printInventoryModule();
			getline(cin, command);
			int option = atoi(command.c_str());
			InventoryDatabaseModule* inv = new InventoryDatabaseModule();
			int tempOpt = 0;

		while ( tempOpt != 5 )
			{
				if (option == 1)
					inv->lookUpBook();
				else if (option == 2)
					inv->addBook();
				else if (option == 3)
					inv->editBook();
				else if (option == 4)
					inv->deleteBook();
				else if ( option == 5 ) 
				{
					cout << "u r stupid";
					break;
				}
			}
			Inventory Database Module
		}
		else if (tempOption == 3)
		{
			Report r("books2.txt");
			cout << endl << endl;
			printReportOptions();
			getline(cin, command);
			int option = atoi(command.c_str());
			Sort d = static_cast<Sort>(option);
			r.printInventory(d);
		}
		else if (tempOption == 4)
		{
			cout << "EXIT OUT" << endl << endl;
			break;
		}
	} while (tempOption != 4);
	// exitc
	return 0;
}
#endif //DEBUG