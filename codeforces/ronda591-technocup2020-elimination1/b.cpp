#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<char, int> fs;

int main() {
	int nc;
	cin >> nc;
	while (nc--) {
		fs.clear();
		string s, t;
		cin >> s >> t;
		for(int i = 0; i < s.length(); ++i) {
			fs[s[i]]++;
		}
		bool ok = false;
		for(int i = 0; i < t.length(); ++i) {
			if(fs[t[i]]) {
				ok = true;
				cout << "YES" << endl;
				break;
			}
		}
		if (!ok)
			cout << "NO" << endl;
	}
}

/*
int main() {
	int nc;
	cin >> nc;
	while (nc--) {
		string s, t;
		cin >> s >> t;
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		int i = 0;
		int j = 0;
		while (i < s.length()) {
			if (s[i] == t[j]) {
				++i;
				++j;
			}
		
		}
	}
}*/
