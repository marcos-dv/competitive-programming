#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
/*
 Programacion dinamica / greedy
 
 Dividir por 10 para reducir longitudes
 
 dp[n] = llegamos a comer n calorias (bool)
 
 dp[0] = 1
 Empieza desde el final a actualizar cosas
 for j = n-comida[i] hasta j = 0
 Si llegamos a comer j calorias, entonces comemos j+comida[i]
 
 Al hacerlo en orden inverso no hay problemas de colisiones. Si lo hacemos en orden descendente
 Hay problemas, contamos con datos falsos (comeremos dp[j], y dp[j+j], dp[j+j+j]...)
 En sentido inverso eso no pasa
 
 O(P*MAX_CALORIAS)
*/

int main() {
	int nc;
	cin >> nc;
	while (nc--) {
		int n, p;
		cin >> n >> p;
		n /= 10;
		int comida[p];
		int sum = 0;
		for(int i = 0; i < p; ++i) {
			cin >> comida[i];
			comida[i]/=10;
			sum += comida[i];
		}
		if (sum < n) {
			cout << "NO SOLUTION" << endl;
			continue;
		}
		//sort(comida, comida+p);
		int MAXM = 250*100+5; //maximo valor que sumaremos
		bool dp[MAXM];
		memset(dp, 0, sizeof(dp));
		dp[comida[0]] = true;
		dp[0] = true;
		for(int i = 1; i < p; ++i) {
			for(int j = MAXM-comida[i]; j >= 0; --j) {
					dp[j+comida[i]] |= dp[j];
			}
		}
		for(int i = n; i < MAXM; ++i) {
			if (dp[i]) {
				cout << i*10 << endl;
				break;
			}
		}
	}
}



