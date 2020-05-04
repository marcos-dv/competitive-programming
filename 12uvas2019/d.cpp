#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main () {
	ll a, b, c;
	while(cin >> a >> b >> c) {
		if (a == 0 && b == 0 && c == 0)
			break;
		ll mcd = __gcd(a, b);
		mcd = __gcd(mcd, c);
		a /= mcd;
		b /= mcd;
		c /= mcd;
		cout << (a+b+c) << endl;
	}

}
