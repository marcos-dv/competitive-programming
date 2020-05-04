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
	string s;
	cin >> s;
	int n = s.length();
	int tr = 0;
	int z = 0;
	if (s == "0") {
		cout << '0' << endl;
		return 0;
	}
	if (s == "1") {
		cout << '0' << endl;
		return 0;
	}
	if (s == "10") {
		cout << '1' << endl;
		return 0;
	}
		
	for(int i = 0; i < n; ++i)
		if (s[i] == '1')
			z++;
	int j = 1;
	for(int i = n-1; i >= 1; i-=2) {
		if ((s[i] == '1') || (s[i-1] == '1')) {
			tr += j;
			j = 0;
		}
		j++;
	}
	if (n&1) {
		tr += j;
		if (z == 1) {
			tr--;
		}
	}
	cout << tr << endl;	
}

