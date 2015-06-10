#include "Report.h"


Report::Report()
{
//	books.resize(100);
	if (*file){
		while(file->good()){
			Book *temp = new Book();
			*file >> *temp;
			books.push_back(temp);
		}
	}
}

Report::~Report()
{
	for_each(books.begin(), books.end(), [](const Book *b){ delete b; });
}

void Report::printInventory(){
	for_each(books.begin(), books.end(), [](const Book *b){ cout << *b << endl; });
}

bool Report::compQuant(Book *b1, Book *b2) { return b1->getQuant() > b2->getQuant(); }

void Report::sortR(bool f(Book *b1, Book *b2)) { std::sort(books.begin(), books.end(), f); }

