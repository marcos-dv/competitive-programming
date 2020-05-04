//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=563
//622 - Grammar Evaluation
#include <bits/stdc++.h>
//estados automata
# define INI 1
# define LEE 2
# define SUM 3
# define PRO 4

using namespace std;

string s;

int precedencia (char op) {
	if (op == '+')
		return 1;
	else if (op == '*')
		return 2;
}

bool parse(s) {
	int estado = INI;
	int le = 0;
	int ri = 0;
	for(int i = 0; i < (int)s.length(); ++i) {
		if (estado == INI) {
			if (s[i] == '(') 
				le++;
			else if (isdigit(s[i])) {
				int val = 0;
				while(i < (int)s.length() && isdigit(s[i])) {
					val = (val*10) + (s[i]-'0');
					++i;
				}
				if ;
			}
			else
				return false;
		}
		else if (estado == INI
		
		
		
	}
	
	
	return true;
}

int main() {
	int nc;
	cin >> nc;
	while (nc--) {
		cin >> s;
		bool ok = parse(s);
	
	
	
	
	
	
	
	}
	string s;
	while (cin >> s) {
		int a = 0;
		int b = 0;
		int c = 0;
		int i = 0;
		a+=(s[i++]-'0');
		while(isdigit(s[i])) {
			a = (a*10)+(s[i]-'0');
			i++;
		}
		char op = s[i++];

		b+=(s[i++]-'0');
		while(isdigit(s[i])) {
			b = (b*10)+(s[i]-'0');
			i++;
		}
		
		i++;
		if (s[i] != '?') {
			c+=(s[i++]-'0');
			while(isdigit(s[i])) {
				c = (c*10)+(s[i]-'0');
				i++;
			}
			if (op == '+') {
				cont += (a+b==c)?1:0;
			}
			else if (op == '-') {
				cont += (a-b==c)?1:0;
			}
		}
	}
	cout << cont << endl;
}

/*
Sample Input

1+2=3
3-1=5
6+7=?
99-0=99

Sample Output
2
*/



