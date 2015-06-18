#pragma once
#include "Interface.h"

namespace Edit {
	enum  Mode { ISBN, Title, Author, Publisher, Date, Quantity, Retail, Wholesale };
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
	template <typename fT, class valT>
	inline void editBook(fT f, valT val);
	bool findBook(string);
	void addBook();
	void deleteBook();
	
};

