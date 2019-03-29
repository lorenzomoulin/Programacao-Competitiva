#include <bits/stdc++.h>

using namespace std;

int f[40];
int r[40];

void calc(){
	f[0] = f[1] = 1;
	r[0] = r[1] = 0;
	f[2] = 1, r[2] = 2;
	f[3] = 2, r[3] = 4;
	for(int i = 4; i < 41; i++){
		f[i] = f[i - 1] + f[i - 2];
		r[i] = r[i - 1] + r[i - 2] + 2;
	}
}

int main(){
	int n;
	cin >> n;
	calc();
	//cout << (1 << -1) << endl;
	while(n--){
		int x;
		cin >> x;
		cout << "fib(" << x << ") = " << r[x] << " calls = " << f[x] << endl;
	}
	return 0;
}
