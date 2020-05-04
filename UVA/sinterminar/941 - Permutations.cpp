//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=882
//941 - Permutations
#include <bits/stdc++.h>

//TLE

using namespace std;

string s;
int num;

int main() {
	int nc;
	cin >> nc;
	while (nc--) {
		cin >> s;
		cin >> num;
		sort(s.begin(), s.end());
		while(num > 0) {
			next_permutation(s.begin(), s.end());
			--num;
		}
		cout << s << endl;
	}
}



