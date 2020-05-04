#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, a, b, c;
		cin >> n >> a >> b >> c;
		string s;
		string t(n,0);
		cin >> s;
		int aa = 0, bb = 0, cc = 0;
		int win = 0;
		for(int i = 0; i < n; ++i)
			if ((s[i] == 'R') && (b > 0)) {
				t[i] = 'P';
				b--;
				win++;
			}
			else if ((s[i] == 'P') && (c > 0)) {
				t[i] = 'S';
				c--;
				win++;
			}
			else if ((s[i] == 'S') && (a > 0)) {
				t[i] = 'R';
				a--;
				win++;
			}
		int n2 = (n+1)/2;
		if (win >= n2) {
			cout << "YES" << endl;
			for(int i = 0; i < n; ++i)
				if (t[i] == 0) {
					if ((a > 0)) {
						t[i] = 'R';
						a--;
					}
					else if ((b > 0)) {
						t[i] = 'P';
						b--;
					}
					else if ((c > 0)) {
						t[i] = 'S';
						c--;
					}
				}
			cout << t << endl;
		}
		else
			cout << "NO" << endl;			
	}
}
