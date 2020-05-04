#include <bits/stdc++.h>
#define push_back pb

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MAXN = 1000006;
const ll INF = 1e18+8;

int n, arr[MAXN], d;
map<string, ll> fr;

ll s[6] = {4, 6, 8, 10, 12, 20}, prob[6];

int main() {
	//int casos;
//	cin >> casos;
	string t;
	while (getline(cin, t)) {
		for (int i = 0; i < 6; i++) {
			prob[i] = 1;
		}
		stringstream ss(t);
		n =0;
		//cerr << t << endl;
		while (ss >> d) {
			n++;
			int j = 0;
			for (; j < 6 && s[j] < d; j++) {
				prob[j] = 0;
			}
			for (int i = j; i < 6; i++) {
				prob[i]*=s[i];
			}
		} //cerr << endl << endl;
		int sel = 0;
		while (prob[sel] == 0) {
			sel++;
		}
		double r = 0;
		for (int i = sel; i < 6; i++) {
			r+=1./(double)prob[i];
		}
		printf("%Ld %.2f\n", s[sel], 1./r/(double)prob[sel]);
		
	}
}
