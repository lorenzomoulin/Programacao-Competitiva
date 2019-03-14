#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

int maior(ll n){
	int i = 1;
	while ((i + 1)*i < n){
		i++;
	}
	return i;
}



int main(){
	ll n, res;
	cin >> n;
	int i = maior(n);
	if (n >= (i + 1)*i - (i - 1)){
		cout << 2 * i + 1 << endl;
	}
	else
		cout  << 2*i << endl;
	
	return 0;
}