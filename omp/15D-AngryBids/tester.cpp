#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	srand (time(NULL));
	cout << "1 2235 2312\n";
	for (int i = 0; i < 20000; ++i)
		cout << rand()%999999 << endl;
}
