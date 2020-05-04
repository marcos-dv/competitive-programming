#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef list<ii> lii;
typedef vector<int> vi;
typedef vector<vii> vvi;

const int N = 100005;
int n,M,t;

lii slide;
vi taken(N+5,0);

// mete todas al principio

int main() {
	cin >> M >> n;
	string sol;
	for(int i = 0; i < n; ++i) {
		int aux;
		cin >> aux;
		if (M-aux >= 0) {
			sol += to_string(i) + ' ';
			M -= aux;
		}
		else {
			sol = to_string(i) + '\n' + sol;
			break;
		}
	}
	cout << sol << endl;
	return 0;
}





