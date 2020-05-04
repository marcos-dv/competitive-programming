#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
	int nc;
	cin >> nc;
	while (nc--) {
		int n;
		cin >> n;
		if (n == 2)
			cout << 2 << endl;
		else if (n & 1)
			cout << 1 << endl;
		else 
			cout << 0 << endl;
	}
}
