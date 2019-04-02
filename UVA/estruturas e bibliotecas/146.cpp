#include <bits/stdc++.h>

using namespace std;

int main(){

    while(true){
        string a;
        cin >> a;
        if (a.compare("#") == 0)
            break;
        if(next_permutation(a.begin(), a.end()))
            cout << a << endl;
        else 
            cout << "No Successor\n";
    }
    return 0;
}
