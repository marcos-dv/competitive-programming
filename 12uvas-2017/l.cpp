#include <iostream>

using namespace std;

bool solve() {
	int n, k;
	cin >> n >> k;
	if ((n == 0) && (k == 0)) {
		return false;
	}
	if (n == 0) {
		cout << n << endl;
		return true;
	}

	int v[n];
	for(int i = 0; i < n; i++)
		cin >> v[i];	

	int maxSize = 0;
	int actSize = 0;
	int ceros = 0;
	bool valido = false;

	for(int i = 0; i < n; ++i) {
		if (v[i] == 1) {
			actSize++;
			ceros = 0;
			valido = true;
		}
		else if(valido) {
			if(ceros < k) {
				ceros++;
				actSize++;
			}
			else {
				valido = false;
				if (actSize-ceros > maxSize) {
					maxSize = actSize-ceros;
				}
				actSize = 0;	
			}
		}
	}

	if (actSize-ceros > maxSize) {
		maxSize = actSize-ceros;
	}
	
	cout << maxSize << endl;
	
	return true;
}

int main() {
	while(solve())	;
}





