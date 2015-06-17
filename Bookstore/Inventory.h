#pragma once
#include "Interface.h"

namespace Edit {
	enum  Mode { ISBN, Author, Date, Retail, Wholesale, RetailList, WholesaleList };
}

class Inventory :
	private Interface
{
	Book getBook();
	static std::vector<Book>::iterator curBook;
public:
	Inventory();
	Inventory(string filename);
	~Inventory();
	bool findBook(string);
	void deleteBook();
	template <typename fT, class valT>
	void editBook(fT, valT);
	void addBook();
};

