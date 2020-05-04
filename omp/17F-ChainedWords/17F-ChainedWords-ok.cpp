#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vii;

/*
Sol directa: cada palabra es un nodo, arista (u,v) si u[fin] = v[inicio]
Hacer ciclo hamiltoniano -> inviable con 200.000 palabras

Sol: Cada nodo es una letras 'a' .. 'z'. Multigrafo, cada arista es una palabra
'a' -> 'c' con palabra "a...c" -> Buscar tour euleriano
200.000 palabras -> Usar hierholzer (lineal) en vez de fleury (cuadratico)

Modificacion en Hierholzer: coger nodos en orden lexicografico
(Revisado version 2)

*/

const int MAX_NODOS = 'z'+3;
// etiquetas aristas (las palabras)
// listas de adyacencia
vector< vector<string> > adj;
// para reconstruir el camino
multiset<string> words [MAX_NODOS][MAX_NODOS];
// array nodos visitados
bool visit[MAX_NODOS];


// Algoritmo de hierholzer para hallar tour euleriano
// criterio: minimo en orden lexicografico en las aristas escogidas
void tour(vector< vector<string> > adj, int st) { 
	// aristas que salen de un vertice no usadas
	unordered_map<int,int> edge_count;
	for (int i = 'a'; i <= 'z'; i++) { 
		edge_count[i] = adj[i].size(); 
	} 

	// camino actual
	vector<int> curr_path; 

	// tour solucion, guarda nodos por los que pasa
	vector<int> circuit; 

	// vertice inicial
	curr_path.pb(st);
	int curr_v = st;

	while (!curr_path.empty()) {
		// al vertice le quedan aristas sin usar 
		if (edge_count[curr_v]) 
		{ 
			// inserta en el camino
			curr_path.pb(curr_v); 

			// toma una arista
			string s = adj[curr_v][0];
			int next_v = s[s.length()-1];

			// marcar como usada 
			edge_count[curr_v]--;
			adj[curr_v].erase(adj[curr_v].begin());

			// siguiente vertice
			curr_v = next_v; 
		} 

		// el vertice se puede insertar en el tour 
		else
		{ 
			circuit.pb(curr_v); 

			// Back-tracking 
			curr_v = curr_path.back(); 
			curr_path.pop_back();
		} 
	}
	// print sol (reverso)
	int pre = circuit[circuit.size()-1];
	
	for (int i=circuit.size()-2; i >= 0; i--) {
		int pos = circuit[i];
		set <string>::iterator it = words[pre][pos].begin();
		if (i > 0)
			cout << *it << ' ';
		else {
			cout << *it << endl;
		}
		words[pre][pos].erase(it);
		pre = pos;
	} 
}
	
void dfs(int v) {
	visit[v] = true;
	for(int u = 0; u < (int)adj[v].size(); ++u) {
		// el vecino es la ultima letra de la palabra
		int vecino = adj[v][u][adj[v][u].size()-1];
		if(!visit[vecino])
			dfs(vecino);
	}
}

int main() {

	int nc;
	cin >> nc;
	while (nc--) {
		int m; // palabras
		string s;
		cin >> m;
		// Grados
		int in[MAX_NODOS];
		int out[MAX_NODOS];
		adj.clear();
		adj.resize(MAX_NODOS);
		for(int i = 'a'; i <= 'z'; ++i) {
			for(int j = 'a'; j <= 'z'; ++j) {
				words[i][j].clear();
			}
		}

		int st = 'z'; // nodo inicial
		// inicializa grados
		for(int i = 'a'; i <= 'z'; ++i) {
			in[i] = out[i] = 0;
		}
		// inicializa aristas
		for(int i = 'a'; i <= 'z'; ++i) {
			adj[i].clear();
		}
		
		// leer palabras		
		for(int i = 0; i < m; ++i) {
			cin >> s;
			// primera y ultima letra
			int pri = s[0];
			int ult = s[s.length()-1];
			in[ult]++;
			out[pri]++;
			adj[pri].pb(s);
			words[pri][ult].insert(s);
			// Guarda que existe arista A->B
			st = min(st, pri);
		}
		
		// Ordena las palabras
		for(int i = 'a'; i <= 'z'; ++i) {
			sort(adj[i].begin(), adj[i].end());
		}
		
		// chequear que el grafo es conexo, y euleriano

		// conexion con dfs
		bool ok = true;

		for(int i = 'a'; i <= 'z'; ++i)
			visit[i] = false;
		dfs(st);
		for(int i = 'a'; i <= 'z'; ++i) {
			// chequea nodos con palabras
			if ((in[i]+out[i] > 0) && !visit[i]) {
				ok = false;
				break;
			}
		}
		//euleriano -> si entramos a un nodo, salimos de el
		for(int i = 'a'; i <= 'z'; ++i) {
			if (in[i] != out[i]) {
				ok = false;
				break;
			}
		}
		
		if (!ok) {
			cout << "No way\n";
		}
		else {
			tour(adj, st);
		}
			 
	}
}


