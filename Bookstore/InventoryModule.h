#ifndef INVENTORY_DATABASE_MODULE
#define INVENTORY_DATABASE_MODULE

#include "Module.h"
#include "Book.h"
#include <vector>
#include <iostream>


using namespace std;

class InventoryDatabaseModule : public Module
{
public:
	InventoryDatabaseModule(BookList*);
	void act();  


	void addBook();
	void lookUpBook();            
	void editBook();
	void deleteBook();


};




#endif 