#pragma once
#include "Interface.h"

/*
Constructor creates vector of Books from Inventory file.
Only exposed method is printInventory which takes the operation the
user wants and prints the results. If printInventory argument is the same as
mode, the result will be printed only. Only exposed methods are the constructor
and printInventory.
*/

/*
Specifies how Inventory information is displayed.
*/
namespace Sort {
	enum Mode { Unsorted=1, Quantity, Date, Retail, Wholesale, RetailList, WholesaleList };
}

class Report : private Interface{
	Report(const Report&);
	Report& operator=(Report&);
	Interface::books;
	Sort::Mode mode;
	template <typename fT>
	void sort(fT get);
public:
	/*
	Calls Interface constructor and sets mode to Unsorted.
	*/
	Report(string fileName);
	Report();
	~Report();
	/*
	Prints the Inventory as specified by mode. Book vector is altered if 
	specified mode does not equal current mode and mode is not RetailList or WholesaleList.
	*/
	void printInventory(Sort::Mode mode);
	void printInventory();
};





