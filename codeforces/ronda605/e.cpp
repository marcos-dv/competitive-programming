#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int MAXN = 200005;
int n;
int a[MAXN];
bool vi[MAXN];
int sol[MAXN];
vector<vector<int>> ady;

//bfs multi-source, desde muchas fuentes
void bfs(){
	int nivel = 1; // distancia
	queue<int> q;
	for(int i = 1; i <= n; ++i) {
		int j1 = i-a[i];
		int j2 = i+a[i];
		if(j1 >= 1 && j1 <= n && ((a[i] & 1) != (a[j1] & 1)))
			q.push(i); 	
		if(j2 >= 1 && j2 <= n && ((a[i] & 1) != (a[j2] & 1)))
			q.push(i);
	}
	
	while(!q.empty()) { // una cola por nivel
		queue<int> t; // t es la cola del siguiente nivel
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			if(vi[u])
				continue;
			vi[u] = true;
			sol[u] = nivel;
 
			for(auto x : ady[u]){
				t.push(x);
			}
		}
		q = t;
		nivel++;
	}
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n;
	ady.resize(n+3);
	for(int i = 1; i <= n; ++i)  {
		cin >> a[i];
		int j1 = i-a[i]; //saltos
		int j2 = i+a[i];
		if(j1 > 0 && j1 <= n) ady[j1].pb(i);
		if(j2 > 0 && j2 <= n) ady[j2].pb(i);
	}
	for(int i = 1; i <= n; ++i)
		sol[i] = -1;
	
	bfs();
	for(int i = 1; i <= n; ++i) {
		cout << sol[i] << " ";
	}
	cout << endl;
}
