#include <iostream>

using namespace std;

//Simbolos
#define B 1
#define U 10
#define S 100
#define P 1000
#define F 10000
#define T 100000
#define M 1000000

//Monotonia
#define UNKNOWN 0
#define CRECE 1
#define DECRECE -1

//Maximo de apariciones de cada simbolo
#define MAX_APARICIONES 10

//Comparacion de letras (devuelve a < b), donde a y b son 2 simbolos
bool comparar (char a, char b) {
	int n = 0;
	int m = 0;
	
	if (a == 'B')
		n = B;
	if (a == 'U')
		n = U;	
	if (a == 'S')
		n = S;
	if (a == 'P')
		n = P;
	if (a == 'F')
		n = F;
	if (a == 'T')
		n = T;
	if (a == 'M')
		n = M;
		
	if (b == 'B')
		m = B;
	if (b == 'U')
		m = U;
	if (b == 'S')
		m = S;
	if (b == 'P')
		m = P;
	if (b == 'F')
		m = F;
	if (b == 'T')
		m = T;
	if (b == 'M')
		m = M;

	return n < m;

}

//Devuelve la suma asociada al caracter(simbolo) a
int suma(char a) {
	int n = 0;

	if (a == 'B')
		n = B;
	if (a == 'U')
		n = U;	
	if (a == 'S')
		n = S;
	if (a == 'P')
		n = P;
	if (a == 'F')
		n = F;
	if (a == 'T')
		n = T;
	if (a == 'M')
		n = M;
	
	return n;
}

void solve() {
	string w;
	cin >> w;

	int total = suma(w[0]);	//Caso base del bucle, y cadenas de 1 elemento
	bool error = false;	//Por la monotonia de la cadena
	if(w.length() != 1) {
		char s = w[0];	//Simbolo actual
		int numS = 1;	//Apariciones del simbolo actual
		short monot = UNKNOWN;
		for(int i = 1; i < w.length(); ++i) {
			if (s == w[i])	//Contador de apariciones del simbolo actual
				numS++;
			else {
				s = w[i];
				numS = 1;
			}
			//Comprobamos monotonia, y el numero de apariciones
			if (((monot == CRECE) && (comparar(w[i], w[i-1]))) ||
			((monot == DECRECE) && (comparar(w[i-1], w[i]))) || (numS >= MAX_APARICIONES)) {
				error = true;
				break;
			}
			else {	//Sumar elemento
				total += suma(w[i]);
				if (comparar(w[i], w[i-1]))	//Fijar monotonia
					monot = DECRECE;
				else if (comparar(w[i-1], w[i]))
					monot = CRECE;
			}
		}
	}
	if (error)
		cout << "error\n";
	else
		cout << total << endl;

}

int main() {
	int ncasos;
	for (cin >> ncasos; ncasos > 0; ncasos--) {
		solve();
	}
}
