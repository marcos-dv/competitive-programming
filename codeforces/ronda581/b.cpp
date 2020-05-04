#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define N 1000000007
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int main() {
	int n, l ,r;
	ll po[21];
	po[0] = 1;
	for(int i = 1; i <= 20; ++i)
		po[i] = po[i-1]*2;

	cin >> n >> l >> r;
	ll su = 0;
	ll elem = 0;
	for (int i = 0; i < l && elem < n; ++i) {
		su += po[i];
		elem++;
	}
	ll ma = su;
	ll mi = su + n-l;
	for(int i = l; i < r && elem < n; ++i) {
		ma += po[i];
		elem++;
	}
	for(int i = r; i < n && elem < n; ++i) {
		ma += po[r-1];
		elem++;
	}
	cout << mi << ' ' << ma << endl;
}

