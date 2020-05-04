#include <iostream>

using namespace std;

#define MAX_VALUE 85

//Devuelve un array con los n primeros numeros de fibonacci
//la posicion [0] contiene 0, y [1] 1.
long long * fibonacci(int n) {
	long long * fibo = new long long int [n];
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i < n; ++i)
		fibo[i] = fibo[i-1] + fibo[i-2];
	return fibo;
}

int main() {
	int altura;
	long long * fibo = fibonacci(MAX_VALUE+1);
	while(true) {
		cin >> altura;
		if (altura == 0)
			break;
		cout << fibo[altura] << '\n';
	}
	delete(fibo);
}
