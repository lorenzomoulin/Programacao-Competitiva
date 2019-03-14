#include <iostream>
#include <bitset>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 50847600ll
#define pb push_back

typedef long long ll;
ll sievesize;
bitset<MAXN> bs;
vector<ll> primes;

void sieve(ll n){
    sievesize = n + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= sievesize; i++){
        if (bs[i]){
            for (ll j = i * i; j <= (ll)sievesize; j += i)  bs[j] = 0;
            primes.pb(i);
        }
    }
}

int main(){
    ll n;
    sieve(MAXN);
    while (cin >> n){
        ll maior = -1000000000;
        for (ll i = 1; primes[i] <= n; i++) {
            ll dif = primes[i] - primes[i - 1];
            if (dif > maior)  maior = dif;
        }
        cout << maior << endl;
    }
}
