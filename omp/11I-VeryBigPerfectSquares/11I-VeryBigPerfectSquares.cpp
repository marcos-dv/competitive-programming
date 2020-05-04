#include <bits/stdc++.h>
using namespace std;

/*
	Estamos buscando la raiz cuadrada entera, solo la primera cifra
	Siguiendo el algoritmo de la raiz cuadrada, el primer digito esta
	determinado por el primer par de digitos del numero
	Si hay un numero impar de cifras, solo por la primera

*/

int intsqrt(int n) {
	if (n == 0)
		return 0;
	int i = 1;
	while (i*i <= n) {
		++i;
	}
	--i;
	return i;
}

int main() {
	string n;
	while (true) {
		cin >> n;
		if (n == "0")
			break;
		int dosdigitos = 0;
		if (n.length() == 1) {
			dosdigitos = n[0]-'0';
			cout << intsqrt(dosdigitos) << endl;
		}
		else if (n.length() == 2) {
			dosdigitos += n[1]-'0';
			dosdigitos += (n[0]-'0')*10;
			//la raiz entera de 0..99 tiene UNA sola cifra
			cout << intsqrt(dosdigitos) << endl;
		}
		else if (n.length() % 2 == 0) {
			dosdigitos += n[1]-'0';
			dosdigitos += (n[0]-'0')*10;
			//la raiz entera de 0..99 tiene UNA sola cifra
			string fill ((n.length()-1)/2, '0');
			cout << intsqrt(dosdigitos) << fill << endl;			
		}
		else if (n.length() % 2 != 0) {
			dosdigitos += n[0]-'0';
			//la raiz entera de 0..99 tiene UNA sola cifra
			string fill ((n.length()-1)/2, '0');
			cout << intsqrt(dosdigitos) << fill << endl;			
		}
	}
}
