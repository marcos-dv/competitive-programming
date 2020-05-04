#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

bool solve() {
	string s, aux;
	aux = "";
	vector <string> v;
	if (!(cin >> s))
		return false;
	
	for(int i = 0; i < s.length(); ++i) {
		if(isupper(s[i])) {
			if (i != 0)
				v.push_back(aux);	
			aux = tolower(s[i]);		
		}
		else if ((s[i] == '-') || (s[i] == '_')) {
			v.push_back(aux);
			aux = "";
		}
		else {
			aux += s[i];
		}
	}
	v.push_back(aux);
	cin >> s;
	if (s == "snake_case") {
		cout << v[0];
		for(int i = 1; i < v.size(); ++i) {
			cout << '_' << v[i];
		}
	}
	else if (s == "kebab-case") {
		cout << v[0];
		for(int i = 1; i < v.size(); ++i) {
			cout << '-' << v[i];
		}
	}
	else {
		for(int i = 0; i < v.size(); ++i) {
			v[i][0] = toupper(v[i][0]);
			cout << v[i];
		}
	}
	cout << endl;
	return true;
}

int main() {
	while(solve()) ;

}
