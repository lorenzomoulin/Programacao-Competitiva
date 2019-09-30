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
    while(true){
        int n, m;
        cin >> n >> m;
        if(n + m == 0)  break;
        int head[n], h[m];
        rep(i, 0, n)
            cin >> head[i];
        rep (i, 0, m)
            cin >> h[i];
        
        sort(h, h + m);
        sort(head, head + n);
        int i,j;
        int cost = 0;
        for ( i = 0, j = 0; i<  n && j < m; j++){
            if (h[j] >= head[i])
                i++, cost += h[j];
            
        }
        if (i < n)
            cout << "Loowater is doomed!\n";
        else 
            cout << cost  << '\n';
    }
   return 0;
}
