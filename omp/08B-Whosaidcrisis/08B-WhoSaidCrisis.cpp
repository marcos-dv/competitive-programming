#include <bits/stdc++.h>

using namespace std;

// Compara a y b: 1 a<b; 0 a=b; -1 a>b
int smaller(string a, string b) {
	if (a.length() < b.length())
		return 1;
	else if (b.length() < a.length())
		return -1;
	else {
		for(int i = 0; i < (int)a.length(); ++i) {
			if (a[i] != b[i])
				return (a[i] < b[i])?1:-1;
		}
		return 0;
	}
}

string diff(string a, string b) {
	int ret = smaller(a,b);
	if (ret == 0)
		return "0";
	if (ret > 0)
		swap(a,b);
	// a > b
	string dif = "";
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int carry = 0;
	for(int i = 0; i < (int)a.length(); ++i) {
		int up = a[i]-'0';
		int down = carry;
		if (i < (int)b.length())
			down += b[i]-'0';
		if (up < down) {
			up += 10;
			carry = 1;
			dif += (char)(up-down+'0');
		}
		else {
			carry = 0;
			dif += (char)(up-down+'0');
		}
	}
	if (ret > 0) {
		dif += '-';
	}
	reverse(dif.begin(), dif.end());
	string dif2 = "";
	int i = 0;
	if (ret > 0)
		dif2 += dif[i++];
	while (dif[i] == '0')
		++i;
	dif2.append(dif, i, dif.length()-i);
	return dif2;
}

int main() {
	string a, b;
	int n;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		cout << diff(a, b) << endl;
	}
}
