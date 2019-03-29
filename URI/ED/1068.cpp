#include <bits/stdc++.h>
#define FOR(i, j, k) for(int i = j; i < k; i++)

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	string s;
	while (cin >> s){
		stack<char> sc;
		bool flag = true;
		FOR(i, 0, s.size()){
			if(s[i] == '('){
				sc.push(s[i]);
			}
			else if(s[i] == ')'){
				if(sc.size())
					sc.pop();
				else{
					flag = false;
					break;
				}
			}
		}
		if (flag){
			sc.size()? cout << "incorrect\n": cout << "correct\n";
		}
		else{
			cout << "incorrect\n";	
		}
		//!flag? cout << "incorrect\n": cout << "correct\n";

		//sc.size() > 0? cout << "incorrect\n": cout << "correct\n";
	}
	return 0;
}
