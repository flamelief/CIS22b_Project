//
// Created by Brandon Yost on 5/9/15.


#ifndef BOOKSTORE_BOOK_H
#define BOOKSTORE_BOOK_H

#include "globals.h"
#include "Price.h"
#include "Date.h"
#ifndef REPORT_DRIVER
//#include "Cashier.h"
#endif //REPORT_MODULE

#include <string>

using namespace std;

class Book {
	friend class Cashier;
private:
	string ISBN, title, author, publisher;
	int quantity;
public:
	Price wholesale, retail;
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

	void setRetail(Price retail);
	Price getRetail() const;

	void setQuant(int quantity);
	int getQuant() const;

	void setDate(Date dateAdded);
	Date getDate() const;

	Price getTotal() { return retail + retail * TAX; } // added here so that books can use this function

	friend istream& operator>>(istream &input, Book &B);
	friend ostream& operator<<(ostream &output, const Book &B);

	//friend void Cashier::decrementBookQuant(vector <Book> &);

	string getProperty(int);
	string toString(int);




	const static int ISB = 1,                  // the purpose of these static variables is for the ReportModule to decide which properties of Book do we want to display out
		BKTTLE = 2,
		AUTHNAME = 4,
		PUB = 8,
		DATE = 16,
		QUANT = 32,
		WCOST = 64,
		RET = 128,                    //it ended exactly at 8, so these values can be representated with 1 int
		EVERYTHING = 255;
	
};

#endif //BOOKSTORE_BOOK_H

