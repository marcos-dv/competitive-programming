#include <iostream>
#include <math.h>
using namespace std;

/*
	Dado un numero, hallar en que base, ese numero tiene el numero maximo de cuatros (la menor).
	Seguramente se pueda optimizar el algoritmo, pues al analizar la transformada de los numeros
	sucesivamente, suelen seguir un patron que podria agilizar los calculos.
*/

#define N 4 //Buscamos 'cuatros'

//Devuelve el numero de cuatros que tiene x en base b
long four (long x, long b) {
	long total = 0;
	while(x > 0) {
		if (x%b == N)
			total++;
		x /= b;
	}
	return total;
}

//Devuelve las cifras que tiene el numero x en la base b.
long cifras(long x, long b) {
	long cifras = 0;
	if (x == 0)
		return 1;
	while(x > 0) {
		x/=b;
		cifras++;
	}
	return cifras;
}

//Analizamos un numero, base a base, contando los 'cuatros' de cada representacion.
void solve() {
	long x;
	cin >> x;
	bool negativo = false;
	if (x < 0) {	//Trabajaremos con el valor absoluto
		negativo = true;
		x = -x;
	}
	long maxN = 0;		//Numero de cuatros
	long actualN = 0;
	long maxB = 0;		//Base
	long actualB = N+1;
	//Si tenemos mas cuatros que el numero de cifras, no es necesario seguir (pues las cifras solo decrecen)
	//Tampoco si la base alcanza al numero
	while ((maxN < cifras(x, actualB)) && (actualB < x)) {
		actualN = four(x, actualB);
		if (actualN > maxN) {
			maxN = actualN;
			maxB = actualB;
		}
		actualB++;
	}
	if (x == 4) {		//Caso especial que nuestro algoritmo no recoge
		if (negativo)
			x = -x;
		cout << x << " 1 5\n";
	}
	else if (maxB == 0) {	//No hemos hallado ninguna base con cuatros
		if (negativo)
			x = -x;
		cout << x << " is infuriable.\n";
	}
	else {
		if (negativo)
			x = -x;
		cout << x << ' ' << maxN << ' ' << maxB << '\n';
	}
}

int main() {
	int ncasos;
	for (cin >> ncasos; ncasos > 0; --ncasos) {
		solve();
	}
}
