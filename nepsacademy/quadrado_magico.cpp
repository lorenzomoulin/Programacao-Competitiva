#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n][n], soma = 0;
    rep(i, 0, n){
        soma = 0;
        rep(j, 0, n)
            cin >> a[i][j], soma += a[i][j];
    }
    rep(i, 0, n){
        int temp = 0;
        rep(j, 0 , n)
            temp += a[i][j];
        if (temp != soma){
            cout << -1 << "\n";
            return 0;
        }
    }
    rep(j, 0, n){
        int temp = 0;
        rep(i, 0 , n)
            temp += a[i][j];
        if (temp != soma){
            cout << -1 << "\n";
            return 0;
        }
    }
    int temp = 0;
    rep(i, 0, n){
        
        temp += a[i][i];
        
    }
    if (temp != soma){
        cout << -1 << "\n";
        return 0;
    }
    temp = 0;
    rep(i, 0, n){
        
        temp += a[i][n - i - 1];
        
    }
    if (temp != soma){
        cout << -1 << "\n";
        return 0;
    }
    cout << soma << "\n";
    return 0;
}
