#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define MOD 1000000007

using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;	
	ll N,T,M,D,I;
	for(int i = 0; i < n; ++i) {
		cin >> N >> T >> M >> D >> I;
		ll sol = 0;
		sol += N*T;
		ll rests = (N-1)/M;
		ll plus = 0;
		
		sol += D*rests;
		sol += (I*(rests)*(rests-1))/2;
		
		cout << sol << endl;
	}
	
}



