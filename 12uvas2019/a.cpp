#include <bits/stdc++.h>

using namespace std;

int main () {
	int a, b;
	while (cin >> a >> b) {
		if (a == 0 && b == 0)
			break;
		if (a < b)
			cout << "SENIL\n";
		else
			cout << "CUERDO\n";
	}

}
