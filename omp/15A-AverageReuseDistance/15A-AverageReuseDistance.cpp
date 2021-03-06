#include <iostream>	//Fixed
#include <iomanip>	//Decimales

using namespace std;

//ABC size
#define ABC 26

//Distancia actual
int distAct[ABC];
//Ultima aparicion de cada letra en una posicion
int appear[ABC];

//Total de "evaluaciones" de distancia
double total = 0;
double suma = 0;

//Ejemplo: en abcaba, el total de evaluaciones seria de 3, 2 de ellas de la letra 'a'
//La suma seria: 2 + 2 + 1, que hacen 5 -> 5/3 = 1.6667

//Tratamiento tras aparecer el caracter c en la posicion pos
void aparece(char c, int pos) {
	int letra = c-'a';
	//Nueva aparicion (suma solo si ha sido referenciado anteriormente)
	suma += distAct[letra];
	distAct[letra] = 0;
	
	//Si fuera necesario, aumentamos la distancia del resto de letras	
	for (int i = 0; i < ABC; ++i) {
		if (appear[letra] < appear[i])
			distAct[i]++;
	}
	
	//Solo cuenta si ya ha sido referenciado anteriormente
	if (appear[letra] != -1) {
		total++;
	}
	//Actualizamos la ultima posicion
	appear[letra] = pos;
}

//Resuelve un caso individualmente dado por el string s
void solve(string s) {

	//Inicializar variables
	suma = 0;
	total = 0;
	for(int i = 0; i < ABC; ++i) {
		distAct[i] = 0;
		appear[i] = -1;
	}
	
	//Algoritmo secuencial
	for(unsigned int i = 0; i < s.length(); ++i)
		aparece(s[i], i);

	//Resultado
	if (total == 0)
		cout << "NaN\n";
	else
		cout << setprecision(4) << fixed << suma/total << '\n';
	
}

int main () {
	string s;
	while ((cin >> s) && (s != "0"))
		solve(s);
}
