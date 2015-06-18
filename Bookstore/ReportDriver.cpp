#ifdef REPORT_DRIVER
#include <iostream>
#include "Report.h"
#include "Inventory.h"

using namespace std;


int main(){
	Report r("books2.txt");
	r.printInventory(Sort::Date);
	//Inventory i("books2.txt");
	//i.addBook();
	//i.findBook("w");
	//i.deleteBook();
	//i.editBook(&Book::setPub, "leslie");
	return 0;
}
#endif //REPORT_DRIVER