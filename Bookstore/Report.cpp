#define _CRT_SECURE_NO_WARNINGS
#include "Report.h"

Report::Report(string fileName) : Interface(fileName){
	mode = Sort::Unsorted;
}
Report::Report()
{
	mode = Sort::Unsorted;
}

Report::~Report() {}

void Report::printInventory(Sort::Mode mode){
	double(Book::*get)() const;
	get = NULL;
	bool sorted = this->mode == mode;
	double total = 0;
	this->mode = mode;
	switch (mode){
		case Sort::WholesaleList:
			cout << "List of wholesale prices: \n";
			get = &Book::getWhole;
			break;
		case Sort::RetailList:
			cout << "List of retail prices: \n";
			get = &Book::getRetail;
			break;
		default:
			cout << "List of inventory ";
			switch (mode){
				case Sort::Unsorted:
					cout << ":\n";
					break;
				case Sort::Quantity:
					cout << "by quantiy:\n";
					if(!sorted) sort(&Book::getQuant);
					break;
				case Sort::Retail:
					cout << "by retail price:\n";
					if(!sorted) sort(&Book::getRetail);
					break;
				case Sort::Wholesale:
					cout << "by wholesale price:\n";
					if(!sorted) sort(&Book::getWhole);
					break;
				case Sort::Date:
					if (!sorted) sort(&Book::getDate);
					cout << "by date added:\n";
					break;
			}
			cout << books;
			return;
	}
	std::for_each(books.begin(), books.end(), [&](const Book &b){
		cout << (b.*get)() << endl;
		total += (b.*get)();
	});
	cout << "Total cost of inventory: " << total << endl;
}

void Report::printInventory() {
	printInventory(mode);
}
// sort that takes in type fT
template <typename fT>
void Report::sort(fT get) {
	std::sort(books.begin(), books.end(), 
		[&](const Book &b1, const Book &b2) { return (b1.*get)() > (b2.*get)(); });
}