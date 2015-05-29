#pragma once
#include <fstream>

using namespace std;

class Interface
{
public:

	static fstream *file;
	Interface();
	Interface(fstream *fs);
	~Interface();
protected:
};

