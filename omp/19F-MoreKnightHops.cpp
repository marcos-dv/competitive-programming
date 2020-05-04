#include <bits/stdc++.h>
#define push_back pb

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MAXN = 1000006;
const ll INF = 1e18+8;

int n, arr[MAXN], d;
map<string, ll> fr;

ll s[6] = {4, 6, 8, 10, 12, 20}, prob[6];

int main() {
	int casos;
	cin >> casos;
	ll n,m;
	while(casos--){
		cin >> n >> m;
		if(m==3)
			cout << (n-2)*m*2+2<<endl;
		else
			cout <<(n-2)*(4*m-6)+2*m-4 << endl;
	}
}
