#include <bits/stdc++.h>
#define MAX_NODOS 20
using namespace std;

struct par {
	int g1, g2;
};

int nnodos, naristas, tiempo, aislados;
bool G [MAX_NODOS][MAX_NODOS];
bool visitado[MAX_NODOS];
list<par> momentos[100];

void leerGrafo() {
	memset (G, 0, sizeof(G));
	//Borramos los datos anteriores e inicializamos
	for (int i = 0; i < 100; ++i)
		momentos[i].clear();
	for (int i = 1; i < MAX_NODOS; ++i)
		visitado[i] = false;
	cin >> nnodos >> naristas;
	aislados = nnodos-1;
	int g1, g2, v;
	while (naristas > 0) { //Inicializamos los momentos
		cin >> g1 >> g2 >> v;
		G[g1-1][g2-1] = G[g2-1][g1-1] = true;
		par p;
		p.g1 = g1;
		p.g2 = g2;
		int instante;
		for (int i = 0; i < v; ++i) {
			cin >> instante;
			momentos[instante].push_back(p);
		}
		--naristas;
	}
}
void dfs(int v) {
	visitado[v-1]= true;
	for (int w = 0; w <= nnodos; ++w)
		if (!visitado[w] && G[v-1][w])
			dfs(w+1);
}
void avanzarTiempo() {
	++tiempo;
	//Se producen todos los encuentros de ese instante
	for (int i = 0; i < MAX_NODOS; ++i) {
		list<par>::iterator it = momentos[tiempo%100].begin();
		for (; it != momentos[tiempo%100].end(); ++it) {
			par p = *it;
			if (visitado[p.g1-1] || visitado[p.g2-1]) {
				if (!visitado[p.g1-1]) {
					aislados--;
					visitado[p.g1-1] = true;
				}
				else if (!visitado[p.g2-1]) {
					aislados--;
					visitado[p.g2-1] = true;
				}
			}
		}
	}
}

int resuelveCaso() {
	leerGrafo();
	tiempo = -1;
	dfs(1);
	//Comprobamos la conexion del grafo
	int i = 1;
	while ((i < nnodos) && visitado[i])
		++i;
	if (i < nnodos)
		//Hay un nodo aislado
		return tiempo;
	i = 1;
	//Reinicializamos "visitado" para guardar los
	//cotillas ya informados
	while (i < nnodos) {
		visitado [i] = false;
		++i;
	}
	while (aislados > 0)
		avanzarTiempo();
	return tiempo;
}

int main() {
	int ncasos;
	cin >> ncasos;
	while (ncasos > 0){
		cout << resuelveCaso() << endl;
		--ncasos;
	}
}
