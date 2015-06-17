#include "Interface.h"

const int BOOKS_CAPACITY = 20;
string Interface::fileName;
vector<Book> Interface::books;

Interface::Interface(string name)
{
	books.clear();
	fileName = name;
	fstream file(fileName, fstream::in);
	if (file) {
		while (file) {
			Book temp;
			file >> temp;
			if (file) addBook(temp);
		}
		cout << books.size() << endl;
		file.close();
	}
}

Interface::Interface() : Interface(fileName) {}

Interface::~Interface()
{
	if (books.size()){
		fstream file(fileName, fstream::out | fstream::trunc);
		file << books;
		file.close();
	}
}

ostream &operator<<(ostream &output, const vector<Book>& books){
	if (books.size()){
		std::for_each(books.begin(), books.end() - 1, [&](const Book &b){ output << b << endl; });
		output << books.back();
	}
	return output;
}

void Interface::addBook(const Book b){
	if (books.size()){
		if (books.size() >= books.capacity()) {
			books.reserve(books.capacity() * 2);
		}
	}
	else books.reserve(BOOKS_CAPACITY);
	books.push_back(b);
}
