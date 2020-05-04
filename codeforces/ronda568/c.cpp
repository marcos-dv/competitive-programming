//http://codeforces.com/contest/1185/problem/C1
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//Facil greedy O(n^2) malo

int main() {
	ll n, M, sum;
	cin >> n >> M;
	ll t[n];

	
	cin >> t[0];
	sum = t[0];
	cout << 0;
	
	for(int i = 1; i < n; ++i) {
		priority_queue<int> pq;
		cin >> t[i];
		for(int j = 0; j < i; ++j) {
			pq.push(t[j]);
		}
		int out = 0;
		ll timeGain = 0;
		while (sum+t[i]-timeGain > M) {
			timeGain += pq.top();
			pq.pop();
			out++;
		}
		cout << ' ' << out;
		sum += t[i];
	}
	cout << endl;
}
