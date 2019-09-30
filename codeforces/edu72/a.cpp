#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int s, e, i;

bool check(int x){
    return s + x > i + (e - x);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int t;
    cin >> t;
    while (t--){
        cin >> s >> i >> e;    
        int l = 0, r = 1e8, res = 1e9;
        while (l <= r){
            int mid = (l + r) / 2;
            if (check(mid)){
                res = min (res, mid);
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        cout << ((e - res + 1 >= 0) ? e - res + 1 : 0 )<< '\n';
    }    
    return 0;
}
