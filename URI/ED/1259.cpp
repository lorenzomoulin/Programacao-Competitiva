#include <bits/stdc++.h>
#define pb push_back
#define OUT(a) for(int i = 0; i < a.size(); i++)cout<<a[i]<<endl;
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> pares, impares;
	while (n--){
		int a;
		cin >> a;
		if (a % 2)
			impares.pb(a);
		else 
			pares.pb(a);
	

	}
	stable_sort(pares.begin(), pares.end());
	stable_sort(impares.begin(), impares.end(), greater<int>());

	OUT(pares);
	OUT(impares);
	
	return 0;
}
