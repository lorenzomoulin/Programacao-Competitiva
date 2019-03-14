#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
using namespace std;

#define MOD 998244353 

typedef long long ll;

string getString(char x) 
{ 
    string s(1, x); 
    return s;    
} 

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool igual = true;
	for (int i = 1; i < s.size(); i++){
		if (s[i] != s[i - 1]){
			igual = false;
			break;
		}
	}
	if (igual){
		ll res = ((((ll)n) * (n + 1)) / 2 )% MOD;
		cout << res << endl;
		return 0;
	}
	vector <string> substrings;
	string temp;
	temp = getString(s[0]);
	for (int i = 1; i < s.size(); i++){
		if (s[i] == s[i - 1]){
			temp += s[i];
		}
		else{
			substrings.push_back(temp);
			temp = getString(s[i]);
		}
	}
	substrings.push_back(temp);
	for (int i = 0; i < substrings.size(); i++){
		cout << substrings[i] << endl;
	}
	//cout << substrings[0] << endl;
	ll tam = substrings.size();
	if (substrings[0][0] == substrings[tam - 1][0]){
		ll res = (2 + (2*(ll)substrings[0].size() - 1) % MOD + (2*(ll)substrings[tam - 1].size() - 1)% MOD) % MOD;
		cout << res << endl;
	}
	else{
		ll res = (1 + (ll)substrings[0].size() % MOD + (ll)substrings[tam - 1].size() % MOD) % MOD;
		cout << res << endl;
	}
	return 0;
}