//http://http://codeforces.com/problemset/problem/1185/D
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;


//Mates
//Sucesion aritmetica

int main() {
	ll n, d;
	cin >> n;
	pll a[n];
	ll d[n-1];
	
	for(int i = 0; i < n; ++i) {
		cin >> a[i].fi;
		a[i].se = i+1;
	}

	if (n < 4) {
		cout << 1 << endl;
		return 0;
	}

	sort(a, a+n);
	
	ll d1 = a[1].fi-a[0].fi;
	ll d2 = a[1].fi-a[0].fi;
	
	
	
	
	ll dif[3]; //diferencias
	for(int i = 0; i < 3; ++i)
		dif[i] = a[i+1].fi-a[i].fi;
	
	int ind = -2;
	bool ok = true;
	
	if (dif[0] == dif[2])
		d = dif[0];
	else if (dif[1] == dif[2])
		d = dif[2];
	else if (dif[0]!=dif[1] && dif[0]+dif[1] == dif[2]) {
		ind = 1;
		ok = false;
		d = dif[2];
	}
	else if (dif[1]!=dif[2] && dif[1]+dif[2] == dif[0]) {
		ind = 2;
		ok = false;
		d = dif[0];
	}
	else if ((dif[1] != dif[0]) && (dif[1] != dif[2])) {
		cout << "-1" << endl;
		return 0;
	}
	
	
	for(int i = 0; i < n; ++i) {
		cerr << a[i].fi << ' ';
	}
	cerr << endl;
	for(int i = 0; i < n; ++i) {
		cerr << a[i].se << ' ';
	}
	cerr << endl;
	cerr << "d = " << d << endl;
	

	//Caso base
	if (a[1].fi-a[0].fi < d) {
		if (a[2].fi-a[1].fi == d)
			ind = 0;
		if (a[2].fi-a[0].fi == d)
			ind = 1;
		ok = false;
	}
	else if (a[1].fi-a[0].fi > d) {
		ind = 0;
		ok = false;
	}
	for(int i = 1; i < n-1; ++i) {

		if ((a[i+1].fi-a[i].fi != d) && (ind != i)) { //Segunda condicion = para quitar elemento (dara fallo 2 veces)
			if (ok) {
				ok = false;
				ind = i+1;
			}
			else {
				ind = -1;
				break;
			}
		}
	}
	if (ind == -1) {
		cout << -1 << endl;

	} else { //-2 = ERA ARITMETICA INICIALMENTE
		if (ind == -2)
			ind = 0;
		cout << a[ind].se << endl;
	}
	
}
