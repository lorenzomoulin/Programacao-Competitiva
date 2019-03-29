#include <bits/stdc++.h>

using namespace std;

int main(){
    int cases = 1;
    while (true){
        string in;
        cin >> in;
        if (in.compare("*") == 0)
            break;
        
        if (in.compare("Hajj") == 0){
            cout << "Case " << cases << ": Hajj-e-Akbar\n";
        }
        else 
            cout << "Case " << cases << ": Hajj-e-Asghar\n"; 
        cases++;
    }
    return 0;
    }
