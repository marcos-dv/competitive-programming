#include <iostream>
#include <math.h>	//sqrt

using namespace std;

const int N = 100000;

const int MAS = 1;
const int MENOS = -1;

int signo[N+1];
bool primo[N+1];

//Inicializa el signo del numero i, suponiendo que los anteriores han sido resueltos
void initSigno(int i) {
	//Caso base de primos
	if (primo[i]) {
		if (((i+1)%4) == 0)
			signo[i] = MAS;
		else if (((i-1)%4) == 0)
			signo[i] = MENOS;
	} //Caso no primos
	else {
		for (int j = 2; j < i; ++j) {
			if (i%j == 0) {	
			//En ese caso, i = j*k, con k = i/j, luego signo(i) = signo(j)*signo(k)
			// que por induccion, ya estan resueltos
				signo[i] = signo[j]*signo[i/j];
				break;
			}
		}
	}
}

//Inicializa el array de signos
void initSignos() {
	signo[2] = MAS;	//Caso base de 2
	for (int i = 3; i <= N; ++i)
		initSigno(i);
}

//Inicializa el array de primos
void initPrimos() {
	for (int i = 0; i <= 3; ++i)
		primo[i] = true;
	for (int i = 4; i <= N; ++i) {
		int raiz = (int)sqrt(i);
		bool fin = false;
		for (int j = 2; j <= raiz; ++j) {
			if ((i%j) == 0) {
				primo[i] = false;
				fin = true;
				break;
			}
		}
		if (!fin)
			primo[i] = true;
	}
}

void solve() {
	int i;
	cin >> i;
	if (signo[i] == MAS)
		cout << "+\n";
	else
		cout << "-\n";
}

int main() {
	initPrimos();	
	initSignos();
	int ncasos;
	for(cin >> ncasos; ncasos > 0; ncasos--) {
		solve();
	}
}
