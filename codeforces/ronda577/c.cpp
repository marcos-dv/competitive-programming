//https://codeforces.com/contest/1201/problem/C

#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;

/*
	Greedy
	Para superar la mediana hay que ir igualando los valores a partir de la mediana
	Array ordenado:
	a1 a2... med med+1 med+2... an
	Primero igualamos med con med+1. (incr la mediana)
	Despues tendremos que igualar los 2 anteriores con med+2
	Etc
Ignorando la primera mitad:
1 4 10 14

4 4 10 14

10 10 10 14

...

*/


int main() {
	int n;
	ll k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a+n);
	int med = a[n/2];
	//Superar la mediana
	int elem = 1;
	for(int i = n/2+1; i < n && k > 0; ++i) {
		ll diff = a[i]-med;
		diff *= elem; //overflow
		ll add = min(diff, k);
		k -= add;
		med += add/elem;
		++elem;
	}
	if (k > 0)
		med += k/elem;
	cout << med << endl;
}

