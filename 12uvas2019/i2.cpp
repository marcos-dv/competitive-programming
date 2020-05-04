#include <bits/stdc++.h>
#define N 100002
#define pb push_back
using namespace std;
typedef long long ll;

int a[5001];
int b[5001];

int main () {
	int nc;
	cin >> nc;
	while (nc--) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		int n;
		cin >> n;
		int aux;
		for(int i = 1; i <= n; ++i) {
			cin >> aux;
			a[aux]++;
		}
		int m;
		cin >> m;
		for(int i = 1; i <= m; ++i) {
			cin >> aux;
			b[aux]++;
		}
		vector<int> sola;
		vector<int> solb;
		for(int i = 1; i <= 5000; ++i) {
			if ((b[i] == 0) && (a[i] > 1)) {
				sola.pb(i);
			}
			if ((a[i] == 0) && (b[i] > 1)) {
				solb.pb(i);
			}
		}
		if (sola.size() == 0)
			cout << "Nada que intercambiar\n";
		else {
			for(int i = 0; i < (int)sola.size()-1; i++)
				cout << sola[i] << ' ';
			cout << sola[sola.size()-1] << '\n';
		}
		if (solb.size() == 0)
			cout << "Nada que intercambiar\n";
		else {
			for(int i = 0; i < (int)solb.size()-1; i++)
				cout << solb[i] << ' ';
			cout << solb[solb.size()-1] << '\n';
		}
	}

}
