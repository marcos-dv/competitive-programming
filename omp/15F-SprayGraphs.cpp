#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int nc;
	cin >> nc;
	while (nc--) {
		int n;
		cin >> n;
		if (n == 1)
			cout << '1' << endl;
		else {
			ll sol = 1;
			sol <<= (n+1);
			sol-=4;
			cout << sol << endl;
		}
	}
}
