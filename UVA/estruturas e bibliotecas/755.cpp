#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string cast(string s){
	string nova = "", copia = "";
	for (int i = 0; i < s.size(); i++){
		if (s[i] != '-'){
			copia += s[i];
		}
	}
	for (int i = 0; i < copia.size(); i++){
		char a = copia[i];
		if (a <= '9' && a >= '0')
			nova += a;
		else if (a>= 'A' && a <= 'C')
			nova += '2';
		else if (a>= 'D' && a <= 'F')
			nova += '3';
		else if (a>= 'G' && a <= 'I')
			nova += '4';
		else if (a>= 'J' && a <= 'L')
			nova += '5';
		else if (a>= 'M' && a <= 'O')
			nova += '6';
		else if (a == 'P' || a == 'R' || a == 'S')
			nova += '7';
		else if (a>= 'T' && a <= 'V')
			nova += '8';
		else if (a>= 'W' && a <= 'Y')
			nova += '9';
	}
	return nova;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--){
		int n; 
		cin >> n;
		string tel_num[n];
		string lista[n];
		for (int i = 0; i < n; i++){
			cin >> tel_num[i];
			lista[i] = cast(tel_num[i]);
		}
		sort(lista, lista + n);
		int cont = 0;
		bool dupl = false;
		for (int i = 0; i < n - 1; i += cont + 1){
			cont = 0;
			int j = i + 1;
			while(lista[i].compare(lista[j]) == 0){
				j++;
				cont++;
				dupl = true;
				if (j > n - 1)
					break;
			}
			if (cont >= 1){
				for (int k = 0; k < 7; k++){
					if(k == 3){
						cout << '-' << lista[i][k];
					}
					else{
						cout << lista[i][k];
					}
				}
				cout << " " << cont + 1 << endl; 
			}
		}	
		if (dupl == false)
			cout << "No duplicates.\n";
		if (t >= 1)
			cout << endl;
	}
	return 0;
}