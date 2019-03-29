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
    //cout << "oi\n";
    while(t--){
        ll n, k;
        cin >> n >> k;
        if (n <= k)
            cout << n - 1 << endl;
        else{
            ll res = 0;
            
            ll menor = 2;
            int idx = 0;
            for (int i = 0; i < primes.size(); i++){
                if (primes[i] > k){
                    menor = primes[i];
                    idx = i;
                    break;
                }
                    
            }
            bs.set();
            bs[0] = bs[1] = 0;
            for (ll i = idx; primes[i] <= n; i++){
		        if(bs[primes[i]]){
		            for(ll j = primes[i]; j <= (ll)n; j += primes[i])
		                bs[j] = 0;
		            
		        }
		    }
		    
		    
            for (int i = 2; i <= n; i++)
            	if(bs[i])
            		res++;
            cout << res<< endl;
        }             
    }
    return 0;
}































