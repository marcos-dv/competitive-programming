#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int sol = 1;
	int r[n]; //cadena a derecha o izq creciente en a[i]
	for(int i = 0; i < n; ++i)
		r[i] = 1;
	int l[n];
	for(int i = 0; i < n; ++i)
		l[i] = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i-1] < a[i]) l[i] = l[i-1]+1;
	}
	for (int i = n-2; i >= 0; --i) {
		if (a[i] < a[i+1]) r[i] = r[i+1]+1;
	}
	
	for (int i = 0; i < n-2; ++i) {
		if (a[i] < a[i+2]) sol = max(sol, l[i] + r[i+2]);
		sol = max(l[i], sol);
		sol = max(r[i], sol);
	}
	sol = max(l[n-1], sol);
	
	cout << sol << endl;
}
