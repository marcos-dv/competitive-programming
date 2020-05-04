#include <iostream>

using namespace std;

//Calcula el area del rectangulo apoyado en los ejes, definido por los vertices (x1, y1) y (x2, y2), x2 > x1
double area(int x1, int x2, int y1, int y2) {
	if (y2 < y1)
		return area(x1, x2, y2, y1);
	return ((double)(y2-y1)/2 + y1)*(x2 - x1);
	
}

//Calcula el area del poligono dado por los N puntos (x, y).
double area(int * x, int * y, int N) {
	double total = 0;
	for(int i = 1; i < N; ++i) {
		//Sumamos el area de todos los rectangulos
		total += area(x[i-1], x[i], -y[i-1], -y[i]);
	}
	return total;
}

//Resuelve un problema individualmente
void solve() {
	//Lectura de datos
	int N, W;
	cin >> N;
	int * x = new int[N];
	int * y = new int[N];
	for(int i = 0; i < N; ++i)
		cin >> x[i] >> y[i];
	cin >> W;
	double initial, used, rain;	// %, m³, m³
	cin >> initial >> used >> rain;
	
	//Calcular volumen total
	double v = W*area(x, y, N);
	
	initial *= v/100;	//m³ iniciales
	
	//Consumo		
	double currentWater = initial - used;

	if (currentWater < 0) {
		cout << "Lack of water. ";
		currentWater = 0;
	}
	//Lluvia
	currentWater += rain;
	if (currentWater > v) {
		cout << "Excess of water. ";
		currentWater = 100;
	} else {
		currentWater = 100*currentWater/v;
	}
	//Balance final
	cout << "Final percentage: " << (int)currentWater << "%\n";

	delete x;
	delete y;
}

int main() {
	int ncasos;
	for(cin >> ncasos; ncasos > 0; ncasos--) {
		solve();	
	}
}
