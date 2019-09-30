#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define inf 0x3f3f3f3f
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int ent[5];
    cin >> ent[0] >> ent[1] >> ent[2] >> ent[3];
    sort(ent, ent+4);
            
    
    cout << abs((ent[3]+ent[0])-(ent[2]+ent[1])) << '\n';
    
    
    
    return 0;
}
