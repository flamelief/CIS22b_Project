#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"

void Book::setISBN(string ISBN) { 
	if (ISBN.empty()) throw InvalidISBN();
	else this->ISBN = ISBN; 
}
string Book::getISBN() { return ISBN; }

void Book::setTitle(string title) {
	if (title.empty()) throw InvalidTitle();
	else this->title = title; }
string Book::getTitle() { return title; }

void Book::setAuthor(string author) {
	if (author.empty()) throw InvalidAuthor();
	else this->author = author;
}
string Book::getAuthor() const { return author; }

void Book::setPub(string publisher) {
	if (publisher.empty()) throw InvalidPublisher();
	else this->publisher = publisher;
}
string Book::getPub() const { return publisher; }

void Book::setWhole(double wholesale) { 
	if (wholesale < 0) throw InvalidPrice();
	else this->wholesale = wholesale; }
double Book::getWhole() const { return wholesale; }

void Book::setRetail(double retail) {
	if (retail < 0) throw InvalidPrice();
	else this->retail = retail; }
double Book::getRetail() const { return retail; }

void Book::setQuant(int quantity) {
	if (quantity < 0) throw InvalidQuantity();
	else this->quantity = quantity;
}
int Book::getQuant() const { return quantity; }

void Book::setDate(Date d) { 
	if (!d.isValid()) throw InvalidDate();
	else dateAdded = d;
}
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

	output << "Wholesale Cost: " << fixed << setprecision(2) << B.wholesale << endl;
	output << "Retail Cost: " << fixed << setprecision(2) << B.retail;
	return output;
}

const char* InvalidPrice::what() const {
	return "Invalid price entered";
}

const char* InvalidDate::what() const {
	return "Invalid date entered";
}

const char* InvalidISBN::what() const {
	return "Empty ISBN field not allowed";
}

const char* InvalidTitle::what() const {
	return "Empty title field not allowed";
}

const char* InvalidAuthor::what() const {
	return "Empty author field not allowed";
}

const char* InvalidPublisher::what() const {
	return "Empty publisher field not allowed";
}

const char* InvalidQuantity::what() const {
	return "Invalid quantity entered";
}
