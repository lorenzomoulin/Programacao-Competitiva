#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define maxn 10000009
ll sievesize;
bitset<maxn> bs;
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

const ll MAXN = 1e5+7;
const ll MOD = 1e9+7;
const ll neutral = 1;
#define comp(a, b) ((a)*(b))

class SegmentTree {
	vector<ll> a;
	int n;
public:
	SegmentTree(ll* st, ll* en) {
		int sz = int(en-st);
		for (n = 1; n < sz; n <<= 1);
		a.assign(n << 1, neutral);
		for(int i=0; i<sz; i++) a[i+n] = st[i];
		for(int i=n+sz-1; i>1; i--)
			a[i>>1] = comp(a[i>>1], a[i])%MOD;
	}
	void update(int i, ll x) {
		a[i += n] += x; //substitui
		for (i >>= 1; i; i >>= 1)
			a[i] = comp(a[i<<1], a[1+(i<<1)])%MOD;
	}
	ll query(int l, int r) {
		ll ans = neutral;
		for (l+=n, r+=n+1; l<r; l>>=1, r>>=1) {
			if (l & 1) ans = comp(ans, a[l++])%MOD;
			if (r & 1) ans = comp(ans, a[--r])%MOD;
		}
		return ans;
	}
};

int main() {
   // cin.sync_with_stdio(0); cin.tie(0);
    sieve((ll)1e6+7);
    ll n, p, qtd = 2, cont = 1;
    vector<ll> qr, ini;
    set<ll> pr;
    map<ll, int> mpr;
    ll arr[MAXN];
    rep(i, 0, MAXN) arr[i] = 1;
    SegmentTree st(arr, arr + MAXN);
    scanf("%lld", &n);
    ll N = n;
    ll PF_idx = 0, PF = primes[PF_idx];
	while (PF * PF <= N) { 
		while (N % PF == 0) {
			N /= PF;
			ini.push_back(PF);
			pr.insert(PF);
		}
		PF = primes[++PF_idx];
	}
	if (N != 1) ini.push_back(N), pr.insert(N);
	
    while (scanf("%lld", &p) != EOF){        
        pr.insert(p);
        qr.push_back(p);
    }
    int j = 0;
    trav(a, pr){
        mpr[a] = j++;
    }
    trav(a, ini)
        st.update(mpr[a], 1);
    trav(a, qr){
        st.update(mpr[a], 1);
        printf("%lld\n", st.query(0, mpr[a] - 1));
    }
    
    
    return 0;
}
