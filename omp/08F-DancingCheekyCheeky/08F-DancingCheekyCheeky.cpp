#include <iostream>

using namespace std;

string s;

/*
            n/3     n/2                n
############ # ##### # #################

*/


int main() {
	int nc, n;
	cin >> nc;
	while (nc--) {
		cin >> s;
		n = (int)s.length();
		for(int i = n/3; i < n/2; ++i) {
			//Patron de i+1 size
			//Secuencia va de [0 a i]
			bool valid = true;
			for(int j = 0; i+j+1 < n; ++j) {
				if (s[i+j+1] != s[j%(i+1)]) {
					valid = false;
					break;
				}
			}
			if (valid) {
			//8 siguientes pasos
				for(int j = 0; j < 8; ++j) {
					cout << s[(j+n)%(i+1)];
				}
				cout << "...\n";
				break;
			}
		}
	}
}

/*
Sample Input

6
123123
1231231
12312312
123124123124
12312412312412
12312412312412312

Sample Output

12312312...
23123123...
31231231...
12312412...
31241231...
41231241...



*/
