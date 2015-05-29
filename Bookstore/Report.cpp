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
}




Report::~Report()
{
}

