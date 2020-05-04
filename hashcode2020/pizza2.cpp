#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef list<ii> lii;
typedef vector<int> vi;
typedef vector<vii> vvi;

const int N = 100005;
int n,M,t;

lii slide;
vi taken(N+5,0);

/*
void rec(int total, int umbral) {
	if (slide.size() <= 0)
		return ;
	cerr << "Umbral -> " << umbral << endl;
	list<ii>::iterator it = lower_bound(slide.begin(), slide.end(), umbral);
	it--;
//	cerr << "Elemento -> " << (*it) << endl;
//	cerr << "Pos -> " << (it-slide.begin()) << endl;
	if (it != slide.end() && (*it).fi) {
		taken[total] = (*it).se;
		int val = umbral - (*it).fi;
		total++;
		slide.erase(it);
		rec(total, val);
	}
}
*/

/*
bool comp (const ii& uno, const ii& dos) {
	return uno.fi < dos.fi;
}
*/

int main() {
	srand(time(NULL));
	cin >> M >> n;
	for(int i = 0; i < n; ++i) {
		int aux;
		cin >> aux;
		ii par;
		par.fi = aux;
		par.se = i;
		slide.pb(par);
	}
	
	lii copia;
	vi best;
	ll minM = 1e12;
	
	int iter1 = 3000, iter2 = n*5000;
	int MM = M;
	for(int iter = 0; iter < iter1; ++iter) {
		M = MM;
		int sz = n;
		taken.clear();
		copia.clear();		
		copia.assign(slide.begin(), slide.end());
		for(int k = 0; k < iter2; ++k) {
			int ran = rand()%sz;
			lii::iterator it = copia.begin();
			advance (it,ran);
			if (M-(*it).fi >= 0) {
				taken.pb((*it).se);
				M-=(*it).fi;
				copia.erase(it);
				sz--;
			}
		}
		if (M < minM) {
			best.assign(taken.begin(),taken.end());
			minM = M;
			if (M == 0)
				break;
		}
	}
	cerr << minM << endl;
	cout << best.size() << endl;
	for(auto i : best)
		cout << i << ' ';
	cout << endl;
	return 0;
}





