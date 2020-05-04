#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MAXN 200006
map<char, int> fs;

ll t[MAXN];
ll s[MAXN];
int a, b;
ll x, y;

ll calc(int r) {
	int aa = r/a;
	int bb = r/b;
	int ab = r/(a*b);
	ll at = 0, bt = 0, abt = 0;
	abt = s[ab]*(x+y);
	at = (s[aa]-s[ab])*x;
	cerr << s[aa+bb-ab] << '/' << s[aa] << endl;
	bt = (s[aa+bb-ab]-s[aa])*y;
	cerr << " aa = " << aa << " bb = " << bb << " ab = " << ab << " at = " << at << " bt = " << bt << " abt = " << abt << endl << endl;
	return abt+at+bt;
}

int main() {
	int nc;
	cin >> nc;
	while (nc--) {
		cerr << "Caso " << endl;
		int n;
		cin >> n;
		for(int i = 0; i < n; ++i) {
			cin >> t[i];
			t[i] /= 100;
		}
		sort(t, t+n);
		reverse(t, t+n);
		s[0] = 0;
		for(int i = 1; i <= n; ++i)
			s[i] = s[i-1]+t[i-1];
		for(int i = 0; i < n; ++i) {
			cerr << "t["<<i<<"] = " << t[i] << ", s["<<i+1<<"] = "<<s[i+1] << endl;
		}

		cin >> x >> a >> y >> b;
		if (x < y) {
			swap(x, y);
			swap(a, b);
		}
		ll k;
		cin >> k;
		int num = n;
		cerr << "--- n = " << n << "--- a = " << a << " b = " << b << endl;
		cerr << "x = " << x << " y = " << y << ". k = " << k << endl;
		if (calc(n) < k) {
			cout << "-1" << endl;
			continue;
		}
		cerr << "Binaria" << endl << endl;
		int l = 1;
		int r = n;
		num = (l+r)/2;
		while (l < num) {
			cerr << "-Check tickets = " << num << endl;
			if (calc(num) < k) {
				l = num;
			}
			else {
				r = num;
			}
			num = (l+r)/2;
		}
		if (calc(num) < k) {
			cout << r << endl;
		}
		else {
			cout << num << endl;
		}
	}
}

/*
int main() {
	int nc;
	cin >> nc;
	while (nc--) {
		string s, t;
		cin >> s >> t;
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		int i = 0;
		int j = 0;
		while (i < s.length()) {
			if (s[i] == t[j]) {
				++i;
				++j;
			}
		
		}
	}
}*/
