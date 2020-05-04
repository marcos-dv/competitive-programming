#include <bits/stdc++.h>

using namespace std;

/*
	Cada palabra un nodo. Arista <=> las palabras son iguales salvo una letra
	Hacer grafo y ver componentes conexas
	Para cada consulta, guardar las componentes conexas a las que pertenece una palabra
	Hay 2 casos:
	-La palabra es del diccionario -> pertenece a su cc solamente
	-Si no, puede pertenecer a varias (por eso un set)
*/

const int N = 20000;

//clase de equivalencia del nodo i = Rel[i]
int Rel[N+9];

vector<string> words;

//Relacion de equivalencia
int Encuentra (int n) {
	if (Rel[n] == n)
		return n;
	return Encuentra(Rel[n]);
}

//Compresion de caminos
void Union (int n, int m) {
    n = Encuentra(n);
    m = Encuentra(m);
    Rel[n] = m;
}

// hay arista u,v??
inline bool match(string u, string v) {
	if (u.length() != v.length())
		return false;
	int count = 0;
	for(int i = 0; i < (int)u.length(); ++i) {
		if (u[i] != v[i]) {
			++count;
			if (count > 1)
				return false;
		}
	}
	return true;
}

int main() {

	//set de las componentes asociadas a un string
	map<string, unordered_set<int>> compos;
	string s, f;
	for(int i = 0; i < N; ++i)
		Rel[i] = i;
	words.clear();
	//lectura
	while(true) {
		cin >> s;
		if (s == "--")
			break;
		words.push_back(s);
	}
	//Preprocesamiento para componentes conexas O(n^2/2)
	for(int i = 0; i < (int)words.size(); ++i) {
		for(int j = 0; j < i; ++j) {
			if (match(words[i], words[j])) {
				Union(i, j);
			}
		}
	}

	for(int i = 0; i < (int)words.size(); ++i) {
		compos[words[i]].insert(Rel[i]);
	}

	//Consultas en O(n) (mejora guardando resultados)
	//sacar las posibles cc de s. Ver si las de f coinciden con alguna

	while (cin >> s >> f) {
		if (match(s, f)) {
			cout << "Yes" << endl;
			continue;
		}
		
		if (s.length() != f.length()) {
			cout << "No" << endl;
			continue;
		}

		unordered_set<int> compoS = compos[s];
		if (compoS.size() == 0) {
			//halla las posibles componentes conexas de cada palabra O(n)
			for(int i = 0; i < (int)words.size(); ++i) {
				if (match(s, words[i]))
					compoS.insert(Rel[i]);
			}
			if (compoS.size() == 0) {
				compoS.insert(-10);
			}
			compos[s] = compoS;
		}

		unordered_set<int> compoF = compos[f]; //posibles componentes conexas
		if (compoF.size() == 0) {
			//halla las posibles componentes conexas de cada palabra O(n)
			for(int i = 0; i < (int)words.size(); ++i) {
				if (match(f, words[i]))
					compoF.insert(Rel[i]);
			}
			if (compoF.size() == 0) {
				compoF.insert(-10);
			}
			compos[f] = compoF;
		}

		//chequeo de si desde s se llega hasta f (comparten alguna cc)
		bool ok = false;
		unordered_set<int>::iterator found;
		for(unordered_set<int>::iterator it = compoS.begin(); it != compoS.end(); it++) {
			if ((*it != -10) && (compoF.find(*it) != compoF.end())) {
				ok = true;
			}
		}
		if (ok)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}

/*

abc
abd
acc
bbb
aba
--
abc acc
abc bbb
acc abd
bbb abc
abd abc
aba abc

Yes
No
Yes
No
Yes
Yes

*/


