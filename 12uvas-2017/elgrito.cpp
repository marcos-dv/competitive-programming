#include<iostream>
#include <iomanip>
using namespace std;

bool solve() {
	string s;
	getline(cin, s);
	if (s.length() == 0)
		return false;
	//Contador de caracteres '!'
	int cont = 0;
	//Contador de caracteres alfabeticos
	int alf = 0;
	for(int i = 0; i < s.length(); ++i) {
		if (s[i] == '!') {
			cont++;
		}
		else if (isalpha(s[i]))
			alf++;
	}
	if (exc > alf)
		cout << "ESGRITO\n";
	else
		cout << "escrito\n";
	return true;
}

int main() {
	while(solve())	;
}
