#include "Interface.h"

string Interface::fileName;
vector<Book> Interface::books;

Interface::Interface(string name)
{
	fileName = name;
	fstream file(fileName, fstream::in);
	if (file && file.is_open()) {
		while (file.good()){
			Book temp = Book();
			file >> temp;
			books.push_back(temp);
		}
	}
	file.close();
}
Interface::Interface(){}

Interface::~Interface()
{
		
		fstream file(fileName, fstream::out | fstream::trunc);
		file << books;
		file.close();
}

ostream &operator<<(ostream &output, const vector<Book>& books){
	std::for_each(books.begin(), books.end() - 1, [&](const Book &b){ output << b << endl; });
	output << books.back();
	return output;
}
