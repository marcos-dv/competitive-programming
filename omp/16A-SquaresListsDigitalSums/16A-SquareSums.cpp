#include <iostream>
#include <math.h>	//sqrt
using namespace std;

//Devuelve true si n es un cuadrado
bool esCuadrado(int n) {
	int raiz = (int) sqrt(n);
	return (raiz*raiz == n);
}

//Devuelve la suma de las cifras de un numero
//En base 10
int sumDigits(int n) {
	int suma = 0;
	while(n > 0) {
		suma += n%10;
		n = n/10;
	}
	return suma;
}

//Devuelve el ultimo numero (> 9) de la secuencia
//de n elementos tales que su cuadrado
//cumple que la suma de sus cifras es un cuadrado
int findSeq(int n) {
	//Numeros consecutivos encontrados
	int counter = 0;
	//Primer numero a comprobar
	int i = 9;
	do {
		i++;
		if (esCuadrado(sumDigits(i*i)))
			counter++;
		else
			counter = 0;
	} while (counter < n);
	return i;
}

int main() {
	//Longitud de la secuencia
	int length = 7;
	//int n = findSeq(length);

	//Devuelve 10005
	int n = 10005;
	for (int i = n-length+1; i <= n; ++i)
		cout << i << ' ' << i*i << '\n';
}
