#define _CRT_SECURE_NO_WARNINGS
#include "Inventory.h"

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

bool Inventory::findBook(string titleISBN) {
	for (curBook = books.begin(); curBook != books.end(); curBook++){
		if (titleISBN == curBook->getTitle() || titleISBN == curBook->getISBN()) {
			return true;
		}
	}
	return false;
}

Book Inventory::getCurBook(){
	return *curBook;
}

Book Inventory::deleteBook() {
	Book b;
	if (curBook != books.end()) {
		b = *curBook;
		books.erase(curBook);
	}
	return b;
}

Book Inventory::getBook() {
	Book b;
	string s;
	Price p;
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

	return b;
}

void Inventory::addBook() {
	pushBook(getBook());
}

void Inventory::editBook(Edit::Mode mode, string input){
	istringstream is(input);
	string str;
	Price p;
	Date d;
	int q;
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
		curBook->setWhole(p);
		break;
	case Edit::Wholesale:
		is >> p;
		curBook->setRetail(p);
		break;
	}

}
