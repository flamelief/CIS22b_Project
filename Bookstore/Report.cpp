#include "Report.h"


Report::Report()
{
	books.resize(100);
	Book b;
	if (*file){
		for (int i = 0; file->good(); i++){
			*file >> books.at(i);
		}
	}
	cout << books.at(2);
	//for_each(books.begin(), books.end(), [](const Book &b){ cout << b; });
}




Report::~Report()
{
}

