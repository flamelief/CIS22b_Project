#pragma once
#include <fstream>
#include <vector>
#include <algorithm>
#include "Book.h"

using namespace std;

class Interface
{
	static string fileName;
public:
protected:
	Interface();
	Interface(string fileName);
	~Interface();
	void pushBook(const Book);
	static vector<Book> books;
	friend ostream& operator<<(ostream&, const  vector<Book>&);
};

