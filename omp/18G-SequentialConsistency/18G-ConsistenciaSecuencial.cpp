#include <bits/stdc++.h>

using namespace std;

/*
	Backtracking -> generar todas las posibilidades
*/

//asig = true -> es asignacion, false -> print
typedef struct {
	bool asig;
	string var;
	char val;
} inst;	//instruccion

set<string> sol; //Salidas validas
list<inst> tren; //de instrucciones a ejecutar
vector<inst> hilo1; //instrucciones de cada hilo
vector<inst> hilo2;
string s;
map<string, char> valores; //valores de las variables durante una ejecucion
int N, M;

//Ejecuta las instrucciones en tren
inline void ejecuta() {
//	cerr << "tren.size = " << tren.size() << endl;
	valores.clear();
	s = "";
	for(list<inst>::iterator it = tren.begin(); it != tren.end(); ++it) {
		if ((*it).asig) {
			valores[(*it).var] = (*it).val;
		}
		else {
			s += (valores[(*it).var] == 0)?'0':valores[(*it).var];
		}
	}
	sol.insert(s);
}

//Funcion recursiva
inline void bt(int i, int j) {
	//cerr << "i = " << i << " || j = " << j << endl;

	if ((i > N) || (j > M))
		return ;
	if ((i == N) && (j == M)) {
		ejecuta();
	}
	else {
		if (i < N) {
			tren.push_back(hilo1[i]);
			list<inst>::iterator it = tren.end(); it--;
			bt(i+1,j);
			tren.erase(it);		
		}
		if (j < M) {
			tren.push_back(hilo2[j]);
			list<inst>::iterator it = tren.end(); it--;
			bt(i,j+1);
			tren.erase(it);
		}
	}
}

int main() {
	int nc;
	for(cin >> nc; nc > 0; nc--) {
		sol.clear();
		tren.clear();
		hilo1.clear();
		hilo2.clear();
		
		cin >> s;
		//Lectura instrucciones
		while (s != "#") {
			inst i;
			if (s == "print") {
				i.asig = false;
				cin >> s;
				i.var = s;
			}
			else {
				i.asig = true;
				i.var = s;
				cin >> s;	// =
				char valor;
				cin >> valor;
				i.val = valor;
			}
			hilo1.push_back(i);
			cin >> s;
		}
		cin >> s;
		while (s != "#") {
			inst i;
			if (s == "print") {
				i.asig = false;
				cin >> s;
				i.var = s;
			}
			else {
				i.asig = true;
				i.var = s;
				cin >> s;	// =
				char valor;
				cin >> valor;
				i.val = valor;
			}
			hilo2.push_back(i);
			cin >> s;
		}


		/* Chequeo
		cerr << "h1, total: " << hilo1.size() << endl;
		for(int i = 0; i < hilo1.size(); ++i) {
			if (hilo1[i].asig)
				cerr << hilo1[i].var << ' ' << hilo1[i].val << endl;
			else
				cerr << hilo1[i].var << endl;
		}
		cerr << "h2, total: " << hilo2.size() << endl;
		for(int i = 0; i < hilo2.size(); ++i) {
			if (hilo2[i].asig)
				cerr << hilo2[i].var << ' ' << hilo2[i].val << endl;
			else
				cerr << hilo2[i].var << endl;
		}
		*/


		//Generar posibilidades
		N = hilo1.size();
		M = hilo2.size();
		bt(0,0);		

/*
		cerr << endl << endl << "Size = " << sol.size() << endl;
		for(set<string>::iterator it = sol.begin(); it != sol.end(); it++) {
			cerr << *it << endl;
		}
		cerr << endl << endl;
*/
		cin >> s;
		while (s != "#") {
			if (sol.find(s) != sol.end()) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
			cin >> s;
		}
		if (nc > 1)
			cout << endl;
	} 

}


/*


Sample Input
2
a = 1
print b
#
b = 1
print a
#
00
01
11
10
111
#
print a
#
print b
#
11
00
#
Sample Output
NO
YES
YES
NO
NO

NO
YES

*/
