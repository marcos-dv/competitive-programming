#include <bits/stdc++.h>

using namespace std;

int main () {
	int a, b;
	while (cin >> a >> b) {
		if ((b-a+1) % 10 == 0)
			cout << "FELIZ DECADA NUEVA\n";
		else
			cout << "TOCA ESPERAR\n";
	}

}
