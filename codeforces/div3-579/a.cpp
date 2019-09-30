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
    //int n; cin >> n;
    int q, n;
    cin >> q;
    while (q--){
        cin >> n;
        int p[n], p1[n], p2[n], j, k;
        rep(i, 0, n){
            cin >> p[i];
            p[i] == 1 ? j = i: j;
            p[i] == n ? k = i: k;
        }
        bool can1 = true, can2 = true;
        p1[0] = 1;
        p2[0] = n;
        rep(i, 1, n){
            p1[i] = p[(j + i) % n];
            p2[i] = p[(k + i) % n];
            
        }
        rep(i,1 , n){
            if (p1[i] < p1[i-1])
                can1 = false;
            if (p2[i] > p2[i-1])
                can2 = false;
        }
        if (can1 || can2)
            cout << "YES\n";
        else
            cout << "NO\n";
    } 
    return 0;
}
