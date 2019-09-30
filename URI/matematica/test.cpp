#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define MAXN 1123456
#define MAXP 11234567
const int MOD = 1e9 + 7;
ll sievesize;
bitset<MAXN> bs;
vector<ll> primes;
int factors[MAXP];
 
const int neutral = 1;
#define comp(a,b) ((a)*(b))%MOD
 
class SegmentTree {
    vector<ll> a;
    int n;
 
public:
    SegmentTree(int*st,int*en) {
        int sz = int(en-st);
        for(n=1; n<sz; n<<=1);
        a.assign(n<<1, neutral);
        for(int i=0; i<sz; i++) a[i+n] = st[i]+neutral;
        for(int i=n+sz-1; i>1; i--)
            a[i>>1] = comp(a[i>>1], a[i]);
    }
 
    void update(int i, int x) {
        a[ i+= n ] = x+neutral;
        for(i >>= 1; i; i >>= 1)
            a[i] = comp(a[i<<1], a[1+(i<<1)]);
    }
 
    ll query(int l, int r) {
        ll ans = neutral;
        for(l+=n, r+=n+1; l<r; l>>=1, r>>=1) {
            if(l & 1) ans = comp(ans, a[l++]);
            if(r & 1) ans = comp(ans, a[--r]);
        }
        return ans;
    }
};
 
void sieve(ll n){
    sievesize = n+1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i=2; i<=sievesize; i++)
    {
        if(bs[i]){
            for(ll j=i*i; j<=(ll)sievesize; j+=i)
                bs[j] = 0;
            primes.push_back(i);
        }
    }
}
 
void primeFactors(ll N)
{
    ll PF_idx = 0, PF = primes[PF_idx];
    while(PF*PF <= N)
    {
        while(N%PF == 0)
        {
            N /= PF;
            factors[PF]++;
        }
        PF = primes[++PF_idx];
    }
    if(N!=1) factors[N]++;
}
 
int main()
{
    sieve(1000002);
 
    ll n_in;
    cin >> n_in;
    primeFactors(n_in);
    // cout << factors[0] << endl;
    // cout << factors[1] << endl;
    // cout << factors[2] << endl;
    // cout << factors[3] << endl;
    // cout << factors[4] << endl;
    // cout << factors[5] << endl;
    // cout << endl << endl;
 
    SegmentTree seg = SegmentTree(factors, factors+MAXP);
 
    int p;
    while(scanf("%d",&p)!=EOF)
    {
        cout << seg.query(0, p-1)%MOD << endl;
        factors[p]++;
        seg.update(p, factors[p]);
    }
 
    return 0;
}
