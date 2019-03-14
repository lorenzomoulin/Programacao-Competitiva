#include <iostream>
using namespace std;

int main(){
	int t;cin >> t;
	while(t--){
		int x;
		cin >> x;
		if(x <= 7){
			cout << 1 << endl;
			continue;
		}
		if (x % 5 == 0){
			cout << x / 5 << endl;
			continue;
		}
		if (x % 10 <= 7 && x % 10 > 1){
			cout << x / 5 + 1 << endl;
			continue;
		}
		if (x % 10 == 1){
			cout << (x - 5) / 5 + 2 << endl;
			continue;
		}	
		if (x % 10 > 7){
			cout <<x  / 5 + 1 << endl;
		}
	}
	return 0;
}