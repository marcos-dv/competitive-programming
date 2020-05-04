//onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1193
//10252 - Common Permutation
#include <bits/stdc++.h>
using namespace std;

//WA ?????????????????''

int main() {
	string a, b;
	int fra[30];
	int frb[30];
	while (cin >> a >> b) {
		for(int i = 0; i < 30; ++i) {
			fra[i] = 0;
			frb[i] = 0;
		}
		
		for(int i = 0; i < (int)a.length(); ++i) {
			fra[a[i]-'a']++;
		}
		for(int i = 0; i < (int)b.length(); ++i) {
			frb[b[i]-'a']++;
		}
		string sol = "";
		for(int i = 0; i < 30; ++i) {
			int mini = min(fra[i], frb[i]);
			if (mini != 0) {
				string letras (mini, (char)(i+'a'));
				sol += letras;
			}
		}
		cout << sol << endl;
	}
	
}

/*
Sample Input

pretty
women
walking
down
the
street

Sample Output

e
nw
et
*/



