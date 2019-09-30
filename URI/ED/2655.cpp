#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll neutral = 0;
#define comp(a, b) ((a)|(b))

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
			a[i>>1] = comp(a[i>>1], a[i]);
	}
	void update(int i, ll x) {
		a[i += n] = x; //substitui
		for (i >>= 1; i; i >>= 1)
			a[i] = comp(a[i<<1], a[1+(i<<1)]);
	}
	ll query(int l, int r) {
		ll ans = neutral;
		for (l+=n, r+=n+1; l<r; l>>=1, r>>=1) {
			if (l & 1) ans = comp(ans, a[l++]);
			if (r & 1) ans = comp(ans, a[--r]);
		}
		return ans;
	}
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    bitset<1> bs;
    cout << sizeof(bitset<1>) << '\n';
    int n, q, m;
    cin >> n >> q >> m;
    ll v[n];
    rep(i, 0, n) {
        cin >> v[i];
        if (v[i] > m)
            v[i] = 0;
        else
            v[i] = 1LL << v[i];
    }
    
    SegmentTree st(v, v + n);
    while (q--){
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1){
            ll res = st.query(a-1, b-1), c = 0;
            while (res > 0) c++, res -= (res & -res);
            cout << c << '\n';
        }
        else{
            if (b <= m)
                st.update(a-1, 1LL << b);
            else
                st.update(a-1, 0);
        }
    }
    return 0;
}
