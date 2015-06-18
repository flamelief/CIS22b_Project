#ifdef REPORT_DRIVER
#include <iostream>
#include <sstream>
#include "Report.h"
#include "Inventory.h"

using namespace std;


int main(){
	//Report r("books2.txt");
	//r.printInventory(Sort::Date);
	Inventory i("books3.txt");
	//i.addBook();
	cout << i.findBook("Finders Keepers") << endl;
	//i.deleteBook();
	i.editBook(Edit::Publisher, "Something House");
	return 0;
}
#endif //REPORT_DRIVER