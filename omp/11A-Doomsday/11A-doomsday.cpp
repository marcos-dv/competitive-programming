#include <iostream>
#include <string>
using namespace std;

/*
Doomsday days:
4/4, 6/6, 8/8, 10/10, 12/12
5/9, 9/5, 7/11, 11/7

Facil deducir que son doomsday:
1/10, 2/21, 3/21 (No bisiesto)
*/

//Doomday de cada mes 2011 (bisiesto) mod 7
int doomdays[12] = {-4, 0, 0, -3, -5, -1, -3, -6, -2, -4, 0, -2};
//Nombres de los dias
string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};


//Resuelve un problema individual
int solve(int doomsday) {	
	int month, day;
	cin >> month >> day;
	//Diferencia de dias con doomsday, que siempre sera positiva debido a nuestro array
	return (day-doomdays[month-1])%7;
}


int main() {
	int ncasos;
	int doomsday = 0;	//En 2011 el doomsday es lunes
	for(cin >> ncasos; ncasos > 0; ncasos--) {
		cout << days[solve(doomsday)] << '\n';
	}
}
