#ifdef REPORT_DRIVER
#include <iostream>
#include "Report.h"

using namespace std;


int main(){
		Report r("books2.txt");
		r.printInventory(WholesaleList);
	return 0;
}
#endif //REPORT_DRIVER