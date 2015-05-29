#include "Interface.h"

fstream *Interface::file = NULL;

Interface::Interface(fstream *fileStream)
{
	file = fileStream;
}
Interface::Interface(){}

Interface::~Interface()
{
	if (file->is_open()) file->close();
}
