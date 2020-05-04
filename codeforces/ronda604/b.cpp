#include <bits/stdc++.h>
#define N 200005
#define pb push_back
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
		cin >> n;
		int l;
		int r;
		for(int i = 0; i < n; ++i) {
			cin >> p[i];
			if (p[i] == 1) {
				l = i;
				r = i;
			}
		}
		string sol (n,'0');
		sol[0] = '1';
		priority_queue<int> num;
		num.push(1);
		for(int m = 2; m < n; ++m) {
			if(l-1 < 0) {
				num.push(p[r+1]);
				r++;
			}
			else if(r+1 >= n) {
				num.push(p[l-1]);
				l--;
			}
			else {
				if (p[l-1] < p[r+1]) {
					num.push(p[l-1]);
					l--;
				}
				else {
					num.push(p[r+1]);
					r++;
				}
			}
			if (num.top() == m) {
				sol[m-1] = '1'; 
			}
			else
				sol[m-1] = '0';
		}
		sol[n-1] = '1';
		cout << sol << endl;
	}
}
