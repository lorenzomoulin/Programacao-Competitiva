#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int table[256];
    memset(table, 0, sizeof table);
    int longest = 0, length = 0;
    cout << s.size() << endl;
    for (int i = 0; i < (int)s.size(); ++i){
        if (table[s[i]] == 0){
            table[s[i]]++;
            length++;
        }
        else{
            memset(table, 0, sizeof table);
            length > longest ? longest = length : longest;
            length = 0;
        }
    }
    cout << longest << endl;
    return 0;
}
