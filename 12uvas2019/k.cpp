#include <bits/stdc++.h>
#define N 1000005
using namespace std;
typedef long long ll;

ll nc[65][10];

void ininc() {
	nc[0][0] = 1;
	nc[1][1] = 1;
	for(int i = 0; i < 65; ++i)
		nc[i][0] = 1;
		
	for(int i = 1; i < 65; ++i) {
		for(int j = 1; j <= min(i, 8); ++j) {
			nc[i][j] = nc[i-1][j-1] + nc[i-1][j];
		}
	}
}

string tob2 (ll n) {
	if (n == 0)
		return "0";
	bitset<64> bs(n);
	string s = bs.to_string();
	int j = s.find('1');
	return s.substr(j);
}

ll comb(ll n, ll m) {
	if (m < 0)
		return 0;
	if (m == 0)
		return 1;
	if (n == 0)
		return 1;
	string s = tob2(m);
	ll sol = 1;
	int i = 0;
	int len = s.length();
	int unos = n;
	while ((i < len) && (unos > 0)) {
		if (s[i] == '1') {
			// cero en s[i]
			for(int j = 0; j <= unos; ++j)
				sol += nc[len-i-1][j];
			//cerr << endl << "Van " << sol << " unos = " << unos;
			// uno en s[i]
			unos--;
			i++;
		}
		else if (s[i] == '0') {
			i++;
		}
	}
	//el 0 no cuenta
	return sol;
}

int main () {
	ininc();
	/*
	for(int p = 0; p <= 4; ++p)
		for(int i = 1; i < 100000; ++i) {
			if (comb(p, i) < comb(p,i-1))
				cerr << p << i << "CACA" << endl;
		}
	*/
/*	
	ll a, b;
	while(true) {
		cin >> a >> b;
		ll solu = comb(a,b);
		cerr << "unos = " << a << " n = " << tob2(b) << " (" << b << ")" << ", combinaciones = " << solu << endl;
	}
*/
	ll n, ini, fin;
	while (cin >> n >> ini >> fin) {
		if (n == 0 && ini == 0 && fin == 0) {
			break;
		}
		else if (n == 0 && ini == 0) {
			cout << 1 << '\n';
			continue;
		}
		//cerr << "unos = " << n << " n = " << tob2(fin) << " (" << fin << ")" << ", combinaciones = " << comb(n, fin) << endl;
		cout << (comb(n, fin)-comb(n, ini-1)) << '\n';
		
	}
}
