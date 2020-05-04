#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define MOD 1003
#define N 1005
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, m, c;
int x,y;

bool vi[N];

bool ok;

struct hash_pair {
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    }
};

vii ady[N];
unordered_map<ii, int, hash_pair> ord;
ii age[N];

void dfs(ii v) {
	vi[ord[v]] = true;
	if (v.se == N-1)
		ok = false;
	for(ii u: ady[ord[v]]) {
		if(!vi[ord[u]]) {
			dfs(u);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while ((cin >> m) && (m) && (cin >> n >> c)) {
		for(int i = 0; i < N; ++i)
			ady[i].clear();
		for(int i = 0; i < N; ++i)
			vi[i] = false;
		for(int i = 0; i < c; ++i) {
			cin >> x >> y;
			age[i] = mp(x,y);
			ord[age[i]] = i;
			for(int j = 0; j < i; ++j) {
				int xx = age[j].fi;
				int yy = age[j].se;
				if ((x-xx)*(x-xx)+(y-yy)*(y-yy) <= 400) {
					ady[i].pb(age[j]);
					ady[j].pb(age[i]);
				}
			}
			if (x <= 10) {
				ady[i].pb(mp(0,N-2));
				ady[N-2].pb(age[i]);
			}
			if (x >= m-10) {
				ady[i].pb(mp(N-1,N-1));
				ady[N-1].pb(age[i]);
			}
		}
		ord[mp(N-1,N-1)] = N-1;
		ord[mp(0,N-2)] = N-2;
		ok = true;
		dfs(mp(0,N-2));

		if (ok) {
			cout << "SI\n";
		}
		else {
			cout << "NO\n";
		}
	
	}
	
	
	
}
