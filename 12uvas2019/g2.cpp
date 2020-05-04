#include <bits/stdc++.h>
#define N 1000000
using namespace std;
typedef long long ll;

int main () {
	ll n, p;
	ll maxi, mini;
	while (cin >> n >> p) {
		if (n == 1) {
			int aux;
			cin >> aux;
			if (aux <= p)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
			continue;
		}
		
		ll sol = 0;
		ll med = p/2;
		
		mini = p+1;
		maxi = 0;
		ll a;
		for(int i = 0; i < n; ++i) {
			cin >> a;
			if (a <= med) {
				sol++;
			}
			if (a > med) {
				mini = min(mini, a);
			}
			else {
				maxi = max(maxi, a);
			}
		}
		if (maxi + mini <= p)
			sol++;
		
		cout << sol << '\n';
	}
}
