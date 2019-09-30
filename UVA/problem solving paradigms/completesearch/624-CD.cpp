#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define debug(x) cout << #x << ": " << x << '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, duration[20];
//multiset<int> resp;
//vi resp;
stack<int> resp;
bitset<20> bs;

int solve(int cd, int space){
    if (cd == n) return 0;
    int npega = solve(cd + 1, space);
    if (space - duration[cd] >= 0){
        int pega = duration[cd] + solve(cd + 1, space - duration[cd]);
        return max(pega, npega);
    }
    return npega;
}

bool print(int cd, int total){
    //debug(cd);
    //debug(total);
    if (total == 0) return true;
    if (cd == n)    return false;
    bool esq = print(cd + 1, total);
    
    if (total - duration[cd] >= 0){
        bool dir = print(cd + 1, total - duration[cd]);
        if (dir){
            cout << duration[cd] << " ";
            return true;
        }
    }
    return false;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int space;
    while (cin >> space >> n){
        bs.reset();
        rep(i, 0, n)
            cin >> duration[i];
        int res = solve(0, space);
        print(0, res);
        cout << "sum:" << res << '\n';
    }
    
   return 0;
}
