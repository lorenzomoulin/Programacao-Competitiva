#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxa = 2e5;
const int inf = 0x3f3f3f3f;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n, k;
    cin >> n >> k;
    int a[n];
    rep (i, 0, n){
        cin >> a[i];
    }
    sort(a, a + n);
    int res = inf, curk = 0;
    rep (i, 0, a[n - 1] + 1){
        curk = 0;
        int acc = 0;
        
        int j = 0;
        while(j < n && curk < k){
            int temp = 0;
            int t = a[j];
            while (t > i){
                t >>= 1;
                temp++;
                
            }
            
            if (t == i){
                    curk++;
                    acc += temp;
                }
            j++;
        }
        if (curk >= k)
            res = min(res, acc);
    }
    cout << res << '\n';
    return 0;
}
