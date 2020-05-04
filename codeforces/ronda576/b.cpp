//https://codeforces.com/contest/1199
#include<bits/stdc++.h>
#define pb push_back

using namespace std;
typedef long long ll;

int main() {
	double H, L;
	cin >> H >> L;
	double x = L*L-H*H;
	x /= 2*H;
	cout << fixed << setprecision(8) << x << endl;
}
