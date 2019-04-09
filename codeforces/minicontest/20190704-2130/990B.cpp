#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){

    int n, k;
    cin >> n >> k;
    
    int a[n],freq[1000005];
    vi b;
    memset(freq, 0, sizeof freq);
    rep(i, 0, n){
        cin >> a[i];
        freq[a[i]]++;
    }
    rep(i, 0, 1000005){
        if (freq[i])
            b.pb(i);
    }
    int res = 0;
    rep(i, 0, sz(b) - 1){
        if(b[i] < b[i+1]){
            if(b[i + 1] <= b[i] + k)
                res += freq[b[i]];
        }
    }
    cout << n - res << endl;
    return 0;
}
