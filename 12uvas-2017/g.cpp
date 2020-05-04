#include<iostream>

using namespace std;

//Separar casos, nos dan 2 magnitud, hay que hallar la otra
//magnitudes ENTERAS siempre
void solve() {
	//Magnitud a leer, y separador '='
	char mag, p;
	//Valores de espacio, velocidad y tiempo
	int d, v, t;
	cin >> mag >> p;
	if (mag == 'D') {
		cin >> d;
		cin >> mag >> p;
		if (mag == 'T') {
			cin >> t;
			cout << "V=" << d/t << endl;
		} else {
			cin >> v;
			cout << "T=" << d/v << endl;
		}
	}
	else if (mag == 'T') {
		cin >> t;
		cin >> mag >> p;
		if (mag == 'V') {
			cin >> v;
			cout << "D=" << v*t << endl;
		} else {
			cin >> d;
			cout << "V=" << d/t << endl;
		}
	}
	else if (mag == 'V') {
		cin >> v;
		cin >> mag >> p;
		if (mag == 'T') {
			cin >> t;
			cout << "D=" << v*t << endl;
		} else {
			cin >> d;
			cout << "T=" << d/v << endl;
		}
	}
}

int main() {
	int ncasos;
	for(cin >> ncasos; ncasos > 0; ncasos--) {
		solve();
	}
}
