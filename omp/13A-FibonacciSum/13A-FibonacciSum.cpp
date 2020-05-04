#include <iostream>

using namespace std;

/*

Echando un vistazo a la sucesion, apreciamos que se repite cada 300 numeros
(debido a que solo hay 100 posibles digitos, en algun momento tendria que repetirse,
al depender de los 2 numeros anteriores).

En otras palabras, el numero en la posicion k, valdra lo mismo que el de k%300.

1 -> 1
2 -> 1
...
299 -> 1
300 -> 0
301 -> 1	(BUCLE)
302 -> 1
...

La suma de los 300 primeros es 14800, lo cual simplificara los calculos.
Dadas las posiciones a y b, bastara con ver cuantos bloques de "300" hay entre ellos,
y despues calcular, (x' = x%300) si a' < b', calcular la suma de los fibo[i], con a' < i <= b',
en otro caso, la suma de los fibo[i] con i > a'; i <= b',
para adherirla a los bloques previamente calculados.

*/

const int M = 100;	//Modulo
const int N = 300;	//Numeros por ciclo
const int SUMA = 14800;	//Suma por ciclo

int fibo[N];	//Numeros de fibonacci%100

void initFibo() {
	fibo[0] = 0;
	fibo[1] = 1;
	fibo[2] = 1;
	for (int i = 3; i < N; ++i)
		fibo[i] = (fibo[i-1] + fibo[i-2]) % M;
}

//Devuelve la suma de los numeros entre las posiciones a y b
long long int solve(long long int a, long long int b) {
	long long int diferencia = b-a+1;
	
	//diferencia = N*bloques + sumandos
	
	//Bloques
	long long int bloques = diferencia/N;
	long long int suma = bloques*SUMA;
	//Otros sumandos
	long long int sumandos = diferencia%N;
	for(long long int i = a; i < a+sumandos; ++i)
		suma+=fibo[i%N];

	return suma;
}


int main() {
	int ncasos;
	long long int a, b;
	initFibo();
	for(cin >> ncasos; ncasos > 0; ncasos--) {
		cin >> a >> b;
		cout << solve(a, b) << '\n';
	}
}
