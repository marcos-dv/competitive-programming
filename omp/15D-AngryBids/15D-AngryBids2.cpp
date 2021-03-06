#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct gente {
	int precio;	//Precio
	int total;	//Numero de personas que quieren ese precio
}

//REVISAR SI SIRVE CON INT

void procesar(vector<int> p, vector<int> c, int P, int C) {
	int cc = 0;	//Contadores de consumidores/productores
	int pc = 0;	
	int ab = P;	//AngryBids actual
	int b = 0;	//Precio actual

	int minab = ab;	//MINIMOS
	int minb = b;
	/*
	//Primer paso
	if (p[0] > c[0]) {
		b = c[0];
	} //else if (p[0] < c[0]) {
		//b = p[0];
	} else {
		b = p[0];
	}
	
	//Actualizar el minimo (donde b no sera menor, seguro, al ser arrays ascendentes)
	if (ab < minab) {
		minab = ab;
		minb = b;
	}//quitar
	*/
	while ((pc < P) && (cc < C)) {
		if(p[pc] > c[cc]) {
			b = c[cc];
			ab++;
			cc++;
		} else if (p[pc] < c[cc]) {
			b = p[pc];
			ab--;
			pc++;
		} else {	//Iguales
			b = p[pc];
			cc++;
			pc++;
		}
		//Actualizar el minimo
		if (ab < minab) {
			minab = ab;
			minb = b;
		}
	}
	//Si se terminaron los productores, no podra mejorarse
	//Si se terminaron los consumidores, podemos subir los precios todo lo posible
	if ((pc < P) && (cc >= C)) {
		b = p[P-1];
		ab -= P-pc-1;
	}
	//Actualizar el minimo
	if (ab < minab) {
		minab = ab;
		minb = b;
	}
		
	cout << minb << ' ' << minab;
}

void solve() {
	int P, C;
	cin >> P >> C;

	vector<int> prod (P, 0);
	vector<int> cons (C, 0);
	for(int i = 0; i < P; ++i)
		cin >> prod[i];
	for(int i = 0; i < C; ++i)
		cin >> cons[i];
	sort(prod.begin(), prod.end());	//Ordenamos los precios, para mejor procesamiento
	sort(cons.begin(), cons.end());
	
	//CASOS EXTREMOS
	if(P == 0)		//Sin productores, el precio minimo es 0
		cout << "0 0";
	else if (C == 0)	//Sin consumidores, el precio sera lo maximo. Ademas, al menos hay 1 productor
		cout << prod[P-1] << '0';
	else {
		procesar(prod, cons, P, C);
	}
	cout << '\n';
}

int main() {
	int ncasos;
	for (cin >> ncasos; ncasos > 0; --ncasos)
		solve();

}
