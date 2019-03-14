#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int cont = 0, n = 1;
	cin >> n;
	while(n > 0){
		cont++;
		int a[n];
		int sum = 0, avg = 0;

		for (int i = 0; i < n; i++){
			cin >> a[i];
			sum += a[i];
		}
		avg = sum / n;
		sum = 0;
		for (int i = 0; i < n; i++){
			sum += abs(avg - a[i]);
		}
		cout << "Set #" << cont << endl << "The minimum number of moves is ";
		
		cout << sum / 2 << ".\n\n";
		cin >> n;
	}
	return 0;
}