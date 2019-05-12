#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        bool a = true;
        for (auto &b : s){
            if (b >= 'a' && b <= 'z' || b >= 'A' && b <= 'Z'){
                if (a){
                    b = toupper(b);
                }
                else
                    b = tolower(b);
                
                a = !a;
            }
            cout << b ;
        }
        cout << '\n';
    }
    return 0;
}
