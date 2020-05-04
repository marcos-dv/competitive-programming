#include <iostream>
#include <math.h>	//sqrt

using namespace std;

/*

n-px es maximo
p = [n/x]

n-x*[n/x]
max {n-x*[n/x] | x<n un numero primo}
Es decir,
min { x*[n/x] | con x<n un numero primo }

f(x) = x*[n/x]

Para x > 0, f es decreciente, y vale 0 a partir de x = n.
f es discontinua cuando n/x es un entero, es decir, n/x = m;
si y solo si x = n/m. Entre 2 puntos de discontinuidad,
f crece, es decir, podemos intuir que el minimo se encuentra en
una discontinuidad. Las discontinuidades son cada vez menores segun
aumenta x, por lo que el minimo estara en la ultima discontinuidad,
antes de x = n (concretamente, "a la derecha" de la discontinuidad).

f(n) = n*[n/n], donde m = 1. La siguiente discontinuidad es m = 2, luego x = n/2.

El numero que buscamos es limDERECHA x-> n/2: x*[n/x] = n/2.
{ n/1.9 * [n/n/1.9] = n/1.9 * [1.9] = n/1.9 }

Como buscamos el valor por la derecha, el resultado sera el primo mas cercano por exceso,
a n/2.

*/

bool esPrimo(int n) {
	if (n < 4)
		return true;
	for (int i = 2; i <= sqrt(n); ++i)
		if (n%i == 0)
			return false;
	return true;
}

//Devuelve el siguiente primo, a partir de n
int sigPrimo(int n) {
	do {
		n++;
	} while (!esPrimo(n));
	return n;
}

void solve() {
	int n;
	cin >> n;
	cout << sigPrimo(n/2) << '\n';	
}

int main() {
	int ncasos;
	for(cin >> ncasos; ncasos > 0; ncasos--)
		solve();
}
