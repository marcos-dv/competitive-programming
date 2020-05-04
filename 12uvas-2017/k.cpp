#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool solve() {
	int n;
	cin >> n;
	if (n == 0)
		return false;
	vector<int> v(n);		
	vector<int> u(n);
	
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
		u[i] = v[i];	
	}
	
	sort(u.begin(), u.end());
	
	int cont = 0;
	int j = 0;
	
	for(int i = 0; i < n; ++i) {
		if (v[i] == u[j])
			j++;
		else
			cont++;
	}
	
	cout << cont << '\n';	
	return true;
}

int main() {
	while(solve()) ;
}
