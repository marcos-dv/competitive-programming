#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define N 1000007

using namespace std;

int m, x, y, z;
string s;
map<string, string> w;

string tolo(string ss) {
	string res = ss;
	for(int i = 0; i < res.size(); ++i) {
		res[i] = tolower(res[i]);
	}
	return res;
}

string add(string s1, string s2) {
	string res = s1;
	for(int i = 0; i < s1.size(); ++i) {
		res[i] = min(s1[i], s2[i]);
	}
	return res;
}

vector<string> strings;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while(cin >> n) {
		w.clear();
		strings.clear();
		for(int i = 0; i < n; ++i) {
			cin >> s;
			if (w[tolo(s)] != "") {
				w[tolo(s)] = add(s, w[tolo(s)]);
			}
			if (w[tolo(s)] == "") {
				w[tolo(s)] = s;
			}
			strings.pb(s);
		}
		
		for(int i = 0; i < n; ++i) {
			s = strings[i];
			cout << w[tolo(s)] << '\n';
		}
		cout << "---\n";
	}
	
}



