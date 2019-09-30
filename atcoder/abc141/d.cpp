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
    cin.exceptions(cin.failbit);
    priority_queue<int> pq;
    int n, m;
    cin >> n >> m;
    rep(i,0, n){
        int a;
        cin >> a;
        pq.push(a);
    }
    while(m--){
        int t = pq.top()/2;
        pq.pop();
        pq.push(t);
    }
    ll res  = 0;
    while (sz(pq)){
        res += pq.top();
        pq.pop();
        
    }
    cout << res << '\n';
    return 0;
}
