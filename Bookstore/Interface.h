#pragma once
#include <fstream>

using namespace std;

class Interface
{
public:

	Interface();
	Interface(fstream *fs);
	~Interface();
protected:
	static fstream *file;
};

