//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3000
//11878 - Homework Checker
#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int cont = 0;
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



