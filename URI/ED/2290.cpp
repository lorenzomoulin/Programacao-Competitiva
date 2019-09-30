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

    while (true){
        int n;    
        cin >> n;
        if(!n) break;
        map<string, int> mapa;
        rep(i, 0, n) {
            string a; cin >> a;
            map<string, int>::iterator it = mapa.find(a);
            if (it != mapa.end())
                it->second++;
            else
                mapa.insert({a, 1});
        }
        vector<string> res;
        trav(a, mapa){
            if (a.second & 1)
                res.push_back(a.first);
        }
        sort(all(res));
        cout << res[0] << ' ' << res[1] << '\n';
    }
    return 0;
}
