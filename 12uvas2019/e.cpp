#include <bits/stdc++.h>

using namespace std;

int a[3];
int b[3];

int main () {
	int nc;
	cin >> nc;
	while (nc--) {
		for(int i = 0; i < 3; ++i)	{
			cin >> a[i];
		}
		for(int i = 0; i < 3; ++i)	{
			cin >> b[i];
		}
		
		sort(a, a+3);
		sort(b, b+3);
		if (a[0] < b[0] && a[1] < b[1] && a[2] < b[2]) {
			cout << "SIRVE\n";
		}
		else {
			cout << "NO SIRVE\n";
		}
	}

}
