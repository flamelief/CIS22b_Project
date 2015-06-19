#pragma once
#include "Interface.h"
#include <sstream>

namespace Edit {
	enum  Mode { ISBN = 1, Title, Author, Publisher, Date, Quantity, Retail, Wholesale };
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
	void editBook(Edit::Mode, string);

	Book& getCurBook() const;
	bool findBook(string);
	void addBook();
	Book deleteBook();
	
};

