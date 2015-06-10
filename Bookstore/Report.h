#pragma once
#include <vector>
#include <algorithm>
#include "Book.h"
#include "Interface.h"

using namespace std;

class Report: Interface{
	vector<Book*> books;
public:
	Report();
	~Report();
	void printInventory();
	bool compQuant(Book *b1, Book *b2);
	
	void sortR(bool (Book*, Book*));

//	Book* end();

};

