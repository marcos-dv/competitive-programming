//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2380
//11385 - Da Vinci Code
#include <bits/stdc++.h>
#define N 103
using namespace std;
typedef long long ll;


int main() {
	int nc, n;
	cin >> nc;
	map<ll,int> fibo; //posiciones
	fibo[1] = 0;
	fibo[2] = 1;
	ll fib, fib1 = 2, fib2 = 1;
	
	for(int i = 2; i < N; ++i) {
		fib = fib1+fib2;
		fibo[fib] = i;
		fib2 = fib1;
		fib1 = fib;
	}
	ll orden[N];
	while (nc--) {
		cin >> n;
		for(int i = 0; i < N; ++i)
			orden[i] = 0;
		for(int i = 0; i < n; ++i) {
			cin >> orden[i];
		}
		string tex;
		char sol[N+1];
		for(int i = 0; i < N; i++)
			sol[i] = ' ';
		cin.ignore();
		getline(cin, tex);
		for(int i = 0, j = 0; i < (int)tex.length() && j < n; ++i) {
			if (tex[i] >= 'A' && tex[i] <= 'Z') {
				sol[fibo[orden[j]]] = tex[i];
				j++;
			}
		}
		for(int i = N-1; sol[i] == ' '; --i) {
			sol[i] = '\0';
		}
		printf("%s\n", sol);
	}
	
}

/*
2
11
13 2 89 377 8 3 233 34 144 21 1
OH, LAME SAINT!
15
34 21 13 144 1597 3 987 610 8 5 89 2 377 2584 1
O, DRACONIAN DEVIL!

THE MONA LISA
LEONARDO DA VINCI
*/



