#include <bits/stdc++.h>
#define push_back pb

using namespace std;
typedef long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MAXN = 1000006;

int n, arr[MAXN], d;
map<string, ll> fr;

int main() {
	int casos;
	cin >> casos;
	for (int cas = 1; cas <= casos; cas++) {
		fr.clear();
		cin >> n;
		for(int k = 0; k < n; ++k) {
			string s;
			cin >> s;
			for(int i = 0; i < (int)s.length()-3; ++i) {
				string ss = s.substr(i, 3);
				fr[ss]++;
			}
		}
		string pat = "";
		ll maxi = -1;
		for(char i = 'A'; i <= 'Z'; ++i)
		for(char j = 'A'; j <= 'Z'; ++j)
		for(char k = 'A'; k <= 'Z'; ++k) {
			string ss = "";
			ss = i;
			ss += j;
			ss += k;
			if (maxi < fr[ss]) {
				maxi = fr[ss];
				pat = ss;
			}
		}
		cout << "PATENT " << pat << " AND WIN " << maxi*1000 << " EUROS!" << endl;
	}
}
