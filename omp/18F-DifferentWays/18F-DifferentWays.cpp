#include <bits/stdc++.h>

using namespace std;

//dp, alternativa: usar casos posibles (posibles opciones de desplazamiento a izq o derecha)

int main() {
	int nc;
	cin >> nc;
	long long dp[50][50];
	memset(dp, 0, sizeof(dp));
	dp[1][24] = 1;
	dp[1][23] = 1;
	dp[1][25] = 1;
	for(int f = 2; f <= 40; ++f) {
		for(int c = 3; c < 45; ++c)
			dp[f][c] += dp[f-1][c-1] + dp[f-1][c] + dp[f-1][c+1];
	}
	
	
	while (nc--) {
		int n;
		cin >> n;
		cout << dp[n][24] << endl;
	}
}
