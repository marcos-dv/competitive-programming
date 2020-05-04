#include <iostream>

using namespace std;

/*

No podremos alcanzar una casilla cuando sea de otro color. En este caso,
si estamos en la casilla (a, b), y a+b % 2 = 0; entonces no alcanzaremos las casillas
(c, d), con c+d % 2 = 1.

Dada la casilla (a, b), otra casilla (c, d) esta en sus diagonales si y solo si
existe un m tal que (c, d) es:

(a+m, b+m)
(a-m, b+m)
(a+m, b-m)
(a-m, b-m)

En este caso, necesitamos unicamente de 1 movimiento.

Tomando m = |c-a|, debe cumplirse que b = d+m, o b = d-m.

Nos damos cuenta, de que ademas, el numero maximo de movimientos minimos sera 2.
(Todas las diagonales (no secantes) del tablero estan conectadas entre si a traves de otra diagonal)

*/

void solve(long long int n) {
	long long int a, b, c, d;
	cin >> a >> b >> c >> d;
	if((a == c) && (b == d))	//Misma casilla
		cout << "0\n";
	
	else if (((a+b)%2) != ((c+d)%2))	//Comprobamos que es valido
		cout << "no move\n";
	else {
		int m = 0;
		if (c > a)
			m = c-a;
		else
			m = a-c;
		if ((b == d+m) || (b == d-m))			
			cout << "1\n";	//Esta en diagonal
		else
			cout << "2\n";	//No esta en diagonal
	}
}

int main() {
	int ncasos, ntests;
	long long size;
	for(cin >> ncasos; ncasos > 0; --ncasos) {
		cin >> ntests;
		cin >> size;
		for(; ntests > 0; --ntests)
			solve(size);
	}
}

