#include "Report.h"

Report::Report()
{
	//TODO: Find behavior on destruction
	if (*file && file->seekg(ios_base::beg)){
		file->clear();
		while(file->good()){
			Book temp = Book();
			*file >> temp;
			books.push_back(temp);
		}
		mode = Unsorted;
	}
}

Report::~Report()
{
	//std::for_each(books.begin(), books.end(), [](const Book &b){ delete b; });
}

void Report::printInventory(Sort mode){
	Price(Book::*get)() const;
	get = NULL;
	bool sorted = this->mode == mode;
	Price total;
	this->mode = mode;
	switch (mode){
		case WholesaleList:
			cout << "List of wholesale prices: \n";
			get = &Book::getWhole;
			break;
		case RetailList:
			cout << "List of retail prices: \n";
			get = &Book::getRetail;
			break;
		default:
			cout << "List of inventory ";
			switch (mode){
				case Unsorted:
					cout << ":\n";
					break;
				case Quantity:
					cout << "by quantiy:\n";
					if(!sorted) sort(&Book::getQuant);
					break;
				case Retail:
					if(!sorted) sort(&Book::getRetail);
					break;
				case Wholesale:
					if(!sorted) sort(&Book::getWhole);
					break;
				case Date:
					//if (!sorted) sort(&Book::getDate);
					cout << "by date added:\n";
					break;
			}
			std::for_each(books.begin(), books.end(), [](const Book &b){ cout << b << endl; });
			return;
	}
	std::for_each(books.begin(), books.end(), [&](const Book &b){
		cout << (b.*get)() << endl;
		total += (b.*get)();
	});
	cout << "Total cost of inventory: " << total << endl;
}

template <typename fT>
void Report::sort(fT get) {
	std::sort(books.begin(), books.end(), 
		[&](const Book &b1, const Book &b2) { return (b1.*get)() > (b2.*get)(); });
}