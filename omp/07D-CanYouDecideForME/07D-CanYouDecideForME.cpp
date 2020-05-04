#include <bits/stdc++.h>

using namespace std;

//Parseo de la cadena, y despues comprobacion: c-b = a; a, b, c son prefijo, entrefijo, sufijo

int main() {
	int nc;
	cin >> nc;
	while (nc--) {
		string s;
		cin >> s;
		int n = s.length();
		size_t eme = s.find("M");
		if (eme == string::npos) {
			cout << "no-theorem\n";
			continue;
		}
		size_t e = s.find("E",eme);
		if (e == string::npos) {
			cout << "no-theorem\n";
			continue;
		}
		if (e == eme+1) {	//caso xMEx
			cout << "no-theorem\n";
			continue;
		}

		string a = s.substr(0, eme);
		string b = s.substr(eme+1, e-eme-1);
		string c = s.substr(e+1, n-e-1);
		
	//	cerr << "SUBS, eme = " << eme << ", e = " << e << endl << a << endl << b << endl << c << endl;

		bool ok = true;
		for(int i = 0; i < (int)a.length(); ++i) {
			if (a[i] != '?') {
				ok = false;
				continue;
			}
		}
		for(int i = 0; i < (int)b.length(); ++i) {
			if (b[i] != '?') {
				ok = false;
				continue;
			}
		}
		for(int i = 0; i < (int)c.length(); ++i) {
			if (c[i] != '?') {
				ok = false;
				continue;
			}
		}
		
		int aa = a.length();
		int bb = b.length();
		int cc = c.length();
		if (!ok || (aa < 1) || (bb < 1) || (cc < 1) || (bb > cc)) {
			cout << "no-theorem\n";
			continue;
		}
		cc--; bb--;
		if (cc-bb == aa) {
			cout << "theorem\n";
		}
		else {
			cout << "no-theorem\n";
		}
	}
}


/*
7
??M?E??? 
xM?Ex?
??M??E????
M?E?
??m?e???
?M?E??
12M12E????
*/
