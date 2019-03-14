#include <iostream>
using namespace std;

int solve(int n, int m){
	if (m <= n)
		return n - m;
	if (m % 2 == 0)	return 1 + solve(n, m / 2);
	else	return 2 + solve(n, m / 2 + 1);
}

int main(){
	int n, m;
	cin >> n >> m;
	cout << solve(n, m) << endl;
	return 0;
}