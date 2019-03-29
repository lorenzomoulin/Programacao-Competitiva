#include <bits/stdc++.h>

#define FOR(i, j, k) for(int i = j; i < k; i++)


using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	while(n--){
		string c;
		cin >> c;
		stack<char> s;
		int diamantes = 0;
		FOR(i, 0, c.size()){
			if (c[i] == '<')
				s.push(c[i]);
			else if (c[i] == '>'){
				if (s.size() > 0){
					diamantes++;
					s.pop();
				}
			}
			
		}
		cout << diamantes << endl;
	}
	return 0;
}
