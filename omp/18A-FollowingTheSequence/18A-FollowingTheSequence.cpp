#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	int nc;
	ll a, b, c, d;
	cin >> nc;
	while (nc--) {
		cin >> a >> b >> c >> d;
		if (b == 0 && c == 0 && d == 0)
			cout << 0;
		else if ((d-c == c-b) && (c-b == b-a)) 
			cout << d+(b-a);
		else if ((d-c == c-b+1) && (c-b == b-a+1)) 
			cout << d+(d-c)+1;
			//Producto en cruz
			//+ sucesion con sentido
		else if ((b != 0) && (c != 0) && (d != 0) && (b*b == c*a) && (c*c == d*b) && ((d*d % c) == 0)) 
			cout << d*d/c;
		else if ((c == a+b) && (d == b+c)) 
			cout << d+c;
		else
			cout << 42;
		cout << endl; 
	}
}


/*

Sample Input

6
5 6 7 8
1 3 6 10
3 6 12 24
1 2 3 5
1 1 2 2
10000 1000 100 10

Sample Output

9
15
48
8
42
1

*/

