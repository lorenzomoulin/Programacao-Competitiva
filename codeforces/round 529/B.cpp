#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	int menor = min(a[n - 2] - a[0], a[n - 1] - a[1]);
	cout << menor << endl;
	return 0;
	
}