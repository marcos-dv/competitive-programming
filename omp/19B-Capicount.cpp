#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MAXN = 20;

int arr[MAXN][MAXN], visited[MAXN][MAXN];

ll p10[20];

ll func (ll n) {
	if (n == 0) return 0;
	vi s;
	while (n > 0) {
		s.push_back(n%10);
		n/=10;
	}
	reverse(s.begin(), s.end());
	
	
	n = s.size();
	ll sum = 0;
	int less = 0;
	for (int i = 0; 2*i < n; i++) {
		if (s[i] > 0)
			sum+=(s[i]-(i==0))*p10[(n-2*i-1)/2];
		if (i == n-1-i) {
			if (!less)
				sum++;
		}
		if (i == n-2-i) {
			if (s[n-1-i] > s[i] || (s[n-1-i] == s[i] && !less))
				sum++;
		}
		//cerr << "up to " << sum << endl;
		if (s[i] > s[n-1-i])
			less = 1;
		else if (s[i] < s[n-1-i])
			less = 0;
	}
	for (int i = 1; i < n	; i++) {
		sum+=p10[(i-1)/2]*9;
	}
	return sum;
}

bool cap (ll n) {
	vi s;
	while (n > 0) {
		s.push_back(n%10);
		n/=10;
	}
	reverse(s.begin(), s.end());
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] != s[(int)s.size()-1-i]) {
			return false;
		}
	}
	return true;
}

int main() {
	p10[0] = 1;
	for (int i = 1; i < 20; i++) {
		p10[i]=p10[i-1]*10;
	}
	ll casos;
	cin >> casos;
	ll a, b;
	/*for (ll i = 1, s = 0; i < 10000000; i++) {
		if (cap(i)) s++;
		if (func(i) != s) {
			cerr << i << " " << s << " " << func(i) << endl;
			break;
		}
	}*/
	while(casos--){
		cin >> a >> b;
		if (b < a) swap(a,b);
		cout << func(b)-func(a-1) << endl;
		
	}
}
