#include <bits/stdc++.h>
#define FOR(i, j, k) for(int i = j; i <k ; i++)
#define pb push_back


using namespace std;

int main(){
	int n;
	while(true){
		cin >> n;
		if(!n)break;
		vector<int> si;
		for(int i = n; i >= 1; i--){
			si.pb(i);
		}
		cout << "Discarded cards: " << si[si.size() - 1];
		si.pop_back();
		vector<int> temp;
		temp.pb(si[si.size()-1]);
		
		while(si.size() > 1){
			
			
			cout << ", " << si[si.size() -1 ] ;
			si.pop_back();
			
			for (int i = 0; i < si.size(); i++){
				temp.pb(si[i]);
			}
			si = temp;
		}
		cout << "Remaining card: " << si[0] << endl;
	}
	return 0;
}
