#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e5 + 9;
ll ft[MAXN];

void update(int i, int x){
    for(; i<=MAXN; i += (i & -i)) ft[i] += x;
}

ll rsq(int b){
    ll q = 0;
    for(; b > 0; b -= (b & -b)) q += ft[b];
    return q;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    while (true){
        int n;
        cin >> n;
        if (!n) break;
        memset(ft, 0, sizeof ft);
        ll freq[n], res = 0;
        rep(i, 0, n)    cin >> freq[i];
        for (int i = n - 1; i >=0 ; i--){
            res += rsq(freq[i]-1); //quantos números menores que freq[i] já estão na BIT??
            update(freq[i], 1); //inserimos freq[i] na BIT
        }        
        cout << (res & 1 ? "Marcelo" : "Carlos") << '\n';
    }
    return 0;
}
