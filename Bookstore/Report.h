#pragma once
#include <vector>
#include <algorithm>
#include "Book.h"
#include "Interface.h"

/*
	Constructor creates vector of Books from Inventory file.
	Only exposed method is setMode which takes the operation the
	user wants and prints the results. If setMode argument is the same as
	mode, the result will be printed but no other operation will occur (i.e. sorting).
*/
enum Sort { Unsorted, Quantity, Date, Retail, Wholesale, RetailList, WholesaleList };

class Report: Interface{
	std::vector<Book> books;
	Sort mode;
	template <typename fT>
	void sort(fT get);
	void printInventory(Price(Book::*)() const);
public:
	Report();
	~Report();
	void setMode(Sort mode);
};

