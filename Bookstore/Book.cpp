//
// Created by Brandon Yost on 5/9/15.
//

#include "Book.h"

void Book::setISBN(uint ISBN) { this->ISBN = ISBN; }
uint Book::getISBN() { return ISBN; }

void Book::setTitle(string title) { this->title = title; }
string Book::getTitle() { return title; }

void Book::setAuthor(string author) { this->author = author; }
string Book::getAuthor() { return author; }

void Book::setPub(string publisher) { this->publisher = publisher; }
string Book::getPub() { return publisher; }

void Book::setWhole(Price wholesale) { this->wholesale = wholesale; }
Price Book::getWhole() { return wholesale; }

void Book::setRetail(Price retail) { this->retail = retail; }
Price Book::getRetail() { return retail; }

void Book::setQuant(int quantity) { this->quantity = quantity; }
int Book::getQuant() { return quantity; }

void Book::setDate(Date d) { dateAdded = d; }
Date Book::getDate() { return dateAdded; }