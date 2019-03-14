#include <iostream>
using namespace std;
typedef long long ll;
#define MOD 1000000009
#define INV 833333341
ll fat[100001];

void calc(){
    fat[0] = 1;
    for (ll i = 1; i <= 100000; i++) fat[i] = (fat[i - 1]*i) % MOD;
}

int main(){
    ll n;
    calc();
    while (true){
        cin >> n;
        if (!n) break;
        cout << (fat[n]*INV) % MOD << endl;
    }
    return 0;
}
