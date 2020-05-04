#include<bits/stdc++.h>
#define pb push_back
 
using namespace std;

/*
	Ventana deslizante
	Hallar el valor de K maximo que podemos obtener
	Despues, ordenar los elementos por su frecuencia
	Elegir el intervalo [l, r] de K elementos con menos cambios
*/

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	int I;
	cin >> n >> I;
	int a[n];
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	I *= 8;
	int k = I/n;
	int K = 1; // 2^k
	for(int i = 0; i < k; ++i) {
		K = min(K<<1, n);
	}
	
	sort(a, a+n);
	vector<int> freq;
	int val = 1;
	for(int i = 1; i < n; ++i) {
		if (a[i] == a[i-1])
			val++;
		else {
			freq.pb(val);
			val = 1;
		}
	}
	freq.pb(val);
	int KK = (int)freq.size();
	if (KK <= K) {
		cout << '0' << endl;
		return 0;
	}
	int l = 0;
	int r = K-1;
	//Cambios en el intervalo candidato actual
	int changes = 0;
	int aux = r+1;
	for(; aux < (int)freq.size(); ++aux) {
		changes += freq[aux];
	}
	int minch = changes;
 
	l++; r++;
	for(; r < (int)freq.size(); ++r) {
		changes += freq[l-1]-freq[r];
		minch = min(minch, changes);
		++l;
	}
	
	cout << minch << endl;
	return 0;
}
