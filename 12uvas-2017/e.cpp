#include<iostream>
#include <iomanip>

using namespace std;

void solve() {
	int h, m, s;
	char p;
	
	cin >> h >> p >> m >> p >> s;
	//Comparamos con la hora 23:59:60
	
	h = 23-h;
	m = 59-m;
	s = 60-s;
	if (s==60) {
		m++;
		s = 0;
	}
	if (m==60) {
		m = 0;
		h++;
	}
	cout << setw(2) << setfill('0') << h  << ":" 
	<< setw(2) << setfill('0') << m << ":" 
	<< setw(2) << setfill('0') << s << endl;
}

int main() {
	int ncasos;
	for(cin >> ncasos; ncasos > 0; ncasos--)
		solve();
}
