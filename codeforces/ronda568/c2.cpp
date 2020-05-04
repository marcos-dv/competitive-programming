//http://codeforces.com/contest/1185/problem/C2
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


//Greedy normal
//Usando 1 <= t[i] <= 100 array freq O(100*n)

int main() {
	ll maxti = 100;
	ll n, M, sum;
	cin >> n >> M;
	ll t[n];
	ll freq[maxti+1] = {0};
	
	
	for(int i = 0; i < n; ++i) {
		cin >> t[i];

	}
	sum = t[0];
	freq[t[0]]++;
	cout << 0; //i=0
	for(int i = 1; i < n; ++i) {		
		if(sum+t[i] <= M) {
			sum+=t[i];
			freq[t[i]]++;
			cout << ' ' << 0;
			continue;
		}
		
		ll tiempo = sum+t[i]-M; //Tiempo necesitado
		ll out = 0; //expulsados
		//Vamos quitando
		for(int j = 100; j >= 1; j--) {
			if (freq[j] == 0)
				continue;

			if (j*freq[j] <= tiempo) {
				tiempo -= j*freq[j];
				out += freq[j];
			}
			else {
				out += (tiempo/j);
				if (tiempo % j != 0)
					out++;

				break;
			}
		}
		sum+=t[i];
		freq[t[i]]++;
		cout << ' ' << out;
	}
	
	cout << endl;
	
}
