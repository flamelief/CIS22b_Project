#ifdef REPORT_DRIVER
#include <iostream>
#include "Report.h"

using namespace std;


int main(){
	fstream fs("books.txt", fstream::in | fstream::out | fstream::app );
	Interface I = Interface(&fs);
	Report r;
//	r.setCompare();  //Report::compQuant);
	r.sort();
	r.printInventory();
	return 0;
}
#endif //REPORT_DRIVER