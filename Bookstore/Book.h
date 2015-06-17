//
// Created by Brandon Yost on 5/9/15.


#ifndef BOOKSTORE_BOOK_H
#define BOOKSTORE_BOOK_H

#include "globals.h"
#include "Price.h"
#include "Date.h"
#ifndef REPORT_DRIVER
#include "Cashier.h"
#endif //REPORT_MODULE

#include <string>

using namespace std;

class Book {
	friend class Cashier;
private:
	string ISBN, title, author, publisher;
	Price wholesale, retail;
	int quantity;
public:
	//This allows the >> operator to input to a book directly
	//The book vector is still protected since they are private in the modules.
	Date dateAdded;
	void setISBN(string ISBN);
	string getISBN() const;

	void setTitle(string title);
	string getTitle() const;

	void setAuthor(string author);
	string getAuthor() const;

	void setPub(string publisher);
	string getPub() const;

	void setWhole(Price wholesale);
	Price getWhole() const;

	void setRetail(Price resale);
	Price getRetail() const;

	void setQuant(int quantity);
	int getQuant() const;

	void setDate(Date dateAdded);
	Date getDate() const;


	friend istream& operator>>(istream &input, Book &B);
	friend ostream& operator<<(ostream &output, const Book &B);

	#ifndef REPORT_DRIVER
	//friend void Cashier::decrementBookQuant(int, Book &);
	
	#endif //REPORT_DRIVER
};

#endif //BOOKSTORE_BOOK_H

