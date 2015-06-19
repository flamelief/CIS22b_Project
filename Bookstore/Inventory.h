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
	//template <typename fT, typename valT>
	//void editBook(fT f, valT val){
	//	if (curBook != books.end()) {
	//		((*curBook).*f)(val);
	//	}
	//}

	bool findBook(string);
	void addBook();
	Book deleteBook();
	
};

