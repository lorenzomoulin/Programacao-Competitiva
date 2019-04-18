#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

#define MAXN 10000009
ll sievesize;
bitset<MAXN> bs;
vector<ll> primes;

int idx;
ll x;
void sieve(ll n){
    sievesize = n;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= sievesize; ++i){
        if(bs[i]){
            
            for (ll j = i * i ; j <= sievesize; j += i){
                cout << j << endl;
                bs[j] = 0;
            
            }
            primes.push_back(i);
            idx++;
            if (primes.size() == x){
                cout << primes[(int)primes.size() - 1];   
                return;
            }
        }
    }
}


int main(){
    
    cin >> x;
    idx =0 ;
    sieve(12000000);
    
    
    cout << "\n";
    return 0;
}
