#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define N 1000007

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
int n, m, x, y, z;
string s;
int v[N+2];

int main() {
	while(cin >> n && n) {
		priority_queue<ii, vector<ii>, greater<ii>> pq;
		ll sol = 0;
		for(int i = 0; i < n; ++i) {
			cin >> x;
			
			while (!pq.empty() && pq.top().fi < x) {
				sol += i-pq.top().se;
				pq.pop();
			}
			pq.push(mp(x,i));
		}
		while (!pq.empty()) {
			sol += n-pq.top().se;
			pq.pop();
		}
		cout << sol << '\n';
	}
	for(int i = 0; i < n; ++i) {
		return 0;
	}
	
}



