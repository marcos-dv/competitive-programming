#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int gc = __gcd(a,b);
		if (gc == 1)
			cout << "Finite" << endl;
		else
			cout << "Infinite" << endl;
	}
}
