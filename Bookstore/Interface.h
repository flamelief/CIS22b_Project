#pragma once
#include <fstream>

using namespace std;

class Interface
{
protected:
	static fstream file;

public:
	Interface();
	~Interface();
};

