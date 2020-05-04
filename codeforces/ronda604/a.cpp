#include <bits/stdc++.h>
#define N 10005
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

int n;
int a[N];
string s;

int main() {
	int m;
	cin >> m;
	while (m--) {
		cin >> s;
		string sol = s;
		n = (int)s.size();
		if (n == 1) {
			if (s[0] != '?')
				cout << s[0] << endl;
			else
				cout << 'a' << endl;
			continue;
		}
		if (s[0] == '?') {
			if (s[1] == 'a')
				sol[0] = 'b';
			else
				sol[0] = 'a';
		}
		for(int i = 1; i < n; ++i) {
			if ((s[i] == s[i-1]) && (s[i] != '?')) {
				sol = "-1";
				break;
			} else {
				if (s[i] != '?')
					sol[i] = s[i];
				else {
					if (sol[i-1] == 'a') {
						sol[i] = 'b';
					}
					else
						sol[i] = 'a';
				}
			}
		}
		if ((sol == "-1") || (n == 2)) {
			cout << sol << endl;
			continue;
		}
		for(int i = 1; i < n; ++i) {
			if (sol[i] == sol[i-1]) {
				if (s[i-1] == '?') {
					if ((i-1 >= 0) && (s[i-2] != 'c'))
						sol[i-1] = 'c';
					else
						sol[i-1] = 'b';
				
				}
				else if (s[i] == '?')
					sol[i] = 'c';
			}
		}
		
		cout << sol << endl;
	}	
	
}
