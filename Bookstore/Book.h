
#ifndef BOOKSTORE_BOOK_H
#define BOOKSTORE_BOOK_H

#include "globals.h"
#include "Date.h"
#ifndef REPORT_DRIVER
#endif //REPORT_MODULE

#include <string>

using namespace std;

class Book {
	friend class Cashier;
private:
	string ISBN, title, author, publisher;
	Date dateAdded;
	double wholesale, retail;
	int quantity;
public:
	void setISBN(string ISBN);
	string getISBN();

	void setTitle(string title);
	string getTitle();

	void setAuthor(string author);
	string getAuthor() const;

	void setPub(string publisher);
	string getPub() const;

	void setWhole(double wholesale);
	double getWhole() const;

	void setRetail(double retail);
	double getRetail() const;

	void setQuant(int quantity);
	int getQuant() const;

	void setDate(Date dateAdded);
	Date getDate() const;

	
	double getTotal() { return  retail; } // added here so that books can use this function

	friend istream& operator>>(istream &input, Book &B);
	friend ostream& operator<<(ostream &output, const Book &B);
};

class InvalidPrice : public exception
{
	virtual  const char* what() const throw();
};

class InvalidDate : public exception
{
	virtual  const char* what() const throw();
};

class InvalidISBN : public exception
{
	virtual  const char* what() const throw();
};

class InvalidTitle : public exception
{
	virtual  const char* what() const throw();
};

class InvalidAuthor : public exception
{
	virtual  const char* what() const throw();
};

class InvalidPublisher : public exception
{
	virtual  const char* what() const throw();
};

class InvalidQuantity : public exception
{
	virtual  const char* what() const throw();
};

#endif //BOOKSTORE_BOOK_H
