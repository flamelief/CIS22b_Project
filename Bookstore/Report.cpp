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

