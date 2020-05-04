#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MAXN = 20002;
bitset<400> arr1[MAXN], arr2[MAXN];
int n;
string s;


int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int  j = 0; j < (int) s.size(); j++) {
			if (s[j] == 'A') {
				arr1[i].set((j<<2), 1);			
				arr2[i].set((j<<2), 1);
			} else if (s[j] == 'G') {
				arr1[i].set((j<<2)+1, 1);
				arr2[i].set((j<<2)+1, 1);
			} else if (s[j] == 'C') {
				arr1[i].set((j<<2)+2, 1);			
				arr2[i].set((j<<2)+2, 1);
			} else if (s[j] == 'T') {
				arr1[i].set((j<<2)+3, 1);
				arr2[i].set((j<<2)+3, 1);
			} else {
				arr1[i].set((j<<2), 1);
				arr1[i].set((j<<2)+1, 1);
				arr1[i].set((j<<2)+2, 1);
				arr1[i].set((j<<2)+3, 1);
			}
		}
		
		bool im = false;
		for (int j = 0; j < i; j++) {
			if ((~arr1[j] & arr2[i]) == 0) {
				if (!im) {
					cout << i+1 << ":";
					im = true; 
				}
				cout << " " << j+1;
			}
		}
		if (im) cout << endl;
	}
	
}
