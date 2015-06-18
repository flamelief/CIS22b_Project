#ifdef DEBUG 
#include <iostream>
#include <iomanip>
#include <string>
#include "Report.h"
#include "Inventory.h"
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
	cout << "|==================================|\n";
	cout << "|    Serendipity Booksellers       |\n";
	cout << "|             Reports              |\n";
	cout << "|  1. Inventory Listing            |\n";
	cout << "|  2. Listing by Quantity          |\n";
	cout << "|  3. Listing by Age               |\n";
	cout << "|  4. Inventory by Retail Value    |\n";
	cout << "|  5. Inventory by Wholesale Value |\n";
	cout << "|  6. Retail Value Listing         |\n";
	cout << "|  7. Wholesale Value Listing      |\n";
	cout << "|  8. Return to Main Menu          |\n";
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
	cout << "|  3. Return to the Main Menu    |\n";
	cout << "|                                |\n";
	cout << "|  Enter Your Choice: ";

}

void printInventoryFound()
{
	cout << "|================================|\n";
	cout << "|     InventoryDatabase Module   |\n";
	cout << "|           Book Found           |\n";
	cout << "|                                |\n";
	cout << "|     1. Edit Book               |\n";
	cout << "|     2. Delete Book             |\n";
	cout << "|     3. Return to Main Menu     |\n";
	cout << "|                                |\n";
	cout << "|  Enter Your Choice: ";
}

void printInventoryEdit()
{
	cout << "|================================|\n";
	cout << "|    InventoryDatabase Module    |\n";
	cout << "|                                |\n";
	cout << "|  1. Edit ISBN                  |\n";
	cout << "|  2. Edit Title                 |\n";
	cout << "|  3. Edit Author                |\n";
	cout << "|  4. Edit Publisher             |\n";
	cout << "|  5. Edit Date Added            |\n";
	cout << "|  6. Edit Quantity              |\n";
	cout << "|  7. Edit Retail Price          |\n";
	cout << "|  8. Edit Wholesale Price       |\n";
	cout << "|  9. Return to Inventory Menu   |\n";
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
			//Cashier menu("books2.txt");
			//menu.printCashierMenu();
		}
		else if (tempOption == 2){
			cout << endl << endl;
			printInventoryModule();
			Inventory i("books2.txt");
			getline(cin, command);
			int option = atoi(command.c_str());
			if (option == 1) { //Finding Book
				cout << "\nEnter book to find: ";
				string s;
				getline(cin, s);
				if (i.findBook(s)) {
					printInventoryFound();
					getline(cin, command);
					option = atoi(command.c_str());
					if (option == 1){
						printInventoryEdit();
						getline(cin, command);
						option = atoi(command.c_str());
						if (option >= Edit::ISBN && option <= Edit::Wholesale) {
							cout << "\nEnter new book info: ";
							getline(cin, s);
							i.editBook(static_cast<Edit::Mode>(option), s);
						}
					}
					else if(option == 2){
						i.deleteBook();
						cout << "\nBook deleted\n\n";
					}
				}
				else cout << "\n\nBook not found\n\n";
			}
			else if (option == 2){
				cout << "\nEnter book to add: \n";
				i.addBook();
				cin.get();
			}

			
		}
		else if (tempOption == 3)
		{
			Report r("books3.txt");
			cout << endl << endl;
			printReportOptions();
			getline(cin, command);
			int option = atoi(command.c_str());
			if (option >= Sort::Unsorted && option <= Sort::WholesaleList) {
				r.printInventory(static_cast<Sort::Mode>(option));
				cout << endl;
			}
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