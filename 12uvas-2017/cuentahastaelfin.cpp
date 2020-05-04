#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#define MILLAR 1000

bool solve() {
	vector<int> v(0,0);
	int i = 0; 
	int n;
	if (!(cin >> n))
		return false;
	v.push_back(n);
	while(cin.get() != '\n') {
		cin >> n;
		v.push_back(n);
	}
	
	v[v.size()-1]++;
	for(int i = v.size()-1; i > 0; i--) {
		if (v[i] == MILLAR) {
			v[i] = 0;
			v[i-1]++;
		}
	}
	if (v[0] == MILLAR) {
		v[0] = 0;
		vector<int>::iterator it = v.begin();
		v.insert(it, 1);
	}
	if (v.size() == 1)
		cout << v[i] << endl;
	else
		cout << v[0] << '.'; 
	for(int i = 1; i < v.size()-1; i++) {
		cout << setw(3) << setfill('0') << v[i] << '.';
	}
	if (v.size() != 1)
		cout << setw(3) << setfill('0') << v[v.size()-1] << endl;
	return true;
}

int main() {
	while(solve()) ;
}
