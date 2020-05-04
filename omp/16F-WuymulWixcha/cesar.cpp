#include <iostream>
#include <string>
using namespace std;

/*

Descodificacion:

F - Caesar Coding 
Context

Roman emperor Julius Caesar was one of the first great characters of history to encrypt the messages to his military commanders. According to historian Gaious Suetonius: "if he had anything confidential to say, he wrote it in cipher, that is, by so changing the order of the letters of the alphabet, that not a word could be made out".

Caesar always used a shift of 3 letters in the alphabet to the right. Many centuries have passed since the times of Julius Caesar, so the science of encryption has made a tremendous progress. For example, a remarkable recent improvement consists in using different shift values, instead of only 3.
The Problem

The first obvious problem is to decrypt this message. If you are reading this, surely you have already done it. So the rest of this problem is very easy.

Write a program that, given an integer number, N, and a text, encrypts it by using Caesar coding. Encryption should be done as follows. Letters from 'A' to 'Z' have to be shifted N positions to the right, circularly. Lowercase letters from 'a' to 'z' also have to be shifted N positions to the right, circularly. The rest of characters do not have to be modified.
The Input

The input consists of a series of test cases. Each test case in described in two lines. The first line contains an integer number, indicating to amount of shift to apply. The following line contains a text to encrypt. Only standard ASCII characters will appear.

The input will end with a line containing 0.
The Output

For each test case, the program has to produce one line. This line consists of the corresponding encrypted text.
Sample Input

14
This is not a very good method...
8
But it was the 1st one in History.
-100
Now, in 2016, there are better techniques, or not?
0

Sample Output

Hvwg wg bch o jsfm uccr ashvcr...
Jcb qb eia bpm 1ab wvm qv Pqabwzg.
Rsa, mr 2016, xlivi evi fixxiv xiglrmuyiw, sv rsx?

*/


string cesar(string s, int n) {
	n = n%26;	//Hay 26 caracteres Ascii
	string cesar = s;
	for (int i = 0; i < s.length(); ++i) {
		if ((s[i] >= 'a') && (s[i] <= 'z')) {		//Solo las letras
			int numAscii = (int)(s[i] + n);		//Debido a la representacion sesgada de los caracteres
								//Necesitamos esta variable auxiliar
			if (numAscii < (int)'a')
				numAscii += 26;
			if (numAscii > (int)'z')
				numAscii -= 26;
			cesar[i] = numAscii;
		}
		else if ((s[i] >= 'A') && (s[i] <= 'Z')) {		//Solo las letras
			int numAscii = (int)(s[i] + n);		//Debido a la representacion sesgada de los caracteres
								//Necesitamos esta variable auxiliar
			if (numAscii < (int)'A')
				numAscii += 26;
			if (numAscii > (int)'Z')
				numAscii -= 26;
			cesar[i] = numAscii;
		}
	}
	return cesar;
}

int main () {
	int desfase = 6;
	while(true) {
		//cin >> desfase;
		if (desfase == 0)
			break;
		string s;
		getline(cin, s);
		cout << cesar(s, desfase) << '\n';
	}
}
