#include <iostream>
#include <cmath>
using namespace std;



int main(){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < (1 << n); i++){
		int soma = 0;
		for (int c = n - 1; c >= 0; c--)
		  {
		    int k = i >> c;
		 
		    if (k & 1){
		      soma += a[n - c - 1];
		      //cout << 1;
		      //cout << soma << endl;
		    }
		    else{
		      soma -= a[n - c - 1];
		      //cout << 0;
		      //cout << soma << endl;
		    }
		  }
		  //cout << endl;
		  //cout << "soma: " << soma << endl << endl;
		if (soma % 360 == 0){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}