#include <bits/stdc++.h>
#define MAXN 13
using namespace std;
typedef long long ll;

/*
 Generar todas las cadenas de n-1 simbolos:
  < < <
  < = <
  = = <
  ...
  
  Y ver cuantas combinaciones genera cada una de ellas
  A < B = C < D = E = F
  
  n = 6
  A tiene 6 posibilidades
  B y C tienen (5 2)
  D, E, F tienen (3 3) (1 opcion solo, porque da igual D = E = F <=> E = F = D etc)
*/

//bug se generan 2 veces

ll nc[MAXN][MAXN];
char arr[MAXN];
int nn;
ll sum;

//numeros combinatorios
void init() {
	for(int i = 0; i < MAXN; ++i)
		nc[i][0] = 1;
	for(int i = 1; i < MAXN; ++i)
	for(int j = 1; j <= i; ++j)
		nc[i][j] = nc[i-1][j]+nc[i-1][j-1];
}

//genera las combinaciones
ll genera() {
	int eq = 1; // elementos en un igual;
	int i = 0;
	ll res = 1;
	int quedan = nn;
	while (i < nn-1) {
		if (arr[i] == '=') {
			eq++;
		}
		else {
			if (eq == 1)
				res *= quedan--;
			else {
				res *= nc[quedan][eq];
				quedan -= eq;
			}
			eq = 1;
		}
		++i;
	}
	if (eq == 1)
		res *= quedan--;
	else
		res *= nc[quedan][eq];
	
	return res;
}


void bt(int n, int j) {
	if (n == 0) {
		sum += genera();
	}
	if (n > 0) {
		arr[n-1] = '=';
		bt(n-1,j+1);
		arr[n-1] = '<';
		bt(n-1,j+1);
	}
}

int main() {
	init();
	ll sol[MAXN+1];
	sol[1] = 1;
	for(nn = 2; nn < MAXN; ++nn) {
		sum = 0;
		bt(nn, 0);
		sol[nn] = sum/2;
	}
	int casos;
	cin >> casos;
	while(casos--) {
		int nnn;
		cin >> nnn;
		cout << sol[nnn] << endl;
	}
}
