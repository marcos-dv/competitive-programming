#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#define N 1000
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;

const int cartas = 13*4+4-8; //por repartir
bool V [N]; //array presencia para backtracking
ll nc[60][60]; //numeros combinatorios
char baraja[cartas+1]; //por repartir (nos interesan solo las 13 primeras posiciones, como mucho)
ll co = 0; //contador (casos posibles)
int A, D, P, M, d, espe;
// espe = especiales en la baraja
long long c1,c2,c3,c4; //casos favorables de cada jugada
set<string> suf;
unordered_map<string, string> casos;
//set de sufijos para no repetir

//mejora: agrupar todos los casos donde se cogen 6 cartas innecesarias, son muchos.
//Trabajar solo con, lo que este en la baraja: cartas especiales + 5 cartas inutiles '7' (backtracking de combinaciones de 6 elementos)
//Hacer las combinaciones con esas cartas. Las repeticiones se llevan gracias al set de suffijos, y los ases son '1', '2', '3', '4'
//Optimizacion por cada caso (tal vez la mano ya la hayamos robado)


		//Caso 1
		//D P A
		//Caso 2
		//D A A
		//Caso 3
		//P A A A
		//Caso 4
		//D P M d		

//chequea si la eleccion es alguna jugada valida
// solo jugadas que no son 6 numeros no especiales
inline void procesa() {
	int A2 = 0;
	int D2 = 0;
	int P2 = 0;
	int M2 = 0;
	int d2 = 0;
	int normal = 0;
	vector<char> robo;
	for(int i = 0; i < 15; ++i) {
		if (V[i]) {
			if (baraja[i] == '1') {
				A2++;
				robo.pb('1');
			}
			else if (baraja[i] == '2') {
				A2++;
				robo.pb('2');
			}
			else if (baraja[i] == '3') {
				A2++;
				robo.pb('3');
			}
			else if (baraja[i] == '4') {
				A2++;
				robo.pb('4');
			}
			else if (baraja[i] == 'D') {
				D2++;
				robo.pb('D');
			}else if (baraja[i] == 'P') {
				P2++;
				robo.pb('P');				
			}else if (baraja[i] == 'M') {
				M2++;
				robo.pb('M');
			}else if (baraja[i] == 'd') {
				d2++;
				robo.pb('d');
			}else if (baraja[i] == '7') {
				normal++;
				robo.pb('7');
			}
		}
	}
	sort(robo.begin(), robo.end());
	string robosuf = "";
	for(int i = 0; i < (int)robo.size(); ++i)
		robosuf+=robo[i];
	set<string>::iterator it = suf.find(robosuf);
	if (it != suf.end()) //Mano repetida!!
		return ;
	suf.insert(robosuf);

	//Formas de seleccionar las cartas inutiles
	ll repes = nc[cartas-espe][normal];

	if ((D+D2 > 0) && (P+P2 > 0) && (A+A2 > 0))
		c1+=repes;
	if ((D+D2 > 0) && (A+A2 > 1))
		c2+=repes;
	if ((P+P2 > 0) && (A+A2 > 2))
		c3+=repes;
	if ((D+D2 > 0) && (P+P2 > 0) && (M+M2 > 0) && (d+d2 > 0))
		c4+=repes;
}

//la mano actual
//agrupamos todos los casos donde cogemos 6 cartas inutiles
inline void procesa2() {
	int A2 = 0;
	int D2 = 0;
	int P2 = 0;
	int M2 = 0;
	int d2 = 0;
	ll repes = nc[cartas][6];
	if ((D+D2 > 0) && (P+P2 > 0) && (A+A2 > 0))
		c1+=repes;
	if ((D+D2 > 0) && (A+A2 > 1))
		c2+=repes;
	if ((P+P2 > 0) && (A+A2 > 2))
		c3+=repes;
	if ((D+D2 > 0) && (P+P2 > 0) && (M+M2 > 0) && (d+d2 > 0))
		c4+=repes;
}

//Combinaciones (n m), subconjuntos de m elementos entre los n
inline void comb (int n, int m) {
	if (m > n)
		return ;
	if (m == 0) {
		procesa();
	}
	else {
		V[n-1] = 1;
		comb(n-1, m-1);
		V[n-1] = 0;
		comb(n-1, m);
	}
}

//inicia numeros combinatorios
void init () {
	for(int i = 0; i < 60; ++i)
	for(int j = 0; j < 60; ++j)
		nc[i][j] = 0;
	for(int i = 0; i < 60; ++i)
		nc[i][0] = 1;
	for(int i = 1; i < 60; ++i)
	for(int j = 1; j < 60; ++j)
		nc[i][j] = nc[i-1][j]+nc[i-1][j-1];
}

int main() {
	init();
	string s;
	while ((cin >> s)&&(s.length() > 1)) {
		vector<char> mano;
		mano.clear();
		for(int i = 0; i < 8; ++i) {
			if (s[i] == 'A') {
				mano.pb('A');
			}
			else if (s[i] == 'D') {
				mano.pb('D');
			}else if (s[i] == 'P') {
				mano.pb('P');				
			}else if (s[i] == 'M') {
				mano.pb('M');
			}else if (s[i] == 'd') {
				mano.pb('d');
			}else {
				mano.pb('7');
			}
		}
		sort(mano.begin(), mano.end());
		string caso = "";
		for(int i = 0; i < (int)mano.size(); ++i)
			caso += mano[i];
		unordered_map<string, string>::iterator it = casos.find(caso);
		if (it != casos.end()) {	//Caso ya analizado
			cout << it->second;
		}
		else {	//Caso por analizar
		suf.clear();
		for(int i = 0; i < N; ++i)
			V[i] = 0;
		A = 0;
		D = 0;
		P = 0;
		M = 0;
		d = 0;
		co = 0;
		c1 = 0;
		c2 = 0;
		c3 = 0;
		c4 = 0;
		for(int i = 0; i < cartas; ++i)
			baraja[i] = '7'; // cartas inutiles
		for(int i = 0; i < 8; ++i) {
			if (s[i] == 'A')
				A++;
			if (s[i] == 'D')
				D++;
			if (s[i] == 'P')
				P++;
			if (s[i] == 'M')
				M++;
			if (s[i] == 'd')
				d++;
		}
		espe = 0; //cartas especiales que quedan en la baraja
		if (!D)
			baraja[espe++] = 'D';
		if (!P)
			baraja[espe++] = 'P';
		if (!M)
			baraja[espe++] = 'M';
		if (!d)
			baraja[espe++] = 'd';
		for(int i = 0; i < 4-A; ++i) {
			baraja[espe++] = '1'+i;	//Los ases los llamo 1,2,3,4
		}
		//Procesa conjuntos con, a lo sumo, 5 cartas inutiles
		if (espe > 0) //podriamos haber robado todas especiales
			comb(espe+5, 6);
		//Procesa los conjuntos con 6 cartas inutiles
		procesa2();

		long long cf = max(c1, c2);
		cf = max(cf, c3);
		cf = max(cf, c4);
		co = nc[cartas][6];
	//	cerr << "CASO\n" << cf << endl << co << endl << "FINCASO\n";
		if (4*cf >= co) {
			cout << "Grand Tichu!\n";
			casos.insert(mp(caso, "Grand Tichu!\n"));
		}
		else {
			cout << "...\n";
			casos.insert(mp(caso, "...\n"));
		}
		}
	}
}


/*

Sample Input

D23468AA
D2P4688K
D23468KA
D2233889
PdM2345T
PdM234AA
0

Sample Output

Grand Tichu!
Grand Tichu!
Grand Tichu!
...
...
...

*/












