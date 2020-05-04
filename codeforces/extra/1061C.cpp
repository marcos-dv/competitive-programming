//https://codeforces.com/problemset/problem/1061/C
#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

//DP
/*
	dp[i][j] = formas de coger entre los i primeros elementos, subsec buenas de j elementos
	(1 <= i,j <= n)
	Seran las de antes dp[i-1][j] + las nuevas por el elemento ai. Lo podremos usar si es el
	j-esimo elemento -> antes habia una bien formada de j-1 elementos, y eso pasa cuando j|a[i]  
	Luego:
	dp[i][j] = dp[i-1][j] + dp[i-1][j-1] si j|a[i]
	dp[i][j] = dp[i-1][j] otro caso
	Sol = Sum en j de dp[n][j]
	
	No entra en espacio -> 1 dimension
 
 	Mejora: dp se actualiza solo en los divisores de a[i]
	No hace falta recordar la fila anterior si recorremos de derecha a izquierda

Ejemplo:

	1 2 3 4 5
  2 1 0 0 0 0
  2 2 1 0 0 0
  1 3 1 0 0 0
 22 4 4 0 0 0
 14 5 8 0 0 0

*/

using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	ll a[n+1];
	//dp[i][j]
	ll dp[n+1];
	ll sol = 0;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	//Inicializacion
	//j = 0 -> dp[i][0] = ? (conviene 1)
	//i = 0 -> dp[i][0] = 0
	//i = 1 -> dp[1][j] = 0 1 0 0 0 0 0 0...
	//j = 1 -> dp[i][1] = i
	dp[0] = 1;
	for(int j = 1; j <= n; ++j) {
		dp[j] = 0;
	}

	//Itera en filas
	for(int i = 1; i <= n; ++i) {
		vector<ll> div;
		//Calcula los divisores de a[i]
		for(int k = 1; k*k <= a[i]; ++k) {
			if (a[i]%k == 0) {
				div.push_back(k);
				if (k*k != a[i]) {
					div.push_back(a[i]/k);
				}
			}
		}
		sort(div.begin(), div.end());
		//Actualizamos de derecha a izquierda
		//Asi no hace falta recordar la fila anterior
		reverse(div.begin(), div.end());
		
		//Iteramos los divisores de derecha a izquierda
		for(int divi = 0; divi < (int)div.size(); ++divi) { //Actualiza array
			if (div[divi] > n)	//out of bounds
				continue;
			dp[div[divi]] = (dp[div[divi]] + dp[div[divi]-1]) % MOD;
		}
		
	}
	
	//Sol
	for(int j = 1; j <= n; ++j) {
		sol=(sol+dp[j])%MOD;
	}
	cout << sol << endl;
}
