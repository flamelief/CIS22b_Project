#define _CRT_SECURE_NO_WARNINGS
#include "Inventory.h"
//vector of cooks
vector<Book>::iterator Inventory::curBook;
Inventory::Inventory(string filename) : Interface(filename)
{
	curBook = books.end();
}

Inventory::Inventory() {
	curBook = books.end();
}

Inventory::~Inventory()
{
}
// function to look up book
bool Inventory::findBook(string titleISBN) {
	for (curBook = books.begin(); curBook != books.end(); curBook++){
		if (titleISBN == curBook->getTitle() || titleISBN == curBook->getISBN()) {
			return true;
		}
	}
	return false;
}

// function to delete book
Book Inventory::deleteBook() {
	Book b;
	if (curBook != books.end()) {
		b = *curBook;
		books.erase(curBook);
	}
	return b;
}
// function to cout book's data
Book Inventory::getBook() {
	Book b;
	string s;
	double p;
	Date d;
	int q;
	cout << "ISBN: ";
	getline(cin, s);
	b.setISBN(s);
	cout << "Title: ";
	getline(cin, s);
	b.setTitle(s);
	cout << "Author: ";
	getline(cin, s);
	b.setAuthor(s);
	cout << "Publisher: ";
	getline(cin, s);
	b.setPub(s);
	cout << "Date Added: ", cin >> d;
	b.setDate(d);
	cout << "Quantity on hand: ", cin >> q;
	b.setQuant(q);
	cout << "Wholesale cost: ", cin >> p;
	b.setWhole(p);
	cout << "Retail cost: ", cin >> p;
	b.setRetail(p);
	cin.get();
	return b;
}

// function to add book
void Inventory::addBook() {
	try{
		Book temp = getBook();
		for (vector<Book>::iterator it = books.begin(); it != books.end(); it++){
			//Allow for duplicate titles but not ISBN's
			if (it->getISBN() == temp.getISBN()) {
				cout << "\nBook already in library\n\n";
				return;
			}
		}
		pushBook(temp);
		cout << "\nAdded book:\n\n" << temp << endl << endl;
	}
	catch (exception &e){
		cout << endl << e.what() << endl << endl;
	}
}

Book& Inventory::getCurBook() const { return *curBook; }

// function to edit book
void Inventory::editBook(Edit::Mode mode, string input){
	istringstream is(input);
	string str;
	double p = 0;
	Date d;
	int q;
	try{
		switch (mode){
		case Edit::ISBN:
			curBook->setISBN(input);
			break;
		case Edit::Title:
			curBook->setTitle(input);
			break;
		case Edit::Author:
			curBook->setAuthor(input);
			break;
		case Edit::Publisher:
			curBook->setPub(input);
			break;
		case Edit::Date:
			is >> d;
			curBook->setDate(d);
			break;
		case Edit::Quantity:
			q = atoi(input.c_str());
			curBook->setQuant(q);
			break;
		case Edit::Retail:
			is >> p;
			curBook->setRetail(p);
			break;
		case Edit::Wholesale:
			is >> p;
			curBook->setWhole(p);
			break;
		}
	}
	catch(exception& e){
		cout << endl << e.what() << endl << endl;
	}

}
