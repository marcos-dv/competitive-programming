#include <bits/stdc++.h>
#define push_back pb

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MAXN = 300;

int n, arr[MAXN], d;

ll dp[MAXN][MAXN][2];

int main() {
	int casos;
	cin >> casos;
	for (int cas = 1; cas <= casos; cas++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			dp[i][i][0] = arr[i];
			dp[i][i][1] = 0;
		}
		for (int sz = 1; sz < n; sz++) {
			for (int i = 0; i+sz < n; i++) {
				int j = i+sz;
				dp[i][j][0] = max(dp[i+1][j][1]+arr[i],
								  dp[i][j-1][1]+arr[j]);
				if (arr[i] < arr[j]) {
					dp[i][j][1] = dp[i][j-1][0];
				} else if (arr[i] > arr[j]) {
					dp[i][j][1] = dp[i+1][j][0];
				} else {
					dp[i][j][1] = min(dp[i+1][j][0], dp[i][j-1][0]);
				}
			}
		}
		cout << min(dp[0][n-1][0], dp[0][n-1][1]) << endl;
		
	}

}
