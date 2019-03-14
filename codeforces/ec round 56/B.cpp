#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool palindrome(string s){
	for (int i = 0; i < s.size() / 2; i++){
		if (s[i] != s[s.size() - 1 - i])
			return false;
	}
	return true;
}

int main(){
	int t; cin >> t;
	while(t--){
		string s;
		cin >> s;
		bool a = true;
		for (int i = 1; i < s.size(); i++){
			if(s[i] != s[i - 1]){
				a = false;
				break;
			}
		}
		if (a){
			cout << -1 << endl;
			continue;
		}
		sort(s.begin(), s.end());
		cout << s << endl;
	}
	return 0;
}