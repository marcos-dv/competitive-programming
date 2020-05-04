//https://codeforces.com/contest/1201/problem/A
//Ronda 577

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	string s[n];
	for(int i = 0; i < n; ++i)
		cin >> s[i];
	int a[m];
	for(int i = 0; i < m; ++i)
		cin >> a[i];
	
	int val = 0;
	int freq[100];
	for(int i = 0; i < m; ++i) {
		for(int c = 'A'; c <= 'E'; ++c)
			freq[c] = 0;
		for(int j = 0; j < n; ++j) {
			freq[s[j][i]]++;
		}
		int maxi = -1;
		for(int c = 'A'; c <= 'E'; ++c) {
			maxi = max(maxi,freq[c]);
		}
		val += maxi*a[i];
	}
	cout << val << endl;
}


