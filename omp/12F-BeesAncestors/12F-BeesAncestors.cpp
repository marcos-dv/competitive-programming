#include <iostream>

using namespace std;

#define N 84	//Maximo de generaciones

//Nos damos cuenta de que el numero de ancestros de Willy en una generacion siguen la sucesion de Fibonacci

long long int fibo[N];

void initFibo() {
	fibo[0] = 1;
	fibo[1] = 1;
	for(int i = 2; i < N; ++i)
		fibo[i] = fibo[i-1] + fibo[i-2];
}

int main() {
	int level;
	initFibo();
	while(true) {
		cin >> level;
		if (level == 0)
			break;
		cout << fibo[level] << '\n';
	}
}

