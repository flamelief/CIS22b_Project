#ifdef DEBUG 
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	int choice;
	cout << "Serendipity Booksellers" << endl;
	cout << "  Inventory Database   " << endl;
	cout << endl;
	cout << "1. Look Up A Book" << endl;
	cout << "2. Add a Book" << endl;
	cout << "3. Edit a Book's Record" << endl;
	cout << "4. Delete a Book" << endl;
	cout << "5. Return to the Main Menu" << endl;
	cout << endl;
	cout << "Enter Your Choice:";
	cin >> choice;

	if (choice == 1)

	else if (choice == 2)

	else if (choice == 3)

	else if (choice == 4)

	else if (choice == 5)

	else
	{
		cout << " Did not Enter the Given choices" << endl;
		system("pause");
	}

/*Pseudo Code
-Initialize all the modules
-In a while loop, ask the user for which module they want to enter
- if they choose 1, then go into Cashier Module
- if they chooes 2, then go into InventoryDataBase Module
- if they choose 3, then go inside Report Module
- if they choose 4, then exit the program
*/

	char cInput;
	do{
		cout << "|================================|\n";
		cout << "|    Serendipity Booksellers     |\n";
		cout << "|           Main Menu            |\n";
		cout << "|  1. Cashier Module             |\n";
		cout << "|  2. Inventory Database Module  |\n";
		cout << "|  3. Report Module              |\n";
		cout << "|  4. Exit Program               |\n";
		cout << "|                                |\n";
		cout << "|  Enter Your Choice: ";
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
		else if (cInput == '3'){
			cout << endl << endl;
			//Report Module
		}
		else if (cInput = '4')
			cout << endl << endl;
	} while (cInput != '4');
	// exit
	return 0;
}
#endif //DEBUG