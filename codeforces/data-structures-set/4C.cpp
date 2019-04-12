#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin  >> n;
    map<string, int> msi;
    while (n--){
        string s;
        cin >> s;
        
        if(msi[s] == 0)
            cout << "OK\n";
        else
            cout << s << msi[s] <<"\n";
        msi[s]++;
    }
    return 0;
}
