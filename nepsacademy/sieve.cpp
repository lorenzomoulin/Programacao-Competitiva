#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAXN 10000009
ll sievesize;
bitset<MAXN> bs;
vector<ll> primes;

void sieve(ll n){
    sievesize = n;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= sievesize; ++i){
        if(bs[i]){
            for (ll j = i * i ; j <= sievesize; j += i)
                bs[j] = 0;
            primes.push_back(i);
        }
    }
}


int main(){
    ll n;
    cin >> n;
    sieve(n);
    if (primes.size())
        cout << primes[0];
    for(int i = 1; i < primes.size(); ++i){
        cout << " " << primes[i];
    }
    cout << "\n";
    return 0;
}
