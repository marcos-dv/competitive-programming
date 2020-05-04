#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool present[120];

int main() {
	int n, m;
	string s;
	cin >> n >> m;
	cin >> s;
	for(int i = 0; i < m; ++i) {
		char c;
		cin >> c;
		present[c] = true;
	}
	
	ll sum = 0;
	ll count = 0;
	for(int i = 0; i < n; ++i) {
		if (present[s[i]])
			count++;
		else {
			sum += (count*(count+1))/2;
			count = 0;
		}
	}
	sum += (count*(count+1))/2;
	cout << sum << endl;
}
