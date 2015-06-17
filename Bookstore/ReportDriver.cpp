#ifdef REPORT_DRIVER
#include <iostream>
#include "Report.h"
#include "Inventory.h"

using namespace std;


int main(){
	//Report r("books2.txt");
	//r.printInventory(RetailList);
	Inventory i("books2.txt");
	i.deleteBook();

	return 0;
}
#endif //REPORT_DRIVER