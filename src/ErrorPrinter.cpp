#include "ErrorPrinter.h"
#include <iostream>
using namespace std;

void ErrorPrinter::printUsage(){
	cout << "Usage: simulator [-config <config path>]"
			" [-house_path <house path>]"
			" [-algorithm_path <algorithm path>]" << endl;
}
