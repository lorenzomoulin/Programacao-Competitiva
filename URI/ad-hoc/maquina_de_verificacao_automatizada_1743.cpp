#include <bits/stdc++.h>

using namespace std;

int main(){
    int x[5];
    for (int i = 0; i < 5; i++)
        cin >> x[i];
    for (int i = 0; i < 5; i++){
        int y; cin >> y;
        if (x[i] == y){
            cout << "N\n";
            return 0;
        }
    }
    cout << "Y\n";
        
    
    return 0;
}
