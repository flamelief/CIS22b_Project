#pragma once
#include "Interface.h"

class Inventory :
	private Interface
{
	Book getBook();
	std::vector<Book>::iterator curBook;
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

