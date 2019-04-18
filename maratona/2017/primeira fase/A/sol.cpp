#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end() 
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MAXN 100009
#define MOD 9
#define INF 0x3f3f3f3f
const int neutral = 0;
#define comp(a, b) ((a)+(b))

class SegmentTree{
private:
    vi st, lazy;
    int size;
#define left(p) (p << 1)
#define right(p) (p >> 1)

    void build(int p, int l, int r, int *A){
        if(l == r) {
            st[p] = Al[l] ; return;
        }
        int m = (l + r) / 2;
        build(left(p), l, m, A);
        build(right(p), m + 1, r, A);
        st[p] = comp(st[left(p)], st[right(p)]);
    }
    
    void push(int p, int l, int r){
        st[p] += (t - l + 1)*lazy[p];
    }
}

int *add_arr(int *a, int *b){
    int c[MOD];
    rep(i, 0, MOD)
        c[i] = a[i] + b[i];
    return c;
}



int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n, q;
    cin >> n >> q;
    
    while (q--){
    
    }    
    return 0;
}
