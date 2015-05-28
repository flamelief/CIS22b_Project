//
// Created by Brandon Yost on 5/9/15.


#ifndef BOOKSTORE_BOOK_H
#define BOOKSTORE_BOOK_H

#include "globals.h"
#include "Price.h"
#include "Date.h"

#include <string>

using namespace std;

class Book {
private:
	uint ISBN;
	string title, author, publisher;
	Price wholesale, retail;
	Date dateAdded;
	int quantity;
public:
	void setISBN(uint ISBN);
	uint getISBN();

	void setTitle(string title);
	string getTitle();

	void setAuthor(string author);
	string getAuthor();

	void setPub(string publisher);
	string getPub();

	void setWhole(Price wholesale);
	Price getWhole();

	void setRetail(Price resale);
	Price getRetail();

	void setQuant(int quantity);
	int getQuant();

	void setDate(Date dateAdded);
	Date getDate();
};

#endif //BOOKSTORE_BOOK_H

