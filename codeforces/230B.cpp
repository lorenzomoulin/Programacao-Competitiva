#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MAXN 10000005
bitset<MAXN> bs;
vector<ll> sqprimes;

void sieve(){
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i  <= 1000000; i++){
        if (bs[i]){
            for (ll j = i * i; j <= (ll)1000000; j += i)   bs[j] = 0;
            sqprimes.push_back(i * i);
        }
    }
}

int main(){
    ll n; cin >> n;
    sieve();
    while (n--){
        ll x; cin >> x;
        if (binary_search(sqprimes.begin(), sqprimes.end(), x)) cout << "YES\n";
        else    cout << "NO\n";
    }
    return 0;
}
