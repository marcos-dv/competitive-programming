#include <bits/stdc++.h>
#define MAXN 1010
#define fi first
#define se second
using namespace std;

//dfs por el grafo, marcas de retroceso para saber cuando hemos entrado en bucle

bool vi[MAXN];
bool retro[MAXN]; //marca de retroceso
pair<char, int> p[MAXN];
bool bucle;

void dfs(int i) {
	retro[i] = true;
	vi[i] = true;
	
	if (p[i].fi == 'A') {
		if (!vi[i+1])
			dfs(i+1);
		if (retro[i+1])
			bucle = true;
	}
	else if (p[i].fi == 'J') {
		if (!vi[p[i].se])
			dfs(p[i].se);
		if (retro[p[i].se])
			bucle = true;
	}
	else if (p[i].fi == 'C'){
		//1 vecino
		if (!vi[i+1])
			dfs(i+1);
		if (retro[i+1])
			bucle = true;
		//2 vecino
		if (!vi[p[i].se])
			dfs(p[i].se);
		if (retro[p[i].se])
			bucle = true;
	}
	retro[i] = false;
}

int main() {
	int nc;
	cin >> nc;
	while(nc--) {
		int n;
		cin >> n;
		memset(vi, 0, sizeof(vi));
		memset(retro, 0, sizeof(retro));
		memset(p, 0, sizeof(p));
		for(int i = 1; i <= n; ++i) {
			char ins;
			cin >> ins;
			p[i].fi = ins;
			if (ins != 'A') {
				cin >> p[i].se;
			}
		}
		bucle = false;
		dfs(1);
		if (vi[n+1] && !bucle) {
			cout << "ALWAYS" << endl;
		} 
		if (vi[n+1] && bucle) {
			cout << "SOMETIMES" << endl;
		
		} 
		if (!vi[n+1]) {
			cout << "NEVER" << endl;
		}
	}
}
