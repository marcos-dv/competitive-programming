//https://codeforces.com/problemset/problem/1061/B
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000007

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
	ll n, m;
	cin >> n >> m;
	ll h[n];
	ll maxi = -1;
	for(int i = 0; i < n; ++i) {
		cin >> h[i];
		maxi = max(maxi, h[i]);
	}
	ll sum = h[i]
	
	
	
	
	
	
	
	
	
	
	cout << sol << endl;
}
