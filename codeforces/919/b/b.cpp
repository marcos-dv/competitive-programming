#include <iostream>

using namespace std;
#define MAX 10001

bool esPerfecto (long n) {
	int suma = 0;
	for(long cifra = n%10; n > 0; cifra = n%10) {
		suma += cifra;
		n /= 10;
	}
	return (suma == 10);
}

long * perfectos () {
	long * perfectos = new long[MAX];
	int i = 0;
	long j = 19;
	while (i < MAX) {
		if (esPerfecto(j))
			perfectos[i++] = j;
		j++;
	}
	return perfectos;
}

int main() {
	long * perf = perfectos();
	int k;
	cin >> k;
	cout << perf[k-1];
	delete perf;
}
