#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int t;
    while(cin >> t){
        while(t--){
            int n;float total = 0;cin >> n;
            for (int i = 0; i < n; i++){
                int a,b,c;
                cin >> a >> b >> c;
                float media = (float)a/ b;
                media *= c;
                total += media*b;
            }
            
            cout << (int)total << endl;
       }
        
    }
    return 0;
}

