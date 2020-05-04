#include <iostream>
using namespace std;

int meseta (string v, int k) {
	int mesetas = 0;
	int consec = 0;
	if (k > v.length())
		return 0;
	for(int i = 0; i < v.length(); ++i) {
		if (v[i] == '*')
			consec = 0;
		else {
			consec++;
			if (consec >= k)
				mesetas++;
		}
	}
	return mesetas;
}

int main() {

	int n, m, k;
	int formas = 0;
	cin >> n >> m >> k;
	
	string M [n];
	for(int i = 0; i < n; ++i) {
		cin >> M[i];
		formas += meseta(M[i], k);
	}

	//Columnas
	if (k != 1) {	//Para no repetir
		for (int j = 0; j < m; ++j) {
			string v = "";
			for(int i = 0; i < n; ++i)
				v+=M[i][j];
			formas += meseta(v, k);
		}
	}
	
	cout << formas;

}
