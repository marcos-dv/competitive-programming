#include <bits/stdc++.h>

using namespace std;

int main () {
	int a, b, c, d;
	int nc;
	cin >> nc;
	while (nc--) {
		cin >> a >> b >> c >> d;
		int sube = 0;
		int baja = 0;
		sube += a*b;
		baja += c*b+d;
		sube += baja;
		cout << baja << ' ' << sube << endl;
	}

}
