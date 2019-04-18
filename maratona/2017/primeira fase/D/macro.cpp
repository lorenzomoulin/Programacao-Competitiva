#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MAXN 10000009

ll sievesize;
bitset<MAXN> bs;
vector<ll> primes;

void sieve(ll n){
    sievesize = n + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= sievesize; i++){
        if(bs[i]){
            for(ll j = i * i; j <= (ll)sievesize; j += i)
                bs[j] = 0;
            primes.push_back(i);
        }
    }
}

set<ll> primeFactors(ll N){
    set<ll> factors;
    ll PF_idx = 0, PF = primes[PF_idx];
    while(PF*PF <= N){
        while(N % PF == 0){
            N /= PF;
            factors.insert(PF);
        }
        PF = primes[++PF_idx];
    }
    if ( N != 1)    factors.insert(N);
    return factors;
} 

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    sieve(1000009);
    ll n;
    cin >> n;
    set<ll> pf = primeFactors(n);
    ll res =  (1LL << pf.size()) - pf.size() - 1;
    cout << res << "\n"; 
    return 0;
}
