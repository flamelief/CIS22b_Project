#pragma once
#include <fstream>
#include <vector>
#include <algorithm>
#include "Book.h"

using namespace std;

/*
Class used to open file and read Books.
*/
class Interface
{
	static string fileName;
public:
	~Interface();
protected:
	/*
	Opens file and reads books to static Book vector.
	opens file using static fileName member while string constructor
	sets fileName to string first.
	*/
	Interface();
	Interface(string fileName);
	/*
	Adds book to vector, doubling the size of vector if vector is full.
	*/
	void pushBook(const Book);
	/*
	Static Book vector shared with child classes.
	*/
	static vector<Book> books;
	friend ostream& operator<<(ostream&, const  vector<Book>&);
};

