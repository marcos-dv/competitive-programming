//http://codeforces.com/contest/1185/problem/A
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

//Greedy facil pivote ---> a b c  ---> a= b-d < b < b+d= c

ll ab(ll a) {
	if (a < 0)
		return -a;
	return a;
}


int main() {
	ll v[3];
	ll d;
	cin >> v[0] >> v[1] >> v[2] >> d;
	sort(v, v+3);
	ll total = 0;
	if(ab(v[1]-v[0]) < d)
		total += ab(v[0]-(v[1]-d));
	if(ab(v[2]-v[1]) < d)
		total += ab(v[2]-(v[1]+d));
	cout << total << endl;
	return 0;
}
