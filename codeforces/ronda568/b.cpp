//http://codeforces.com/contest/1185/problem/B

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;

//Strings -> comparacion + almacenamiento de las comparaciones


map<string, set<string>> match;
map<string, set<string>> nomatch;

//a -> b, a deriva en b
bool maps(string a, string b) {
	if (b.length() < a.length()) return false;
	if (a[0] != b[0])		return false;
	char last = a[0];
	uint j = 1;
	for(uint i = 1; i < a.length(); ++i) {
		while(j < b.length() && a[i] != b[j] && b[j] == last)
			j++;
		if (j >= b.length())
			return false;
		if (a[i] == b[j]) {
			j++;
			last = a[i];
		}
		else if (b[j] != last)
			return false;
	}
	while(j < b.length() && last == b[j]) {
		j++;
	}
	return (j == b.length());
}

int main() {
	int n;
	string a, b;
	cin >> n;
	set<string>::iterator it;
	set<string> asetok;
	set<string> asetno;
	for(int i = 0; i < n; ++i) {
		cin >> a >> b;
		asetok = match[a];
		if (asetok.find(b) != asetok.end()) {
			cout << "YES\n";
			continue;
		}
		
		asetno = nomatch[a];
		if (asetno.find(b) != asetno.end()) {
			cout << "NO\n";
			continue;
		}
		
		if (maps(a, b)) {
			match[a].insert(b);
			cout << "YES\n";
		}
		else {
			nomatch[a].insert(b);
			cout << "NO\n";
		}
	}
}
