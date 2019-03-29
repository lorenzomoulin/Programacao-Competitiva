#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a % b ): a;
}

int main(){
	int n;
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	while (cin >> n){
		FOR(i, n){
			int n1, d1, n2, d2, nf, df, nf2 , df2;
			char op, temp;
			cin >> n1 >> temp >> d1 >> op >> n2 >> temp >> d2;
			if (op == '+'){
				nf = n1 * d2 + n2*d1;
				df = d1 * d2;

			}
			else if (op == '-'){
				nf = n1*d2 - n2*d1;
				df = d1*d2;

			}
			else if (op == '*'){
				nf = n1* n2;
				df = d1*d2;
			}
			else {
				nf = n1*d2;
				df = n2*d1;
			}

			int m = gcd(nf, df);
			///cout << m << endl;
			nf2 = nf/m;
			df2 = df/m;
			if (nf2 < 0 && df2 < 0){
				nf2 *= -1;
				df2 *= -1;
			}
			else if(nf2 >= 0 && df2 < 0) {
				df2 *= -1;
				nf2 *= -1;
			}
			if (nf < 0 && df < 0){
				nf *= -1;
				df *= -1;
			}	
			else if(nf >= 0 && df < 0) {
				df *= -1;
				nf *= -1;
			}
			cout << nf << "/" << df << " = " << nf2 << "/" << df2 <<endl;
		}
	}
	return 0;
}
