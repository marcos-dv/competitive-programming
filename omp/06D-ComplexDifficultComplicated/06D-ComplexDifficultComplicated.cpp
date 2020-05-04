#include<iostream>
#include<math.h>

using namespace std;

double const MAXIMO = 1073741824;	//2^30

/*

Podemos interpretar el numero complejo como un vector en R2,
en forma polar, elevarlo a n es equivalente a que su modulo se 
eleve a n, y su angulo se multiplique por n. De esta forma, un numero
complejo sera real si y solo si su angulo esta en el eje real, es decir,
que el angulo valga mpi, con m un entero (radianes). Alternativamente,
sera imaginario si su angulo es mpi+pi/2, para m entero.

Sea z = (a + bi), su forma polar:
-Argumento r = sqrt(a*a+b*b)
-Angulo alpha = arctan(b/a)

Su forma polar -> z = r*(cos(alpha) + sen(alpha)i);
Por lo tanto, el problema es determinar si sen(alpha) = 0 (sin que r sea demasiado grande)

*/

//Devuelve si sen(t*N) = 0, con t en radianes
bool real (double t, double n) {
	//Metodo 1, no funciona por falta de precision:
	//return (sin(t*N) == 0);

	//Devuelve si t*n = mPI, para m entero
	return floor(t*n/M_PI) == (t*n/M_PI);

}

//Devuelve el modulo del vector (a, b) (o el complejo z = a+bi)
double modulo(double a, double b) {
	return sqrt(a*a + b*b);
}

//Devuelve el angulo del vector (a, b) con el eje horizontal
double ang(double a, double b) {
	return atan2(a, b);
}

void solve() {
	double a, b;	//Parte real e imaginaria
	cin >> a >> b;
	if (b == 0)
		cout << "1\n";
	else if (a == 0)
		cout << "2\n";
	else {
	
	double m = modulo(a, b);
	double mAct = m;	//Modulo actual
	double t = ang(b, a);
	long N = 1;
	while (!real(t, N) && (mAct <= MAXIMO)) {
		mAct *= m;
		N++;		
	}
	if (mAct > MAXIMO)
		cout << "TOO COMPLICATED\n";
	else
		cout << N << endl;
	}
}

int main() {
	int ncasos;

	for(cin >> ncasos; ncasos > 0; ncasos--)
		solve();

}
