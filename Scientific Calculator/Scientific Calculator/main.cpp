#include <iostream>
#include "Token.h"
using namespace std;

class Util {

};

int main() {
	Token t1;
	cout << static_cast<int>(t1.get_type()) << endl;
	return 0;
}