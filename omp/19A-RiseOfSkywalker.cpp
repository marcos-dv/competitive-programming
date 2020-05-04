#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MAXN = 1000006;

int n, arr[MAXN], d;

int main() {
	int casos;
	cin >> casos;
	for (int cas = 1; cas <= casos; cas++) {
		cin >> n;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sum+=arr[i];
		}
		sort(arr, arr+n, greater<int>());
		int i = 0, d = 0;
		while (d*2 <= sum) {
			d+=arr[i];
			i++;
		}
		cout << "Case " << cas << ": " << i << " planets" << endl;
	}

}
