#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;
int n, m, z, C, F;
string s;
int x[50005];
int y[50005];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while ((cin >> C >> F >> n) && (n+C+F > 0)) {
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		for(int i = 0; i < n; ++i) {
			cin >> x[i] >> y[i];
		}
		sort(x, x+n);
		sort(y, y+n);
		cout << x[(n-1)/2] << ' ' <<  y[(n-1)/2] << '\n';
	}
}



