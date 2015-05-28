#include <iostream>
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
}