#include <bits/stdc++.h>

using namespace std;

//Backtracking (TLE)

int w, h;
bool ** par;
int * paresfila;
int * pri;
int * se;
int pares;

//Quedan k pares, estamos en fila f, columna c
inline int bt(int k, int f, int c, int mov) {
	if (k == 0) {
		return mov;
	}
	if (paresfila[f] == 0) {
		return bt(k,f+1,c,++mov);
	}

	k-=paresfila[f];
	//Dividir
	if ((pri[f] < c) && (se[f] > c)) {
		int mizq = mov;
		mizq += abs(c-pri[f]);
		mizq += abs(se[f]-pri[f]);
		if (k != 0)
			mizq++;
		mizq = bt(k, f+1, se[f], mizq);

		int mder = mov;
		mder += abs(c-se[f]);
		mder += abs(se[f]-pri[f]);
		if (k != 0)
			mder++;
		mder = bt(k, f+1, pri[f], mder);
		
		return min(mizq, mder);
	}
	else {
		if (abs(c-pri[f]) < abs(c-se[f])) {
			mov += abs(c-pri[f]);
			mov += abs(se[f]-pri[f]);
			c = se[f];
		}
		else {
			mov += abs(c-se[f]);
			mov += abs(se[f]-pri[f]);
			c = pri[f];
		}
		if (k != 0)
			mov++;
		return bt(k, f+1, c, mov);
	}
}







int main() {
	int nc;
	cin >> nc;
	while (nc--) {

		cin >> w >> h;
		par = new bool * [h];
		for(int i = 0; i < h; i++)
			par[i] = new bool[w];
			
		paresfila = new int[h];
		pri = new int[h];
		se = new int[h];
		pares = 0;
		
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
					pares++;
				}
			}
		//	cerr << "Fila = " << i << " | PRI = " << pri[i] << " | SEC = " << se[i] << endl;
		}
		
		/*
		for(int i = 0; i < h; ++i)
		for(int j = 0; j < w; ++j) {
			cerr << par[i][j];
			if (j == w-1)
				cerr << endl;		
		}
		*/
		
		if (pares == 0) {
			cout << '0' << endl;
			continue;
			for(int i = 0; i < h; i++)
				delete par[i];
			delete par;
			delete paresfila;
			delete pri;
			delete se;
		}
		
		int mov = 0;
		int fila = 0;
		int col = 0;
		mov = bt(pares, fila, col, mov);
	//	cerr << "pares = " << pares << endl;
		/*while (pares > 0) {
			if (paresfila[fila] > 0) {
				//cerr << "FILA " << fila << endl;
				if (abs(col-pri[fila]) < abs(col-se[fila])) {
					//
					mov += abs(col-pri[fila]);
					mov += abs(se[fila]-pri[fila]);
					col = se[fila];
				}
				else {
					mov += abs(col-se[fila]);
					mov += abs(se[fila]-pri[fila]);
					col = pri[fila];
				}
				pares-=paresfila[fila];
			}
			fila++;
			if (pares)
				mov++;
		}
		*/
		cout << mov << endl;
		
		for(int i = 0; i < h; i++)
			delete par[i];
		delete par;
		delete paresfila;
		delete pri;
		delete se;
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
2
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
