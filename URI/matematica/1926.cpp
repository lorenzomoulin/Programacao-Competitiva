#include <bits/stdc++.h>

#define MAXN 10000009
#define rep(i, a, b) for(int i = a; i < (b); ++i)
//#define trav(a, x) for(auto &a: x)
#define sz(x) (int)x.size()
#define endl "\n"
#define all(x) x.begin(), x.end()
using namespace std;
typedef vector<int> vi;
typedef long long ll;

bitset<MAXN> bs;
ll sievesize;
vi primes;
vi gemeos;

void sieve(ll n){
    sievesize = n;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= sievesize; i++){
        if(bs[i]){
            for(ll j = i * i; j <= sievesize ; j += i)
                bs[j] = 0;
                
            primes.push_back(i);  
            
        }
    }
    rep(i, 1, sz(primes) - 1){
        if (primes[i] - primes[i - 1] == 2 || primes[i + 1] - primes[i] == 2)
            gemeos.push_back(primes[i]);
    }
    if (primes[sz(primes) - 1] - primes[sz(primes) - 2] == 2 )
        gemeos.push_back(primes[sz(primes) - 1]);
}


int main(){
    sieve(1000009);
    int q;
    cin >> q;
    //rep(i, 0, sz(gemeos))
       //cout << gemeos[i] << endl;
    int res[1000001], atual = 0;
    res[0] = 0;
    rep(i, 1, 1000001){
        if (binary_search(all(gemeos), i)){
            res[i] = atual + 1;
            atual++;
            
        }
        else
            res[i] = atual;
    }
    
    //rep(i, 0, sz(st.s)){
        //cout << st.s[i] << endl;
    //}
    
    while(q--){
        int x, y;
        cin >> x >> y;
        if (y > x)
            cout << res[y] - res[x - 1]<< endl;
        else
            cout << res[x] - res[y - 1] << endl;
    }
   
    return 0;
}
