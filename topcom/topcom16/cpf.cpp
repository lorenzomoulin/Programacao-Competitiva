#include <bits/stdc++.h>
#define rep(i, a, b) for(int i= a; i <(b); ++i)
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int a[11];
        scanf("%1d%1d%1d.%1d%1d%1d.%1d%1d%1d-%1d%1d", &a[0], &a[1], &a[2], &a[3], &a[4] ,&a[5], &a[6] ,&a[7] ,&a[8], &a[9] ,&a[10]);
        int b[11];
        int m = 10;
        int s = 0;
        rep(i, 0, 9){
            s += m*a[i];
            m--;
        }
        (s % 11 == 1 || s % 11 == 0) ? b[9] = 0 : b[9] = 11 - s % 11;
        s = 0;
        m = 11;
        rep(i, 0, 10){
            s += m*a[i];
            m--;
        }
        (s % 11 == 1 || s % 11 == 0) ? b[10] = 0 : b[10] = 11 - s % 11;
        if (b[10] == a[10] && b[9] == a[9])
            cout << "CPF verificado!\n";
        else
            cout << "CPF incorreto!\n";
    }
    return 0;
}
