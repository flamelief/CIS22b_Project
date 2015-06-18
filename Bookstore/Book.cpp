#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"

void Book::setISBN(string ISBN) { this->ISBN = ISBN; }
string Book::getISBN() { return ISBN; }

void Book::setTitle(string title) { this->title = title; }
string Book::getTitle() { return title; }

void Book::setAuthor(string author) { this->author = author; }
string Book::getAuthor() const { return author; }

void Book::setPub(string publisher) { this->publisher = publisher; }
string Book::getPub() const { return publisher; }

void Book::setWhole(Price wholesale) { this->wholesale = wholesale; }
Price Book::getWhole() const { return wholesale; }

void Book::setRetail(Price retail) { this->retail = retail; }
Price Book::getRetail() const { return retail; }

void Book::setQuant(int quantity) { this->quantity = quantity; }
int Book::getQuant() const { return quantity; }

void Book::setDate(Date d) { dateAdded = d; }
Date Book::getDate() const { return dateAdded; }

istream& operator>>(istream &input, Book &B){
	input.ignore(256, ':'), input.get();
	getline(input, B.ISBN);
	input.ignore(256, ':'), input.get();
	getline(input, B.title);
	input.ignore(256, ':'), input.get();
	getline(input, B.author);
	input.ignore(256, ':'), input.get();
	getline(input, B.publisher);
	input.ignore(256, ':'), input.get();
	input >> B.dateAdded;
	input.ignore(256, ':'), input.get();
	input >> B.quantity;
	input.ignore(256, ':'), input.get();
	input >> B.wholesale;
	input.ignore(256, ':'), input.get();
	input >> B.retail;
	return input;
}

ostream& operator<<(ostream &output, const Book &B){
	output << "ISBN: " << B.ISBN << endl;
	output << "Title: " << B.title << endl;
	output << "Author: " << B.author << endl;
	output << "Publisher: " << B.publisher << endl;
	output << "Date Added: " << B.dateAdded << endl;
	output << "Quantity On Hand: " << B.quantity << endl;
	output << "Wholesale Cost: " << B.wholesale << endl;
	output << "Retail Cost: " << B.retail;
	return output;
}

//bool compQuant(const Book &b1, const Book &b2) { return b1.getQuant() > b2.getQuant(); }
