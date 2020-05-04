#include <iostream>

using namespace std;

/*
Tenemos que calcular, dado s impar:

1+3+...+s-2+ s +s-2+...+1
s = 2n-1 => s+1/2 = n
La suma de los primeros n impares es n^2
s = 2n+1 => s-2 = 2n-1 es el impar n-esimo
Por lo que debemos hacer
2*n^2 + s
n = s-1/2
(s-1)^2/2 + s

Como s es del orden de 10^9, usamos long long
*/

int main() {
	int ncasos;
	long long s;
	for(cin >> ncasos; ncasos > 0; ncasos--) {
		cin >> s;
		cout << (s-1)*(s-1)/2 + s << endl;
	}
}
