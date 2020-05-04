#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define N 1007
#define MOD 1000000007
using namespace std;
typedef long long ll;

int n, k, m, x, y, z;
string s;
int v[N+2];
ll dp[N];


int main() {
	
	while(cin >> n) {
		if (n == 0)
			break;
		memset(dp, 0, sizeof(dp));
		cin >> k;
		for(int i = 0; i < k; ++i) {
			cin >> v[i];
		}
		sort(v, v+k);
		dp[0] = 1;
		for (int i = 1; i <= n; i++) 
				for (int j = 0; j < k; j++) 
				    if (i >= v[j]) 
				        dp[i] = (dp[i]+dp[i-v[j]])%MOD; 
		cout << dp[n] << endl;
	}
	
}



