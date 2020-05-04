#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
//#define fi first
//#define se second
using namespace std;

//typedef pair<int,int> ii;

const int N = 100005;
int n,M,t;

struct ii {
	int fi;
	int se;
};

bool cmp (ii lhs, ii rhs) {
	return lhs.fi < rhs.fi;
}	


list<ii> slide;
vector<int> taken(N+5,0);

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

int main() {
	cin >> M >> n;
	for(int i = 0; i < n; ++i) {
		int aux;
		cin >> aux;
		ii par;
		par.fi = aux;
		par.se = i;
		slide.pb(par);
	}
	
	rec(t, M);
	
	set<int> s( taken.begin(), taken.end() );
	s.erase(0);
	cout << s.size() << endl;
	for(auto i : s)
		cout << i << ' ';
	cout << endl;
	return 0;
}





