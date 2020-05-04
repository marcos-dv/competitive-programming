#include <iostream>
using namespace std;

/*
d = distActual
v = vActual
t = tiempo

d = v*t		//Ecuacion actual
d' = d+D	//Distancia de impacto
d' = v'*t	//Nueva ecuacion (correcta)
v' = d+D/t
v' = vt+D/t
v' = v+D/t
v'-v = D/t

La diferencia v'-v sera la cantidad de toneladas
a poner o quitar. Como vemos, S no es necesario
*/


//Resuelve un problema individual
void solve() {	
	//TIME SPEED DISTANCE
	//days mm/s km
	int T, S, D;
	cin >> T >> S >> D;

	int tons = 625*D/(T*54);
	if (tons > 0)	//Falta mas velocidad
		cout << "Remove " << tons << " tons\n";
	else		//Sobra velocidad
		cout << "Add " << -tons << " tons\n";
}


int main() {
	int ncasos;
	for(cin >> ncasos; ncasos > 0; ncasos--) {
		solve();
	}
}
