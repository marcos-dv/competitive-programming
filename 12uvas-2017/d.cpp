#include<iostream>
#include <math.h>

using namespace std;

#define MICRAS 1000000

/*
g*2^n = h
h/g = 2n
log2(h/g) 
*/

bool solve () {
	double  gros;
	double h;
	if (!(cin >> gros >> h))
		return false;
	h = MICRAS*h;
	cout << ceil(log2(h/gros)) << '\n';
	return true;
}

int main() {
	while(solve()) ;
}
