#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define N 1000000007
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;

/*
	Floyd + Greedy
	Greedy: Para cada 1<=j<=m;
	Sea vi el ultimo nodo anadido, ver si dist(vi,pi) < dist(vi,pi-1)+dist(pi-1, pi)
	Entonces anadir pi al camino optimo
*/


int main() {
	int n;
	cin >> n;
	string adj[n];
	for(int i = 0; i < n; ++i)
		cin >> adj[i];
	int m;
	cin >> m;
	int p[m];
	for(int i = 0; i < m; ++i)
		cin >> p[i];
	//floyd
	int D[n][n];
	//int P[n][n];
	for(int i = 0; i < n; ++i)
	for(int j = 0; j < n; ++j) {
		D[i][j] = 100000;
//		P[i][j] = i;
	}
	for(int i = 0; i < n; ++i)
	for(int j = 0; j < n; ++j) {
		if (adj[i][j] == '1')
			D[i][j] = 1;
	}
	for(int i = 0; i < n; ++i)
		D[i][i] = 0;
	
	for(int k = 0; k < n; ++k)
	for(int i = 0; i < n; ++i)
	for(int j = 0; j < n; ++j)
			D[i][j] = min(D[i][j], D[i][k]+D[k][j]);

/*			
	for(int i = 0; i < n; ++i) {
	for(int j = 0; j < n; ++j) {
		cout << D[i][j] << ' ';
	}
	cout << endl;
	}
*/

	vector<int> v;
	v.pb(p[0]);
	int nn = 1; //num nodos subseq
	int fin = p[m-1];
	for(int i = 1; i < m-1; ++i) {
		int dist1 = D[v[nn-1]-1][p[i+1]-1];
		int dist2 = D[v[nn-1]-1][p[i]-1] + D[p[i]-1][p[i+1]-1];
		if (dist1 < dist2) {
			v.pb(p[i]);
			++nn;
		}
	}
	v.pb(fin);
	++nn;
	cout << nn << endl;
	for(int i = 0; i < nn; ++i)
		cout << v[i] << ' ';
}


