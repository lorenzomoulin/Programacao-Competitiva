#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
    //cin.sync_with_stdio(0); cin.tie(0);
    //cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    int a[n], b[n];
    rep(i, 0, n) cin >> a[i];
    sort(a, a + n);
    int i = 0, j = n - 1;
    rep(k, 0, n){
        if (k & 1){
            b[j--] = a[k];
        }
        else
            b[i++] = a[k];
    }
    int res = 0;
    for(int k = 0; k < n - 1; k ++){
        res += b[k]*b[k + 1];
    }
    res += b[n-1]*b[0];
    printf("%.3lf\n", (double)res*(sin((M_PI/180.0)*(360.0/n)))/2.0);
    return 0;
}
