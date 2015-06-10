#pragma once
#include <vector>
#include <algorithm>
#include "Book.h"
#include "Interface.h"

enum Sort { Unsorted, Quantity, Date, Retail, Wholesale };

class Report: Interface{
	std::vector<Book> books;
	Sort mode;
	template <typename fT>
	void sort(fT get);
public:
	Report();
	~Report();
	void printInventory();
	void setMode(Sort mode);
};

