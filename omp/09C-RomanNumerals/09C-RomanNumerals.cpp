#include <iostream>

using namespace std;

//Podria factorizarse mucho el codigo

int procesarRoman(string s, int i) {
	//SOLO SUMAN
	if (s[i] == 'V')
		return 5;
	if (s[i] == 'L')
		return 50;
	if (s[i] == 'D')
		return 500;

	//SUMAN O RESTAN
	bool fin;
	if (i < s.length()-1)	//Fin de la cadena
		fin = false;
	if (s[i] == 'I') {
		if ((fin) || ((s[i+1] != 'V') && (s[i+1] != 'X')))
			return 1;
		return -1;
	}
	if (s[i] == 'X') {
		if ((fin) || ((s[i+1] != 'L') && (s[i+1] != 'C')))
			return 10;
		return -10;
	}
	if (s[i] == 'C') {
		if ((fin) || ((s[i+1] != 'D') && (s[i+1] != 'M')))
			return 100;
		return -100;
	}
	if (s[i] == 'M') {
		return 1000;
	}		
	return 0;
}

//Roman number to usual number
int fromRoman(string s) {
	int n = 0;
	for(int i = 0; i < s.length(); ++i) {
		n += procesarRoman(s, i);
	}
	return n;
}

//Devuelve true si la cadena c esta en numeros romanos
bool roman(string c) {
	return (c[0] > 'A');
}

int stringtointeger(string c) {
	int n = 0;
	int b = 10;
	for(int i = 0; i < c.length(); ++i) {
		n = (n*b+(c[i]-'0'));
	}
	return n;
}

//Usual number to Roman number
string toRoman(int n) {
	int b = 10;
	string s = "";

//Por su posicion en el string, mejor colocar primero decenas y centenas
	
	int d = (n/b) %b;	//Decenas
	if (d == 9)
		s = "XC";
	else {
		if (d == 4)
			s = "XL";
		else {
			if (d > 4)
				s = "L";
			for (int i = 0; i < d%5; ++i)
				s+="X";
		}
	}
	
	int c = (n/(b*b)) %b;	//Centenas
	if (c == 9)
		s = "CM"+s;
	else {
		if (c == 4)
			s = "CD"+s;
		else {
			for (int i = 0; i < c%5; ++i)
				s ="C"+s;
			if (c > 4)
				s = "D"+s;
		}
	}

	int u = n%b;	//Unidades
	if (u == 9)
		s += "IX";
	else {
		if (u == 4)
			s += "IV";
		else {
			if (u > 4)
				s += "V";
			for (int i = 0; i < u%5; ++i)
				s+="I";
		}
	}
	
	int m = n / (b*b*b);	//Millares
	for (int i = 0; i < m%5; ++i)
			s ="M"+s;
	
	return s;
}

int main() {
	string c;
	while (cin >> c) {
		if(roman(c))
			cout << fromRoman(c) << endl;
		else
			cout << toRoman(stringtointeger(c)) << endl;
	}
}

