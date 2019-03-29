#include <bits/stdc++.h>


using namespace std;

#define MAXN 10000009

typedef long long ll;

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

int main(){
    int t;
    ios_base::sync_with_stdio(0);
    cin >> t;
    sieve(100000);
    while(t--){
        ll n, k;
        cin >> n >> k;
        if (n <= k)
            cout << n - 1 << endl;
        else{
            set<ll> res;
            for (ll i = 2; i <= n; i++)
                res.insert(i);
            ll menor = 2;
            int idx = 0;
            for (int i = 0; i < primes.size(); i++){
                if (primes[i] > k){
                    menor = primes[i];
                    idx = i;
                    break;
                }
                    
            }
            while (menor <= n){
                for (int i = menor; i <= n; i += menor)
                    res.erase(i);

                for (int i = idx; i < primes.size(); i++){
                    if (primes[i] > menor){
                        menor = primes[i];
                        idx = i;
                        break;
                    }
                }
                cout << "menor : " << menor << endl;
            }
            cout << res.size() << endl;
        }             
    }
    return 0;
}































