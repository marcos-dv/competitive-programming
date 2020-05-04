#include <iostream>
#include <limits>
using namespace std;

/* a y b cadenas; operaciones: insertar, borrar, sustituir
d(n, m) = 
	SI a[n] = b[m]
		d(n-1, m-1)
	SINO
	1+min {
		d(n-1, m)	//Eliminar
		d(n, m-1)	//Insertar
		d(n-1, m-1)	/Sustitucion
}

Casos base:

SI n = 0
	return m
SI m = 0;
	return n;
si n, m < 0, return +inf (base minimizar)

*/

//Variables globales
string a, b;


//Minimo
double min(double a, double b, double c) {
	if ((a < b) && (a < c))
		return a;
	if (b < c)
		return b;
	return c;
}

//Rellenar campos de la tabla
double d(double ** D, int i, int j) {
	//CASOS BASE
	if (i == 0)
		return j;
	if (j == 0)
		return i;
//	if ((i < 0) && (j < 0))	//No lo usamos nunca
//		return numeric_limits<double>::infinity();
	
	//CASOS RECURSIVOS
	if (a[i-1] == b[j-1])		//Ojo, los caracteres en el string estan desplazados respecto a la tabla
		return D[i-1][j-1];
	else
		return 1+min(D[i-1][j-1], D[i-1][j], D[i][j-1]);

}

//Devuelve la distancia de edicion entre las cadenas a y b
int editDistance(double ** D, int n, int m) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			D[i][j] = d(D, i, j);
	return (int) D[n-1][m-1];
	
}

//Resuelve un problema individual
void solve() {

	getline(cin, a);
	getline(cin, b);		
	int n = 1+a.length();
	int m = 1+b.length();	
	double ** D = new double * [n];
	for (int i = 0; i < n; ++i)
		D[i] = new double[m];

	cout << editDistance(D, n, m) << '\n';
}

int main() {
	int ncasos;
	cin >> ncasos;
	for (getline(cin, a); ncasos > 0; --ncasos)
		solve();
	
}
