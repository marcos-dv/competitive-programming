#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
/*
 Programacion dinamica
 
 Casos posibles = permutaciones
 Casos favorables:
 Conocido dp[n]
 1 2 3 ... n
 Calculamos dp[n+1]:
 Para el n+1 hay n opciones de gorro, fijada una (sea 1) queda:
 
 1 2 3 ...... n
 2 3 4    n n+1
 -Son las opciones de dp[n]! Pero hay mas, si 1 va con el n+1 (que ahora si puede, porque es n+1 no 1), nos queda
 2 3 ... n
 2 3 ... n
 Que son dp[n-1] posibilidades.
 dp[n+1] = n*(dp[n]+dp[n-1])
 
 
 Alternativa en concurso: Backtracking dejando calcular todo (2 <= n <= 12).
 Cuando termine, hacer programa con todas las soluciones explicitas
 
*/

int main() {
	ll fact[15];
	ll dp[15];
	fact[0] = 1;
	for(int i = 1; i < 15; ++i)
		fact[i] = fact[i-1]*i;
	dp[2] = 1;
	dp[3] = 2;
	for(int i = 4; i < 15; ++i)
		dp[i] = (i-1)*(dp[i-1]+dp[i-2]);
	int nc;
	cin >> nc;
	while (nc--) {
		int n;
		cin >> n;
		cout << dp[n] << "/" << fact[n] << endl;
	}
}



