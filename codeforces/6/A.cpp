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
    cin.sync_with_stdio(0); cin.tie(0);
    int a[4];
    rep(i, 0, 4)    cin >> a[i];
    sort(a, a + 4);
    rep(i, 0, 4)rep(j, i + 1, 4)rep(k, j + 1, 4)
        if(a[i] + a[j] > a[k])
        {
            cout << "TRIANGLE\n";
            return 0;
        }
                
    rep(i, 0, 4)rep(j, i + 1, 4)rep(k, j + 1, 4)
        if(a[i] + a[j] == a[k])
        {
            cout << "SEGMENT\n";
            return 0;
        }
    cout << "IMPOSSIBLE\n";
    return 0;
}
