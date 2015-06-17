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

void Inventory::deleteBook() {
	if (curBook != books.end()) {
		books.erase(curBook);
	}
}

template <typename fT, class valT>
void Inventory::editBook(fT, valT) {
	curBook->(*ft)(valT);
}

Book Inventory::getBook() {
	Book b;
	string s;
	Price p;
	Date d;
	int q;
	cout << "Title: ", cin >> s;
	b.setTitle(s);
	cout << "Author: ", cin >> s;
	b.setAuthor(s);
	cout << "Publisher: ", cin >> s;
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

