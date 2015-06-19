#ifdef REPORT_DRIVER
#include <iostream>
#include <sstream>
#include "Report.h"
#include "Inventory.h"

using namespace std;


int main(){
	Price p(100, 0), w(1, 1);
	Book b;
	b.setRetail(p);
	w = w + (p);
	cout << w << endl;
	return 0;
}
#endif //REPORT_DRIVER