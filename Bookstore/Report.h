#pragma once
#include "Interface.h"

/*
Constructor creates vector of Books from Inventory file.
Only exposed method is printInventory which takes the operation the
user wants and prints the results. If printInventory argument is the same as
mode, the result will be printed only.
*/

enum Sort { Unsorted, Quantity, Date, Retail, Wholesale, RetailList, WholesaleList };

class Report : Interface{
	Interface::books;
	Sort mode;
	template <typename fT>
	void sort(fT get);
public:
	Report(string fileName);
	Report();
	~Report();
	void printInventory(Sort mode);
	void printInventory();
};





