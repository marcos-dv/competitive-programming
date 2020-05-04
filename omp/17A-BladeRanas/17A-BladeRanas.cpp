#include <iostream>

using namespace std;

void print(string t[], int n) {
	for(int i = 0; i < n; ++i)
		cout << t[i] << endl;
}

bool fin(string t[], int i, int j, int n, int m) {
	if((i >= n) || (j >= m) || (i < 0) || (j < 0) || (t[i][j] == '#'))
		return true;
	return false;
}

//Ranas comibles desde la posicion (a,b)
int comida(string t[], int a, int b, int n, int m) {
	if (t[a][b]=='#')
		return 0;
	int i;
	int j;
	int ranas = 0;
	if (t[a][b]=='R')
		ranas = 1;
	
	//Hori Vert
	for(i = a+1, j = b; !fin(t,i,j,n,m); ++i)
		if (t[i][j] == 'R')	ranas++;
	for(i = a-1, j = b; !fin(t,i,j,n,m); --i)
		if (t[i][j] == 'R')	ranas++;
	for(i = a, j = b+1; !fin(t,i,j,n,m); ++j)
		if (t[i][j] == 'R')	ranas++;
	for(i = a, j = b-1; !fin(t,i,j,n,m); --j)
		if (t[i][j] == 'R')	ranas++;
	//Diagonales
	for(i = a+1, j = b+1; !fin(t,i,j,n,m); ++i, ++j)
		if (t[i][j] == 'R')	ranas++;
	for(i = a+1, j = b-1; !fin(t,i,j,n,m); ++i, --j)
		if (t[i][j] == 'R')	ranas++;
	for(i = a-1, j = b+1; !fin(t,i,j,n,m); --i, ++j)
		if (t[i][j] == 'R')	ranas++;
	for(i = a-1, j = b-1; !fin(t,i,j,n,m); --i, --j)
		if (t[i][j] == 'R')	ranas++;
	return ranas;
}

void solve() {
	int n, m;
	cin >> n >> m;
	string s;
	string t[n];
	for(int i = 0; i < n; ++i) {
		cin >> s;
		t[i] = s;
	}
	//print(t, n);
	int maxComida = -1;
	int maxPosX = 1;
	int maxPosY = 1;
	int comidaAct = -1;
	//Recorrido exhaustivo por el tablero
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			comidaAct = comida(t,i,j,n,m);
			if (comidaAct > maxComida) {
				maxComida = comidaAct;
				maxPosX = i+1;
				maxPosY = j+1;
			}
		}
	}
	cout << maxPosX << ' ' << maxPosY << '\n';
}

int main() {
	int ncasos;
	for(cin >> ncasos; ncasos > 0; ncasos--)
		solve();
}
