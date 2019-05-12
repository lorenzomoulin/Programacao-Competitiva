#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
using namespace std;
typedef long long ll;
#define MAXK 1009
ll n, k, m, a[MAXK], f[MAXK];

void fk(){
    rep(i, n + 1, k + 1){
        rep(j, 1, n + 1){
            f[i] = (f[i] + a[j]*f[i - j] % m) % m;
        }
    }
}

int main(){
    cin >> n >> k >> m;
    memset(f, 0, sizeof f);
    rep(i, 1, n + 1)
        cin >> a[i];
    rep(i, 1, n + 1)
        cin >> f[i];
    fk();
    cout << f[k] % m << "\n";
    return 0;
}
