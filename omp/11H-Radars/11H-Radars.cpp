#include <iostream>
#include <math.h> //sqrt

using namespace std;

//Lee la matriz asociada
void leerMatriz(int ** G, bool ** B, int size, int & vigilados) {
	for(int i = 0; i < size; ++i)
		for(int j = 0; j < size; ++j) {
			cin >> G[i][j];
			if (G[i][j] == 0) {
				vigilados++;
				B[i][j] = true;
			}
			else
				B[i][j] = false;
		}
}

//Distancia euclidea entre (i, j) y (l, m)
double dist (int i, int j, int l, int m) {
	return sqrt((i-l)*(i-l) + (j-m)*(j-m));
}

//Procesa los candidatos a ser influenciados por el radar en (i, j)
void procesarRadar(int ** G, bool ** B, int size, int i, int j, int & vigilados) {
	//Hallar media
	double media = 0;
	double vecinos = 4;
	if (i-1 < 0)
		vecinos--;
	else
		media+=G[i-1][j];
	if (i+1 >= size)
		vecinos--;
	else
		media+=G[i+1][j];
	if (j-1 < 0)
		vecinos--;
	else
		media+=G[i][j-1];
	if (j+1 >= size)
		vecinos--;
	else
		media+=G[i][j+1];
	media = media/vecinos;
	
	//Revisaremos el cuadrado de lado 2*media centrado en (i, j)
	//***Posible optimizar el cuadrado???***
	
	for (int l = i-media; l <= i+media; ++l)
		for(int m = j-media; m <= j+media; ++m)
			//Comprobamos que estamos en los limites
			if ((l >= 0) && (l < size) && (m >= 0) && (m < size) && !B[l][m]) {
				//Comprobar la influencia
				if (dist(i, j, l, m) <= media) {
					B[l][m] = true;
					vigilados++;
				}
			}
	
}

//Procesa los radares de una matriz
void procesarMatriz(int ** G, bool ** B, int size, int & vigilados) {
	for(int i = 0; i < size; ++i)
		for(int j = 0; j < size; ++j) {
			if (G[i][j] == 0)
				procesarRadar(G, B, size, i, j, vigilados);
		}
}

//Resuelve un problema individual, muestra el resultado por la salida
void solve() {
	int size;
	cin >> size;
	int ** G = new int *[size];
	bool ** B = new bool *[size];
	int vigilados = 0;
	//Inicializar y leer
	for(int i = 0; i < size; ++i) {
		G[i] = new int[size];
		B[i] = new bool[size];
	}
	
	leerMatriz(G, B, size, vigilados);
	procesarMatriz(G, B, size, vigilados);
	
	cout << (size*size)-vigilados << '\n';
	
	//Borrar memoria dinamica
	for(int i = 0; i < size; ++i) {
		delete G[i];
		delete B[i];
	}
	delete G;
	delete B;
}


int main() {
	int ncasos;
	for(cin >> ncasos; ncasos > 0; ncasos--) {
		solve();
	}
}
