#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fib[100005];

const int MOD = 1000000007;

int main() {
	string s;
	cin >> s;
	fib[2] = 2;
	fib[3] = 3;
	for(int i = 4; i < 100005; ++i) {
		fib[i] = (fib[i-1]+fib[i-2])%MOD;
	}
	ll sum = 1;
	if (s[0] == 'm' || s[0] == 'w') {
		cout << 0 << endl;
		return 0;
	}
	char lc = s[0]; //last char
	int rep = 1;
	bool wm = false;
	for(int i = 1; i < s.size(); ++i) {
		if (s[i] == 'm' || s[i] == 'w') {
			wm = true;
			break;
		}
		else if (s[i] == lc) {
			rep++;
		}
		else {
			if ((lc == 'u' || lc == 'n') && (rep > 1)) {
				sum = (sum*fib[rep]) % MOD;
			}
			rep = 1;
			lc = s[i];
		}
	}
	if ((lc == 'u' || lc == 'n') && (rep > 1)) {
		sum = (sum*fib[rep]) % MOD;
	}
	if (wm)
		cout << 0 << endl;
	else
		cout << (sum % MOD) << endl;
}
