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
                //cout << j << endl;
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



bitset<12000010> e_composto;

int primo, cont;

void crivo(int n){
    cont = 0;
  e_composto[1] = 1; // 1 não é composto, mas o vetor na verdade guarda os números que não são primos
  for(int i = 2; i <= n; ++i){
    if(!e_composto[i]){
      for(int j = 2; j*i <= n; ++j){
        e_composto[i*j] = 1;
      }
      primo = i;
      cont++;
      if (cont == x)
        return;
    }
  }
  return;
}
int main(){
    
    cin >> x;
    idx =0 ;
    crivo(12000000);
    cout << primo;
    
    cout << "\n";
    return 0;
}
