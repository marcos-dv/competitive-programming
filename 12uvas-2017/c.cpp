#include<iostream>

using namespace std;

#define N 10

void solve(string s) {

	int v[N];
	for(int i = 0; i < N; i++) {
		v[i] = 0;
	}
	for(int i = 0; i < s.length(); ++i) {
		v[s[i]-'0']++;
	}
	
	int n = v[0];
	bool subnormal = true;
	for(int i = 1; i < N; ++i) {
		if (v[i] != n)
			subnormal = false;
	}
	if (subnormal)
		cout << "subnormal\n";
	else
		cout << "no subnormal\n";

}

int main() {
	string s;
	while (cin >> s) {
		solve(s);
	}
}
