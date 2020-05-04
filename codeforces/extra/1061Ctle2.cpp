//https://codeforces.com/problemset/problem/1061/C
#include <iostream>
#define MOD 10000007

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
	ll a[n+1] ;
	//dp[i][j]
	ll * dp = new ll[n+1];
	ll * aux;
	//dp[i-1][j]
	ll * pre = new ll[n+1];
	ll sol = 0;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	//Inicializacion
	//j = 0 -> dp[i][0] = 0
	//i = 0 -> dp[i][0] = 0
	//i = 1 -> dp[1][j] = 0 1 0 0 0 0 0 0...
	//j = 1 -> dp[i][1] = i
	for(int j = 0; j <= n; ++j) {
		dp[j] = 0;
		pre[j] = 0;
	}
	dp[1] = 1;
	pre[1] = 1;
//	for(int j = 1; j <= n; ++j)
	//	cerr << pre[j] << ' ';
	//cerr << endl;

	//Itera en filas
	for(int i = 2; i <= n; ++i) {
		dp[1] = i;
		//cerr << dp[1] << ' ';
		for(int j = 2; j <= i; ++j) { //Actualiza array
			if (a[i]%j == 0) {
				dp[j] = (pre[j] + pre[j-1]) % MOD;
			}
			else {
				dp[j] = pre[j];
			}
			//cerr << dp[j] << ' ';
		}
		//cerr << endl;
		//Actualiza el anterior
		aux = pre;
		pre = dp;
		dp = aux;
	}
	
	//Sol
	for(int j = 1; j <= n; ++j) {
		sol=(sol+pre[j])%MOD;
	}
	cout << sol << endl;
	delete pre;
	delete dp;
}
