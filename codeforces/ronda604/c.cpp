#include <bits/stdc++.h>
#define N 400005
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

int n;
int p[N];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
	//cerr << endl << endl;
		int g = 0, s = 0, b = 0;
		memset(p, 0, sizeof(p));
		cin >> n;
		for(int i = 0; i < n; ++i) {
			cin >> p[i];
		//	cerr << "Pos " << i << ' ' << p[i] << endl;
		}
	//	cerr << "Comienso" << endl;
		if (n <= 6) {
			cout << "0 0 0" << endl;
			continue;
		}
		int j = (n-1)/2;
		if (n & 1)
			j--;
		while ((j > 1) && p[j] == p[j+1]) {
			j--;
		}
		if (j <= 1) {
			cout << "0 0 0" << endl;
			continue;
		}
		//cerr << "Ult = " << j << endl;
		
		int jj = 1;
		g++;
		while((p[jj] == p[jj-1]) && jj <= j){
		//	cerr << "oro " << jj << "(" << p[jj] << ")" << endl;
			g++;
			jj++;
		}
		if(jj > j) {
			cout << "0 0 0" << endl;
			continue;
		}
		//cerr << "sil " << jj << "(" << p[jj] << ")" << endl;
		jj++;
		s++;
		while((s <= g) && jj <= j){
		//	cerr << "sil " << jj << "(" << p[jj] << ")" << endl;
			s++;
			jj++;
		}
		if(jj > j) {
			cout << "0 0 0" << endl;
			continue;
		}
		while((p[jj] == p[jj-1]) && jj <= j){
		//	cerr << "sil " << jj << "(" << p[jj] << ")" << endl;
			s++;
			jj++;
		}

	//	cerr << "br " << jj << "(" << p[jj] << ")" << endl;

		jj++;
		b++;
		while (jj <= j) {
			//cerr << "br " << jj << "(" << p[jj] << ")" << endl;

			b++;
			jj++;
		}
		if ((g >= s || g >= b) || (g*b*s == 0) || (g+b+s > (n/2)) {
			cout << "0 0 0" << endl;
			continue;
		}
		else {
			cout << g << ' ' << s << ' ' << b << ' ' << endl;
		}
	
	
	}
	
}
