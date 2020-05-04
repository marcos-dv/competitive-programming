#include <iostream>
#include <algorithm>
using namespace std;

bool solve () {
	int n;
	cin >> n;
	if (n == 0)
		return false;
	int v[n];
	for(int i = 0; i < n; ++i)
		cin >> v[i];

	//Maxima longitud del grupo	
	int maxG = 1;
	//Minima longitud del grupo
	int minG = n+1;
	//Numero de grupos
	int nG = 1;
	//Minima velocidad actual
	int minAct = v[0];
	//Longitud del grupo actual
	int gAct = 1;

	for(int i = 1; i < n; ++i) {
		if (v[i] < minAct) {
			nG++;
			maxG = max(gAct, maxG);
			minG = min(gAct, minG);
			minAct = v[i];
			gAct = 1;
		}
		else {
			gAct++;
		}
	}
		
	maxG = max(gAct, maxG);
	minG = min(gAct, minG);

	cout << nG << ' ' << minG << ' ' << maxG << '\n';	
	
}

int main() {
	while (solve()) ;
}
