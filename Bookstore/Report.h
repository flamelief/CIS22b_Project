#pragma once
#include <vector>
#include <algorithm>
#include "Book.h"
#include "Interface.h"

using namespace std;

class Report: Interface{
	vector<Book> books;
public:
	Report();
	~Report();
};

