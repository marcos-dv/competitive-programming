#include <iostream>
#include <math.h> //sqrt
using namespace std;

const double borde = 0.5;
//gravedad
const double g = 9.8;

/*
Operando con las ecuaciones del tiro parabolico llegamos a determinar:
x = v*sqrt(2h/g)
para este caso.
*/
void solve() {
	double L, D, H, V, d;
	cin >> L >> D >> H >> V;
	//Cambio de mm a m
	L/=1000;
	D/=1000;
	H/=1000;
	V/=1000;
	//Distancia recorrida durante el salto
	d = V*sqrt(2*H/g);
	
	//Analisis de casos
	if (d < D-borde)
		cout << "FLOOR";
	else if (d <= (D+borde))
		cout << "EDGE";
	else if (d < (D+L-borde))
		cout << "POOL";
	else if (d <= (D+L+borde))
		cout << "EDGE";
	else	//if (d > (D+L+borde))
		cout << "FLOOR";
	cout << '\n';
}


int main() {
	int ncasos;
	for(cin >> ncasos; ncasos > 0; ncasos--) {
		solve();
	}
}
