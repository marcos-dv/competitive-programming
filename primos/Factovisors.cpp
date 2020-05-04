#include <bits/stdc++.h>

#define FACT first
#define FREQ second

using namespace std;
typedef long ll;
typedef pair<ll, ll> pii;

const long long MAXN = 10000000001;

// Smallest Prime Factor
int spf[MAXN]; 

// Calculo del menor factor primo, modificacion del algoritmo de eratostenes
// https://www.geeksforgeeks.org/prime-factorization-using-sieve-olog-n-multiple-queries/
// Time Complexity : O(nloglogn)
void sieve() 
{ 
	spf[1] = 1; 
	for (int i=2; i<MAXN; i++) 
		// Marca cada numero como su menor factor primo
		spf[i] = i; 

	// Los pares se ponen spf = 2
	for (int i=4; i<MAXN; i+=2) 
		spf[i] = 2; 

	for (int i=3; i*i<MAXN; i++) 
	{ 
		// Si spf[i] = i, es que no tenia divisores, es primo
		if (spf[i] == i) 
		{ 
			// Marca todos los multiplos de i que no estuvieran ya marcados
			// Ojo, si fuera j = i*k con k < i, entonces k | j con k < i
			// luego spf[j] no seria i, sino k, por eso i*i
			for (int j = i*i; j < MAXN; j += i) 
				
				// Si no estaba marcado, lo marcamos
				if (spf[j]==j)
					spf[j] = i; 
		} 
	} 
} 

// Devuelve una lista ordenada de factores primos de x (repetidos)
// Complejidad: O(log n)
vector<ll> getFactorization(ll x) 
{ 
	vector<ll> ret; 
	while (x != 1) 
	{ 
		ret.push_back(spf[x]); 
		x = x / spf[x]; 
	} 
	return ret; 
} 

// Convierte el vector de factores primos repetidos, en un vector
// de pares (k, freq), donde k es primo y aparece freq veces
// en la factorizacion
vector<pii> compactar(vector<ll> v) {
	vector<pii> ret;
	unsigned int i = 0;
	pii p;
	p.FACT = -1;
	while (i < v.size()) {
		if (p.FACT != v[i]) {	//Si es un primo nuevo
			if (i != 0)
				ret.push_back(p);
			p.FACT = v[i];
			p.FREQ = 1;	//Ha aparecido por primera vez
		}
		else	//Si ha aparecido antes
			p.FREQ++;
		i++;
	}
	ret.push_back(p);
	return ret;
}

// devuelve la factorizacion de producto de v1 y v2
vector<pii> factorizacionProd(vector<pii> v1, vector<pii> v2) {
	// indices para recorrer factorizaciones
	unsigned int i1 = 0, i2 = 0;
	pii par;
	vector<pii> ret;
	while (i1 < v1.size() && i2 < v2.size()) {
		ll k1 = v1[i1].FACT;	// factor actual de v1
		ll k2 = v2[i2].FACT;	// factor actual de v2
		ll freq1 = v1[i1].FREQ;	// num apariciones de k1 en v1
		ll freq2 = v2[i2].FREQ;	// num apariciones de k2 en v2
		// es factor comun
		if (k1 == k2) {
			par.FACT = k1;
			par.FREQ = freq1 + freq2;
			ret.push_back(par);
			i1++; //factor procesado en v1
			i2++; //factor procesado en v2
		}
		// para tener la factorizacion ordenada
		if (k1 < k2) {
			// inserta factor k1 (< k2)
			par.FACT = k1;
			par.FREQ = freq1;
			ret.push_back(par);
			i1++; //factor procesado en v1
		}
		//analogo al anterior
		if (k2 < k1) {
			par.FACT = k2;
			par.FREQ = freq2;
			ret.push_back(par);
			i2++;
		}
	}
	//Tal vez v1 o v2 no haya terminado de procesarse
	while (i1 < v1.size()) {
		ll k1 = v1[i1].FACT;	// factor actual de v1
		ll freq1 = v1[i1].FREQ;	// num apariciones de k1 en v1
		par.FACT = k1;
		par.FREQ = freq1;
		ret.push_back(par); // insertamos el factor
		i1++; // siguiente factor
	}
	while (i2 < v2.size()) {
		ll k2 = v2[i2].FACT;	// factor actual de v2
		ll freq2 = v2[i2].FREQ;	// num apariciones de k2 en v2
		par.FACT = k2;
		par.FREQ = freq2;
		ret.push_back(par); // insertamos el factor
		i2++; // siguiente factor
	}
	return ret;
}

// Calcula la factorizacion en primos de n!
vector<pii> factorizacionFact(int n) {
	vector<pii> ret;
	for(int k = 2; k <= n; ++k) {
		// Factorizacion del factor actual
		vector<pii> facto = compactar(getFactorization(k));
		// Factorizacion del producto de todos hasta el factor actual
		ret = factorizacionProd(ret, facto);
	}
	return ret;
}

// Calcula la factorizacion en primos de n^expo
vector<pii> factorizacionPow(vector<pii> v, int expo) {
	vector<pii> ret(v);
	for(unsigned int i = 0; i < ret.size(); ++i) {
		ret[i].FREQ *= expo;
	}
	return ret;
}

// devuelve true si v1 divide a v2 -> v1 | v2, false en otro caso
bool divide (vector<pii> v1, vector<pii> v2) {
	unsigned int j = 0;
	for(unsigned int i = 0; i < v1.size(); ++i) {
		while ((j < v2.size()) && (v2[j].FACT < v1[i].FACT)) {
			j++;
		}
		// en v2 no quedan factores
		if (j >= v2.size()) {
			return false;
		}
		if (v2[j].FACT == v1[i].FACT) {
		// los factores aparecen menos veces de las necesarias
			if (v2[j].FREQ < v1[i].FREQ) {
				return false;
			}
			j++;
		}
		else if (v2[j].FACT > v1[i].FACT) {
			// el factor vi1[i].fi NO aparece en v2
			return false;
		}
	}
	return true;	
}

// Programa 
int main(int argc, char const *argv[]) 
{ 	
	ll n, m;
	sieve(); 
	while (cin >> n >> m) {
		vector<pii> nfact = factorizacionFact(n);
		vector<pii> mm = compactar(getFactorization(m));

		if (divide(mm, nfact)) {
			cout << m << " divides " << n << "!" << endl;
		}
		else {
			cout << m << " does not divide " << m << "!" << endl;
		}
	}
	return 0;
} 



