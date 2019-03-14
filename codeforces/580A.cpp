#include <iostream>
#define rep(i, n) for (int i = 0; i < n; ++i)
using namespace std;

int main(){
	int n, maior = 1, atual = 1;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 1; i < n; i++){
		if(a[i] >= a[i - 1]){
			atual++;
			if(atual > maior){
				maior = atual;
			}
		}
		else{
			atual = 1;

		}
	}
	cout << maior << endl;
	return 0;
}