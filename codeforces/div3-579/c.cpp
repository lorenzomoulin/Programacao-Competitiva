#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MAXN 10000009
ll sievesize, numDiffPF[MAXN];
bitset<MAXN> bs;
vector<ll> primes;

void sieve(ll n) {
	sievesize = n + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= sievesize; i++) {
		if (bs[i]) {
			for (ll j = i * i; j <= (ll)sievesize; j += i) bs[j] = 0;
			primes.push_back(i);
		}
	}
}

ll numDiv(ll N) {
	ll i = 0, p = primes[i], ans = 1;
	while (p * p <= N) {
		ll power = 0;
		while (N % p == 0) { N /= p; power++; }
		ans *= (power + 1);
		p = primes[++i];
	}
	if (N != 1) ans *= 2;
	return ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    //sieve(1000000);
    int n;
    cin >> n;
    ll a[n], x, res;
    rep (i, 0, n) cin >> a[i];
    x = a[0];
    rep (i, 1, n){
        x = __gcd(x, a[i]);
    }
    
    int cnt = 0; 
    for (ll i = 1; i*i <= x; i++) { 
        if (x % i == 0) { 
            // If divisors are equal, 
            // count only one 
            if (x / i == i) 
                cnt++; 
  
            else // Otherwise count both 
                cnt = cnt + 2; 
        } 
    } 
    
    /*set<ll> div;
    ll N = x;
    div.insert(1);
    div.insert(x);
    for (ll i = 2LL; i * i <= N; i++){
        while (x % i == 0){
            div.insert(i);
            if (i != x/i){
                div.insert(x/i);
            }
            x /= i;
        }
    }*/
    cout << cnt << '\n';
    return 0;
}
