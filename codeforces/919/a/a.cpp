#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

int main() {
	int n;
	double a, b, act, m;
	double min = numeric_limits<double>::infinity();
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		act = a/b;
		if (act < min)
			min = act;
	}
	cout << setprecision(9) << min*m;
}
