#ifdef DRIVER
#include <iostream>
#include "Report.h"

using namespace std;

int main(){
	fstream fs("books.txt", fstream::in | fstream::out | fstream::app );
	Interface I = Interface(&fs);
	Report r;
	r.printInventory();
	return 0;
}
#endif //DRIVER