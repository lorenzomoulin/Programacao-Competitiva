#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    scanf("\n");
    while(n--){
        string s;
        getline(cin, s);
        
        set<char> sc;
        for (auto &a : s)
            if (a >= 'a' && a <= 'z')
                sc.insert(a);
        if ((int)sc.size() == 26)
            cout << "frase completa\n";
        else if ((int)sc.size() >= 13)
            cout << "frase quase completa\n";
        else 
            cout << "frase mal elaborada\n";
    }
    return 0;
}
