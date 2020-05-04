#include <bits/stdc++.h>


using namespace std;
typedef long long ll;


int main() {
	int q;
	cin >> q;
	int a[3];
	while (q--) {
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a+3);
		if (a[0] < a[1])
			a[0]++;
		else if ((a[1] < a[2]) && (a[0] == a[1])) {
			a[0]++;
			a[1]++;
		}
		if (a[1] < a[2])
			a[2]--;
		else if ((a[0] < a[1]) && (a[1] == a[2])) {
			a[1]--;
			a[2]--;
		}
		long long sol = 2*a[2]-2*a[0];
		cout << sol << endl;
	}
}
