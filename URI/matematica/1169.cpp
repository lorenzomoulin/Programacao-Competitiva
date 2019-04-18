#include <bits/stdc++.h>

using namespace std;

int main(){
    unsigned long long n;
    cin >> n;
    while(n--){
        int t;
        cin >> t;
        //1kg = 1000g*12 graos
        unsigned long long res = pow(2, t - 5);
        res /= 375ULL;
        cout << res << " kg\n";
    }
    return 0;
}
