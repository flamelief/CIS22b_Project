#pragma once
#include <vector>
#include <algorithm>
#include "Book.h"
#include "Interface.h"

/*
	Constructor creates vector of Books from Inventory file.
	Only exposed method is printInventory which takes the operation the
	user wants and prints the results. If printInventory argument is the same as
	mode, the result will be printed only.
*/
enum Sort { Unsorted, Quantity, Date, Retail, Wholesale, RetailList, WholesaleList };

class Report: Interface{
	std::vector<Book> books;
	Sort mode;
	template <typename fT>
	void sort(fT get);
public:
	Report();
	~Report();
	void printInventory(Sort mode);
};

