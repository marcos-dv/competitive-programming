#include <bits/stdc++.h>
#define N 1000000
using namespace std;
typedef long long ll;

int main () {
	double l;
	int n;
	while (cin >> l) {
		cin >> n;
		double t, v;
		int mini = 50000010;
		for(int i = 0; i < n; ++i) {
			cin >> t >> v;
			if (t >= 0) {
				double tiempo = t+l/v;
				mini = min(mini, (int)tiempo);
			}
		}
		cout << mini << '\n';
	}
}
