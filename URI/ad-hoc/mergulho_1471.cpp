#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, r;
    while (cin >> n >> r){
        
        bool a[n + 1];
        
        memset(a, 0 , sizeof a);
        
        for (int i = 0; i < r; i++){
            int b;
            cin >> b;
            a[b] = 1;
        }
        if (n == r){
            cout << "*\n";
            continue;
        }
        bool p = true;
        for (int i = 1 ;i  <= n; i++){
            if (!a[i]){
                cout << i << " ";
            }            
        }
        cout << '\n';
    }
    return 0;
}
