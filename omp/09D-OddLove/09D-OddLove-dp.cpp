#include <bits/stdc++.h>

using namespace std;

//Programacion dinamica

bool ** par;

int main() {
	int nc;
	cin >> nc;
	while (nc--) {
		int w, h, ultimaFila;
		vector<int> pri; // primer par en la fila
		vector<int> se; //segundo par en la fila
		vector<int> paresfila; // pares por fila
		//dp[0][k] = minimo numero de movimientos para en la fila k
		//acabar en el numero par de la izquierda
		//dp[1][k] = igual que pero acabar en el par de la derecha
		vector<int> dp[2];

		cin >> w >> h;
		
		par = new bool * [h];
		for(int i = 0; i < h; i++)
			par[i] = new bool[w];
			
		paresfila.resize(h);
		paresfila.clear();
		pri.resize(h);
		pri.clear();
		se.clear();
		se.resize(h);
		dp[0].resize(h);
		dp[1].resize(h);
		dp[0].clear();
		dp[1].clear();
		ultimaFila = -1;
		
		for(int i = 0; i < h; ++i)
		for(int j = 0; j < w; ++j)
			par[i][j] = false;

		for(int i = 0; i < h; i++) {
			paresfila[i] = 0;
			pri[i] = 100000;
			se[i] = -1;
		}

		string s;
		for(int i = 0; i < h; i++) {
			cin >> s;
			for(int j = 0; j < w; ++j) {
				par[i][j] = (((s[j]-'0') % 2) == 0);
				if (par[i][j]) {
					pri[i] = min(pri[i], j);
					se[i] = max(se[i], j);
					paresfila[i]++;
					ultimaFila = i;
				}
			}
		}
		
		if (ultimaFila < 0) {
			cout << '0' << endl;
			continue;
			for(int i = 0; i < h; i++)
				delete par[i];
			delete par;
		}
		
		// Caso base
		if (paresfila[0] == 0) {
			dp[0][0] = 0;
			dp[1][0] = 0;
		}
		else {
			dp[0][0] = se[0]+(se[0]-pri[0]);
			dp[1][0] = se[0];
		}
		
		for(int fila = 1; fila <= ultimaFila; ++fila) {
			if (paresfila[fila] == 0) {
				dp[0][fila] = dp[0][fila-1]+1;
				dp[1][fila] = dp[1][fila-1]+1;
			}
			else {
				// actualizar dp[0] (acabamos en la izq)
				// 2 casos: venimos de la izquierda, o venimos de derecha
				// izq
				int izq = dp[0][fila-1]+1;
				int dcha = dp[1][fila-1]+1; // valor de venir de izq, o venir dcha
				int col = -1;
				// buscamos la columna de la que venimos
				for(int ff = fila-1; ff >= 0; --ff) {
					if (paresfila[ff] > 0) {
						col = pri[ff];
						break;
					}
				}
				if (col == -1)
					col = 0;
				// vamos a la derecha, y luego a la izquierda
				izq += abs(col-se[fila]);
				izq += abs(se[fila]-pri[fila]);
				// dcha
				for(int ff = fila-1; ff >= 0; --ff) {
					if (paresfila[ff] > 0) {
						col = se[ff];
						break;
					}
				}
				if (col == -1)
					col = 0;
				// vamos a la derecha, y luego a la izquierda
				dcha += abs(col-se[fila]);
				dcha += abs(se[fila]-pri[fila]);
				
				// cogemos el minimo camino
				dp[0][fila] += min(izq, dcha);

				// actualizar dp[1] (acabamos en la dcha)
				// 2 casos: venimos de la izquierda, o venimos de derecha
				// izq
				izq = dp[0][fila-1]+1;
				dcha = dp[1][fila-1]+1; // valor de venir de izq, o venir dcha
				col = -1;
				// buscamos la columna de la que venimos
				for(int ff = fila-1; ff >= 0; --ff) {
					if (paresfila[ff] > 0) {
						col = pri[ff];
						break;
					}
				}
				if (col == -1)
					col = 0;
				// vamos a la izquierda, y luego a la derecha
				izq += abs(col-pri[fila]);
				izq += abs(pri[fila]-se[fila]);
				// dcha
				for(int ff = fila-1; ff >= 0; --ff) {
					if (paresfila[ff] > 0) {
						col = se[ff];
						break;
					}
				}
				if (col == -1)
					col = 0;
				// vamos a la izquierda, y luego a la derecha
				dcha += abs(col-pri[fila]);
				dcha += abs(pri[fila]-se[fila]);
				
				// cogemos el minimo camino
				dp[1][fila] += min(izq, dcha);
			}
		}
		
		cout << min(dp[0][ultimaFila], dp[1][ultimaFila]) << endl;

		for(int i = 0; i < h; i++)
			delete par[i];
		delete par;

	}
}


/*
7
5 3
54578
36329
75241
9 1
759456785
2 2
22
22
6 6
777777
772777
777777
777727
727777
777777
7 7
1811181
1118811
1881111
8111111
1188181
1881181
1111111
8 3
29511211
59356961
25299669
6 4
846817
645887
715322
558583
*/
