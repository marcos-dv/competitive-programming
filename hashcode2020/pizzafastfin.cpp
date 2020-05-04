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
vi taken;
int v [N];


// mete todas al principio

int main() {
	cin >> M >> n;
	string sol;
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	for(int i = n-1; i >= 0; --i) {
		if (M - v[i] >= 0) {
			taken.pb(i);
			M-=v[i];
		}
		else
			break;
	}
	cout << taken.size() << endl;
	for(auto i: taken)
		cout << i << ' ';
	cout << endl;
}





