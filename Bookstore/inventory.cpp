#ifdef DEBUG 
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	int choice;
	cout << "|================================|" << endl;
	cout << "|      Serendipity Booksellers   |" << endl;
	cout << "|        Inventory Database      |" << endl;
	cout << "|                                |" << endl;
	cout << "|   1. Look Up A Book            |" << endl;
	cout << "|   2. Add a Book                |" << endl;
	cout << "|   3. Edit a Book's Record      |" << endl;
	cout << "|   4. Delete a Book             |" << endl;
	cout << "|   5. Return to the Main Menu   |" << endl;
	cout << "|                                |" << endl;
	cout << "|      Enter Your Choice:        | ";
	cin >> choice;


	while (!readChar(cInput) || (cInput < '1') || (cInput > '5')) {
		cout << "\nPlease enter a number between 1 and 5: ";
	}
	if (cInput == '1')
		lookUpBook();
	else if (cInput == '2')
		addBook();
	else if (cInput == '3')
		editBook();
	else if (cInput == '4')
		deleteBook();
	{
		cout << " Did not Enter the Given choices" << endl;
		system("pause");
	}