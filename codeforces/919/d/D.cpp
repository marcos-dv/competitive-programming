#include <iostream>
#include <list>
#include <vector>
#include <string.h>

#define MAX_NODOS 26

using namespace std;

int nnodos;
int naristas;
list<int> arrayLista[MAX_NODOS];
bool visitado[MAX_NODOS]; 
string lectura;
int chars[MAX_NODOS];

void leeGrafo (void)
{
 cin >> nnodos >> naristas;
 cin >> lectura;

 int l1, l2;

 for(int i=0; i<naristas; i++) {

	cin >> l1 >> l2;
	arrayLista[l1 - 1].push_back(l2 - 1);
 }
}

void bpp(int v)
{
 visitado[v]= true;
 char c = lectura.at(v);
 chars[(int) c - 'a']++;
 list<int>::iterator it;
 it=arrayLista[v].begin();
 while(it!=arrayLista[v].end()){
 int w=*it;
 if (!visitado[w])
	 bpp(w);;

 it++;
 }
}
void busquedaPP ()
{
 memset(visitado, 0, sizeof(visitado));
 bpp(0);
}

int main () {

 leeGrafo();
 busquedaPP();
 list<int> a[MAX_NODOS] = arrayLista;
 int resultado = 0;

 for(int i = 0; i < MAX_NODOS; i++){

	if(chars[i] > resultado)
		resultado = chars[i];

}

cout << resultado << endl;

} 
