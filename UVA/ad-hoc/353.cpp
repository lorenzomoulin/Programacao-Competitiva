#include <bits/stdc++.h>

using namespace std;

bool palindrome(string s){
    for (int i = 0; i < s.size() / 2; i++){
        if (s[i] != s[s.size() - i  -1])
            return false;
    }
    
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    string s;
       
    while (cin >> s){
        set<string> p;
        for (int i = 0; i < s.size(); i++){
            p.insert(s.substr(i, 1));
        }
        for (int i = 1; i <= s.size(); i++){
            for (int j = 0; j < s.size(); j++){
                if (j + i > s.size() -1)
                    break;
                if(palindrome(s.substr(j, i + 1))){
                    p.insert(s.substr(j, i + 1));
                       //cout << s.substr(j, i + 1) << endl;
                }
                     
                //cout << j << i << endl;
            }
        }        
        cout << "The string '" << s << "' contains "  << p.size() << " palindromes."<< endl;
    }
    return 0;
}
