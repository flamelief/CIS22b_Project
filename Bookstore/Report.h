#pragma once
#include <vector>
#include <algorithm>
#include "Book.h"
#include "Interface.h"

class Book;

class Report: Interface{
	std::vector<Book*> books;
	bool (*Report::compare)(const Book*, const Book*);
public:
	Report();
	~Report();
	void printInventory();
	void setCompare();// Compare);
	bool (*Report::getCompare())(const Book*, const Book*);
	static bool compQuant(const Book *b1, const Book *b2);
	void sort();
};

