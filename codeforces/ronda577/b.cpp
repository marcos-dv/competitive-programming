#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int main() {
	int n;
	cin >> n;
	int a[n];
	ll sum = 0;
	int maxi = -1;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		maxi = max(maxi, a[i]);
		sum += a[i];
	}
	
	if ((sum & 1) || (maxi > sum/2))
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
}

