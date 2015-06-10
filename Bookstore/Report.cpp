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

void Report::printInventory(Price(Book::*get)() const) {
	Price total;
	switch (mode) {
		case WholesaleList:
			cout << "List of wholesale prices: \n";
			break;
		case RetailList:
			cout << "List of retail prices: \n";
			break;
		default:
			cout << "List of inventory ";
			switch (mode) {
				case Unsorted:
					cout << ":\n";
					break;
				case Quantity:
					cout << "by quantiy:\n";
					break;
				case Date:
					cout << "by date added:\n";
					break;
				case Retail:
					cout << "by retail price:\n";
					break;
				case Wholesale:
					cout << "by wholesale price:\n";
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

void Report::setMode(Sort mode){
	Price(Book::*get)() const;
	switch (mode){
		case WholesaleList:
			get = &Book::getWhole;
			break;
		case RetailList:
			get = &Book::getRetail;
			break;
		default:
			get = NULL;
			if (this->mode != mode){
				switch (mode){
				case Quantity:
					sort(&Book::getQuant);
					break;
				case Retail:
					sort(&Book::getRetail);
					break;
				case Wholesale:
					sort(&Book::getWhole);
					break;
				}
			}
			break;
	}
	this->mode = mode;
	printInventory(get);
}

template <typename fT>
void Report::sort(fT get) {
	std::sort(books.begin(), books.end(), 
		[&](const Book &b1, const Book &b2) { return (b1.*get)() > (b2.*get)(); });
}