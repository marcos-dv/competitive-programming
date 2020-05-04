#include <bits/stdc++.h>

using namespace std;

/*
	Mayor subcadena repetida en una cadena
	(Empate -> primera en aparecer)
	Busqueda binaria por tamano
	s.length() = n -> 
	s.find() -> O(n)
	Aprox O(n²log2n) cada caso
*/

int main() {
	int N;
	string s;
	cin >> N;
	getline(cin, s);
	for(int i = 0; i < N; ++i) {
		getline(cin, s);
		int len = s.length();
		int l = 0;	//Revisar empezar en 0 ok
		int r = len;
		int m = (l+r)/2;
		int lastInd = -1;
	//	cerr << "word = " << s << endl;
		while(l != m) {
		//	cerr << "tamano = " << m << endl;
			bool encontrado = false;	//tamano m -> encontrada cadena
			for(int i = 0; i < len-m+1; ++i) {
				string sub = s.substr(i, m);
			//	cerr << sub << endl;
				size_t found = s.find(sub, i+1);
				if (found != string::npos) {
					lastInd = i;
					encontrado = true;
			//		cerr << "OK" << endl;
					break;
				}
			}
			if (!encontrado) {
				r = m;
			}
			else {
				l = m;
			}
			m = (l+r)/2;
		}
		if (lastInd >= 0)
			cout << s.substr(lastInd, m) << endl;
		else {
			cout << endl;
		}
	}
	
	
}	

	
