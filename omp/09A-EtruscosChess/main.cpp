#include <iostream>
#include <math.h>	//sqrt
using namespace std;

/*
Analizando el problema podemos ver que si hay x filas
el numero de etruscos sera de n tal que 
(x+2)*(x+1)/2 > n >= x*(x+1)/2 
(la suma de los primeros naturales)
Despejando x:
(x+2)*(x+1) > 2n >= x*(x+1)
x^2 + 3x + 2 > 2n >= x^2 + x
De donde:
x^2 + 3x + 2-2n > 0
Y
x^2 + x - 2n <= 0

x > (sqrt(1+8n)-3)/2
x <= (sqrt(1+8n)-1)/2

Entonces basta con truncar el segundo valor
*/




//Devuelve la cantidad de (los primeros) naturales sumados, si la suma es n
//Si la suma no es un numero triangular, se trunca para que lo sea
long long int inverseSum (long long int n) {
	return (long long int) (sqrt(1+8*n)-1)/2;
}

//Resuelve un problema individual, muestra el resultado por la salida
void solve() {
	long long nwarriors = 0;
	cin >> nwarriors;
	long long nrows = inverseSum(nwarriors);
	cout << nrows << '\n';
}


int main() {
	int ncasos;
	for(cin >> ncasos; ncasos > 0; ncasos--) {
		solve();
	}
}
