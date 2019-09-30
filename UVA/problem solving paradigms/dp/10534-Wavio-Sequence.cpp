#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int lis(int arr[], int l, int r, bool lr){
    multiset<int> s;
    multiset<int>::iterator it;
    
    if (lr){
        rep(i, l, r + 1){
            s.insert(arr[i]);
            it = ++s.lower_bound(arr[i]);
            if (it != s.end())
                s.erase(it);
        }
    }
    else {
        for (int i = r; i >= l; i--){
            s.insert(arr[i]);
            it = ++s.lower_bound(arr[i]);
            if (it != s.end())
                s.erase(it);
        }
    }
    return sz(s);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    int arr[10009];
    while (cin >> n){
        rep(i, 0, n){
            cin >> arr[i];
        }
        int res = 1;
        rep(i, 0, n){
            int l = lis(arr, 0, i, true);
            int r = lis(arr, i + 1, n - 1, false);
            cout << "L: " << l << ", R: " << r << '\n';
            if (abs(r - l) == 1)
                res = max(res, r + l);
        }
        cout << res << '\n';
    }
    return 0;
}
