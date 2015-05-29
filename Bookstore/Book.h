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
	string ISBN, title, author, publisher;
	Price wholesale, retail;
	Date dateAdded;
	int quantity;
public:
	void setISBN(string ISBN);
	string getISBN();

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

	friend istream& operator>>(istream &input, Book &B);
	friend ostream& operator<<(ostream &output, const Book &B);

};

#endif //BOOKSTORE_BOOK_H

