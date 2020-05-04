//Mejora en tiempo
#include <iostream>
#include <limits>
#include <math.h>
using namespace std;

/*
Como las jarras son adyacentes, las posibilidades tirando 1 jarra: (hay n jarras)
n
Tirando 2 jarras: n-1
Tirando 3: n-2...

Tirando n jarras: 1
Es decir, tenemos 1+2+...+n = n(n+1)/2 posibilidades
Por backtracking podemos hacer un algoritmo cuadratico para resolver el problema

Por desempate, debemos recorrer primero todas las opciones que conlleven la jarra 1, luego la jarra 2, etc.

Mejora:
Calcularemos el NUMERADOR de las medias en un array (C), de forma que
C[i] contiene el numerador de tirar las i primeras jarras.

Para calcular el numerador en la tirada entre i y j, solamente hay que hacer
C[j]-C[i]

Haremos lo mismo con el volumen, reutilizaremos V[i] para poner todo el volumen de tirar las i primeras jarras.
Como seran numeros grandes, usaremos long long

*/


//Devolvemos la temperatura a la que se queda la piscina, tras tirar n jarras a partir de la 'a'.
//Devuelve infinito si la temperatura no es aceptable, o no llenamos media piscina
double temp (long long jarV[], long long C[], int a, int b, double target, double maxV) {
	int vol;
	if (a > 0)
		vol = jarV[b]-jarV[a-1];
	else
		vol = jarV[b];
	
	if ((maxV > 2*vol) || (maxV < vol))	//No llenamos media piscina o desbordamos
		return numeric_limits<double>::infinity();
	double num = 0;
	if (a > 0)
		num = C[b]-C[a-1];
	else
		num = C[b];
	double dif = abs(target - (double)num/vol);
	if (dif <= 5)	//Cota diferencia de temperatura
		return dif;
	return numeric_limits<double>::infinity();
}

void solve() {
	int maxV, n;	//max volumen target temperature, nJars
	double target;
	cin >> maxV >> target >> n;
	long long jarV[n], jarT[n], C[n];
	for(int i = 0; i < n; ++i) {
		cin >> jarV[i] >> jarT[i];
	}
	C[0] = jarT[0]*jarV[0];
	for(int i = 1; i < n; ++i) {
		C[i] = C[i-1] + jarV[i]*jarT[i];
		jarV[i] += jarV[i-1];
	}
	//Backtracking
	double minDif = numeric_limits<double>::infinity();
	double difAct = 0;
	int minFirst = 0;
	int minLast = 0;
	for(int i = 0; i < n; ++i) {	//Empezando por jarra i
		for(int j = i; j < n; ++j) {	//j = Ultima jarra que tiramos
			difAct = temp(jarV, C, i, j, target, maxV);	//Calculamos dif de temp
			if (difAct < minDif) {
				minDif = difAct;
				minFirst = i;
				minLast = j;
			}
		}
	}
	
	if (minDif <= 5)
		cout << minFirst << ' ' << minLast << '\n';
	else
		cout << "Not possible\n";
}

int main() {
	int ncasos;
	for(cin >> ncasos; ncasos > 0; ncasos--)
		solve();
}
