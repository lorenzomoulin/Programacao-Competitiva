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
    int q; cin >> q;
    while(q--){
        int n;
        cin >> n;
        int sticks[4*n];
        rep(i, 0, 4*n) cin >> sticks[i];
        sort(sticks, sticks + 4*n);
        int i =0, j = 4*n - 1, area = sticks[0]*sticks[4*n - 1], cur_a, cur_b;
        bool turn = false, can = true;
        while (i < j){
            if (turn){
                if (sticks[i] == cur_a && sticks[j] == cur_b){
                    i++, j--;
                    turn = false;
                }
                else{
                    can = false;
                    break;
                }
            }
            else{
                cur_a = sticks[i];
                cur_b = sticks[j];
                if (cur_a*cur_b != area){
                    can = false;
                    break;
                }
                i++, j--;
                turn = true;
            }
        }
        if (can)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
