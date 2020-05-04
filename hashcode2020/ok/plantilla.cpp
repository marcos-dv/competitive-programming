#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define FOR
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef list<ii> lii;
typedef vector<int> vi;
typedef vector<vii> vvi;

const int N = 100005;
int n,M,t;

struct dato {
	int id;
	string s;
	dato() : id(0), s("") {}
	dato(int id_) : id(id_) { }
	dato(int id_, string s_) : id(id_), s(s_) { }
};
bool comp (const dato& lhs, const dato& rhs) {
	return lhs.id < rhs.id;
}
bool compa (dato lhs, dato rhs) {
	return lhs.id < rhs.id;
}

class Comp
{
	public:
		bool operator() (dato lhs, dato rhs) {
			return lhs.id < rhs.id;
		}
};

vector<dato> v;
vector<dato> sol;
priority_queue<dato, vector<dato>, Comp> pq;

// requiere ordenado en el parametro
// search un id, return indice
int bs(int val) {
	int l = 0;
	int r = n-1;
	if (sol[l].id >= val)
		return l;
	if (sol[r].id <= val)
		return r;
	while (l < r-1) {
		int m = (l+r) >> 1;
		if (sol[m].id == val)
			return m;
		else if (sol[m].id > val) {
			r = m;
		}
		else {
			l = m;
		}
	}
	return (l+r) >> 1;
}

void read() {
	cin >> n >> M;
	v.clear();
	int aux;
	string s;
	for(int i = 0; i < n; ++i) {
		cin >> aux >> s;
		v.pb(dato(aux, s));
	}
}

void print() {
	for(int i = 0; i < n; ++i) {
		cout << sol[i].id << ' '  << sol[i].s << '\n'; 
	}
}
void printv() {
	for(int i = 0; i < n; ++i) {
		cout << v[i].id << ' ' << v[i].s << '\n'; 
	}
}

int getsol() {
	int total = 0;
	for(int i = 0; i < n; ++i) {
		total += sol[i].id;
	}
	return total;
}

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


int main() {
	srand(time(NULL));
	// read
	read();
	
	// new sol
	// copy
	sol = vector<dato>(v);
	sort(sol.begin(), sol.end(), comp);
	
	// print sol
	print();
	
	// print points
	cout << getsol() << '\n';
	int pos = 59;
	cout << "Busca posicion " << pos << " -> id = " << sol[bs(pos)].id << '\n';
	
	
	/*
	
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
*/
	
}





