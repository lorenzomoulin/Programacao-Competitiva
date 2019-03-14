#include <iostream>
using namespace std;

int main(){
	int n, t;
	cin >> n >> t;
	int a[n - 1];
	t -= 1;
	int res = 0;
	for (int i = 0; i < n - 1; i++){
		cin >> a[i];
	}
	int i;
	for (i = 0; i < n - 1;){
		if(res == t){
			cout << "YES\n";
			return 0;
		}
		res = i + a[i];
		i += a[i];
	}
	if(res == t){
		cout << "YES\n";
		return 0;
	}
	cout << "NO\n";
	return 0;
}