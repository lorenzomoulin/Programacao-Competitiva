#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define INFLL 0x3f3f3f3f3f3f3f3f
typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll mod = 1e9+7;
#define MAXN 10000009
ll sievesize, numDiffPF[MAXN];
bitset<MAXN> bs;
vector<ll> primes;
set<ll> px;
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

set<ll> primeFactors(ll N) {
	set<ll> factors;
	ll PF_idx = 0, PF = primes[PF_idx];
	while (PF * PF <= N) { 
		while (N % PF == 0) {
			N /= PF;
			factors.insert(PF);
		}
		PF = primes[++PF_idx];
	}
	if (N != 1) factors.insert(N);
	return factors;
}

template<typename T>
T modExp(T a, T b, T m) {
    if (b == 0) return (T)1;
    T c = modExp(a, b / 2, m);
    c = (c * c) % m;
    if (b % 2 != 0) c = (c*a) % m;
    return c;
}

template<typename T>
T modMul(T a, T b, T m) {
	T x = 0, y = a % m;
	while (b > 0) {
		if (b % 2 == 1) x = (x + y) % m;
		y = (y * 2) % m; b /= 2;
	}
	return x % m;
}

vector<pair<ll, int>> vpli;


ll legendre(ll x, ll p) {
	ll ans = 0;
	ll prod = p;
	while(prod <= x) {
		ans += x/prod;
		if (p > INFLL/prod) break;
		prod *= p;
	}
	return ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    sieve((ll)1e6+9);
    ll x, t;ll n;
    
    cin >> x >> n;
    px = primeFactors(x);
    ll res = 1;
    trav(a, px){
        //vpli.push_back({a, legendre(n, a)});
        //cout << a << " " << legendre(n, a) << '\n';
        res = modMul(res, modExp(a, legendre(n, a), mod), mod);
    }
    
    
    cout << res << '\n';
    return 0;
}
