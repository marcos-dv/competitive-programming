#include <bits/stdc++.h>
#define N 1000000
using namespace std;
typedef long long ll;

int main () {
	int nc;
	cin >> nc;
	while (nc--) {
		int n;
		cin >> n;
		int x[n];
		int y[n];
		int r[n];
		int col = 0;
		for(int i = 0; i < n; ++i) {
			cin >> x[i] >> y[i] >> r[i];
			for(int j = 0; j < i; ++j) {
				ll aa = x[i]-x[j];
				aa *= aa;
				ll bb = y[i]-y[j];
				bb *= bb;
				ll rr = r[i]+r[j];
				rr *= rr;
				if (aa+bb < rr)
					col++;
			}
		}
		cout << col << endl;
	}
}
