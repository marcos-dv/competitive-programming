#include <iostream>

using namespace std;

/*

Dados 4 enteros positivos:
a b c d
Forman cuadrado sii son iguales
Forman rectangulo sii son iguales 2 a 2
Forman cuadrilatero sii cumplen todos la desigualdad triangular
Que se reduce a que:
d < SUM(a b c)
2d < SUM(a b c d)
alternativamente con x recorriendo a b c d:
x < SUM(a b c d)/2
para x = a, b, c, d

*/


//v denota un array de 4 enteros positivos
bool esCuadrado(int v[]) {
	return ((v[0] == v[1]) && (v[0] == v[2]) && (v[0] == v[3]));
}

//Igualdad 2 a 2
bool esRectangulo(int v[]) {
	return (((v[0] == v[1]) && (v[2] == v[3])) ||
		((v[0] == v[2]) && (v[1] == v[3])) ||
		((v[0] == v[3]) && (v[1] == v[2])));
}

bool esCuadrilatero(int v[]) {
	double suma = 0;
	for(int i = 0; i < 4; ++i)
		suma += v[i];
	suma = suma/2;
	return (((double)v[0] < suma) && 
		((double)v[1] < suma) && 
		((double)v[2] < suma) && 
		((double)v[3] < suma));
}

//Resuelve individualmente un problema
void solve() {
	int v[4];
	for (int i = 0; i < 4; ++i)
		cin >> v[i];
	if (esCuadrado(v))
		cout << "square" << '\n';
	else if (esRectangulo(v))
		cout << "rectangle" << '\n';
	else if (esCuadrilatero(v))
		cout << "quadrangle" << '\n';
	else
		cout << "banana" << '\n';
}

int main() {
	int ncasos;
	for(cin >> ncasos; ncasos > 0; --ncasos)
		solve();
}
