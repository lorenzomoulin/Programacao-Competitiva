#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	int res = 0;
	bool formed[n] = {false};
	for (int i = 0; i < n; i++){
		cin >> a[i];
		formed[i] = false;	
	}
	sort(a, a + n);
	for (int i = 0; i < n; i += 2){
		res += a[i + 1] - a[i];
	}
	cout << res << endl; 
	return 0;
}