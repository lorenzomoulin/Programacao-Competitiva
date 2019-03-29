#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if (!s.compare("1") || !s.compare("78") || !s.compare("4"))
            cout << "+\n";
        else if (!s.substr(s.size() - 2, 2).compare("35"))
            cout << "-\n";
        else if (s[0] == '9' && s[s.size()-1] == '4')
            cout << "*\n";
        else if (!s.substr(0, 3).compare("190"))
            cout << "?\n"; 
               
    }
    return 0;
}
