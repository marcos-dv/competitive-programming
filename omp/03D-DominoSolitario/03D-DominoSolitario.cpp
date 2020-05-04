#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
typedef pair<int, int> pii;

pii p1, p2;
vector<pii> piezas; // p[0] inicial, p[m+1] final
bool usadas[50];
int ult; //ultima usada
bool ori; //orientacion ult
bool sol;
int n;
int m;

inline void bt(int k) {
	if (sol)
		return ;
	if (k == 0) {
		sol = true;	
		return ;
	}
	if (k == 1) {
		int i = 1;
		while (i <= m) {
			if (ori) {
				if ((!usadas[i]) && (piezas[i].fi == piezas[ult].se) && (piezas[i].se == piezas[m+1].fi)) {
					bt(0);
				}
				else if ((!usadas[i]) && (piezas[i].se == piezas[ult].se) && (piezas[i].fi == piezas[m+1].fi)) {
					bt(0);
				}
			}
			else {
				if ((!usadas[i]) && (piezas[i].fi == piezas[ult].fi) && (piezas[i].se == piezas[m+1].fi)) {
					bt(0);
				}
				else if ((!usadas[i]) && (piezas[i].se == piezas[ult].fi) && (piezas[i].fi == piezas[m+1].fi)) {
					bt(0);
				}
			}
			i++;
		}
	}
	else {
		int i = 1;
		while (i <= m) {
			if (ori) {
				if ((!usadas[i]) && (piezas[i].fi == piezas[ult].se)) {
					usadas[i] = true;
					int aux = ult;
					bool aux2 = ori;
					ori = true;
					ult = i;
					bt(k-1);
					usadas[i] = false;
					ult = aux;
					ori = aux2;
				}
				else if ((!usadas[i]) && (piezas[i].se == piezas[ult].se)) {
					usadas[i] = true;
					int aux = ult;
					bool aux2 = ori;
					ori = false;
					ult = i;
					bt(k-1);
					usadas[i] = false;
					ult = aux;
					ori = aux2;
				}
			}
			else {
				if ((!usadas[i]) && (piezas[i].fi == piezas[ult].fi)) {
					usadas[i] = true;
					int aux = ult;
					bool aux2 = ori;
					ori = true;
					ult = i;
					bt(k-1);
					usadas[i] = false;
					ult = aux;
					ori = aux2;
				}
				else if ((!usadas[i]) && (piezas[i].se == piezas[ult].fi)) {
					usadas[i] = true;
					int aux = ult;
					bool aux2 = ori;
					ori = false;
					ult = i;
					bt(k-1);
					usadas[i] = false;
					ult = aux;
					ori = aux2;
				}
			}
			i++;
			
		}
	}
}
	
		
int main() {
	while(true) {
		sol = false;
		cin >> n;
		if (!n)
			break;
		cin >> m;
		piezas.clear();
		memset(usadas, false, sizeof(usadas));
		cin >> p1.fi >> p1.se;
		cin >> p2.fi >> p2.se;
		piezas.pb(p1);
		for(int i = 0; i < m; ++i) {
			pii p;
			cin >> p.fi >> p.se;
			piezas.pb(p);
		}
		piezas.pb(p2);
		
		if (n == 1) {
			for(int i = 1; i <= m; ++i) {
				if ((piezas[i].fi == p1.se) && (piezas[i].se == p2.fi)) {
					sol = true;
					break;
				}
			}
		}
		
		else {
			ult = 0;
			ori = true;
			bt(n);
		}
		
		if (sol)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

/*
3
4 
0 1 
3 4 
2 1 
5 6 
2 2 
3 2 
2 
4 
0 1 
3 4 
1 4 
4 4 
3 2 
5 6 
0

*/


