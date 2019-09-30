#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MOD 1000000007
ll f[100010];

void calc(){
    f[0] = 1;
    rep(i, 1, 100010){
        f[i] = (i*f[i-1]) % (MOD);
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    calc();
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        cout << f[n] << '\n';
    }
   return 0;
}
