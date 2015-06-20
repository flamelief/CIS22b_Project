#define _CRT_SECURE_NO_WARNINGS
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

// function for inventory  found
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
//function for inventory edit
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

int getOption(){
	string option;
	getline(cin, option);
	return atoi(option.c_str());
}

/*Pseudo Code
-Initialize all the modules
-In a while loop, ask the user for which module they want to enter
- if they choose 1, then go into Cashier Module
- if they chooes 2, then go into InventoryDataBase Module
- if they choose 3, then go inside Report Module
- if they choose 4, then exit the program
*/
int main(int argc, char* argv[])
{

	//inline function
	string filename = "books.txt";
	if (argc == 2) {
		filename = argv[1];
	}
	void printMain();
	void printReportOptions();
	void printInventoryModule();

	int tempOption = 0;
	string command;

	do{
		printMain();
		tempOption = getOption();
		// for invalid input numbers/choices
		if ((tempOption< 1) || (tempOption> 4))
		{
			cout << "Invalid Input, Please enter a number between 1 and 4: ";
			continue;
		}
		// option 1: cashier module and function call
		if (tempOption == 1){
			cout << endl << endl;
			//cashier module
			Cashier menu(filename);
		}
		// option 2: call inventory module function 
		else if (tempOption == 2){
			cout << endl << endl;
			printInventoryModule();
			Inventory i(filename);
			int option = getOption();
			if (option == 1) { //Finding Book
				cout << "\nEnter book to find: ";
				string s;
				getline(cin, s);
				if (i.findBook(s)) {
					cout <<i.getCurBook() << endl << endl;
					printInventoryFound();
					option = getOption();
					// option to edit inventory
					if (option == 1){
						printInventoryEdit();
						option = getOption();

						if (option >= Edit::ISBN && option <= Edit::Wholesale) {
							cout << "\nEnter new book info: ";
							getline(cin, s);
							i.editBook(static_cast<Edit::Mode>(option), s);
							cout << i.getCurBook() << endl << endl;
						}
					}
					//option to delete book
					else if(option == 2){
						i.deleteBook();
						cout << "\nBook deleted\n\n";
					}
				}
				else cout << "\n\nBook not found\n\n";
			}
			// option to add book
			else if (option == 2){
				cout << "\nEnter book to add: \n";
				i.addBook();
			}

			
		}
		// option: report module
		else if (tempOption == 3)
		{
			Report r(filename);
			cout << endl << endl;
			printReportOptions();
			int option = getOption();
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