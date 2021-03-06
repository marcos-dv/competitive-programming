#include <iostream>
#include <iomanip>	//redondeo a centesimas

using namespace std;

//Factorial
double fact (double n) {
	if (n == 0)
		return 1;
	double f = 1;
	for(int i = 2; i <= n; ++i)
		f*=i;
	return f;
}

//numero combinatorio (n r) (POSIBLE CAMBIO DE FORMULA)
double NC (double n, double r) {
	return fact(n)/(fact(r)*fact(n-r));
}

//Binomial negativa, (r =) veces que NO ocurre suceso de probabilidad p, hasta que ocurre n veces
double BN (double n, double p, double r) {
	double p1 = 1;
	for(int i = 0; i < r; ++i)
		p1*=(1-p);
	double p2 = 1;
	for(int i = 0; i < n; ++i)
		p2*=p;
	return p1*p2*NC(n+r-1, r);	
}

void solve() {
	double p;
	double n;
	
	cin >> n >> p;
	
	//Casos extremos
	if (p == 0)
		cout << "0.00\n";
	else if (p == 1)
		cout << "1.00\n";
	else {
		double suma = 0;
		//Necesitamos la probabilidad de que B gane menos de n veces (ya que son 2n-1 partidos, debe ganar 0 .. n-1 como mucho)
		for(int i = 0; i < n; ++i)
			suma += BN(n, p, i);

		cout << fixed << setprecision(2) << suma << endl;
	}
}

int main() {
	int ncasos;
	for(cin >> ncasos; ncasos > 0; --ncasos) {
		solve();
	}
}

