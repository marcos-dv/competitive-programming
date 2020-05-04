#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool present[120];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int q;
	string s;
	cin >> q;
	while (q--) {
		cin >> s;
		int l = 0, r = 0, u = 0, d = 0;
		for(char c : s) {
			l += c == 'L';
			r += c == 'R';
			u += c == 'U';
			d += c == 'D';
		}
		l = min(r, l);
		u = min(u, d);
		if (l == 0) {
			u = min(u, 1);
		}
		if (u == 0) {
			l = min(l, 1);
		}
		cout << 2*(u+l) << endl;
		string ss(2*(u+l), 0);
		for(int i = 0; i < u; ++i) ss[i] = 'U';
		for(int i = u; i < l+u; ++i) ss[i] = 'L';
		for(int i = l+u; i < u+l+u; ++i) ss[i] = 'D';
		for(int i = u+u+l; i < l+u+l+u; ++i) ss[i] = 'R';
		cout << ss << endl;
	}
}
