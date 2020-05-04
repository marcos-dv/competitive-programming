#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<string, set<string>> match;
map<string, set<string>> nomatch;

int main() {
	int n;
	string a, b;
	cin >> n;
	set<string>::iterator it;
	set<string> aset;
	cin >> a >> b;
	aset = match[a];
		cout << "Vacio" << endl;
		if (aset.find(b) == aset.end()) {
			cout << "no sale" << endl;			
		}
		match[a].insert(b);
		aset = match[a];
		if (aset.find(b) == aset.end()) {
			cout << "no sale" << endl;			
		}
		else {
			cout << "si sale" << endl;			
		}
	


}
