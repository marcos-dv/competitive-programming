#include <iostream>
#include <set>
using namespace std;

int main() {
	long long a, b, p, x, m, k;

	cin >> a >> b >> p >> x;
	//Iteramos para cada candidato n, si cumple la ecuacion
	for (long long n = 1; n <= x; ++n) {
		m = n/p;
		k = n%p;
		int exponente = m+k;
		//Calcular la ultima cifra de k*a^k
		cifraA = a%p;
		cifra = 1;
		for(int j = 0; j < exponente; ++j)
			cifra = (cifra*cifraA)%p;
	
		cifra = (cifra*k)%p;
		if (cifra == b)
			candidatos++;
	}
	cout << candidatos;
}
