//https://codeforces.com/contest/1199

#include<bits/stdc++.h>
#define pb push_back

using namespace std;
typedef long long ll;

int main() {
	int n, x, y;
	cin >> n >> x >> y;
	int a[n];
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	for(int i = 0; i < n; ++i) {
		bool ok = true;
		for(int j = max(0, i-x); j <= min(i+y, n-1); ++j) {
			if (i != j) {
				if (a[j] < a[i]) {
					ok = false;
					break;
				}
			}
		}
		if (ok) {
			cout << i+1 << endl;
			return 0;
		}
	}
}
