#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define print(a) trav(x, a) cout << x << " "; cout << '\n';
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, m;
    cin >> n >> m;
    if (m == 0){
        cout << "1\n";
        return 0;
    }
    
    int ar[n + 1], res = 1;
    bool c[n + 1];
    
    rep(i, 1, n + 1){
        c[i] = true;
        ar[i] = 2;
    }
    print(ar)
    rep(j, 0, m){
        bool achou = false;
        rep(i, 1, n + 1){
            if (ar[i] == 2){
                if (i == 1){
                    ar[i] = 0;
                    if(ar[i + 1])ar[i + 1]--;
                    if(ar[n])ar[n]--;
                    
                }
                
                else if (i == n){
                    ar[i] = 0;
                    if(ar[1])ar[1]--;
                    if(ar[i - 1])ar[i-1]--;
                }
                else{
                    ar[i] = 0;
                    if(ar[i + 1])ar[i + 1]--;
                    if(ar[i - 1])ar[i - 1]--;
                }
                c[i] = false;
                achou = true;
                print(ar)
                print(c)
                break;
                
            }
        }
        if (!achou){
            achou = false;
            rep(i, 1, n + 1){
                if (ar[i] == 1){
                    if (i == 1){
                    ar[i] = 0;
                    if(ar[i + 1])ar[i + 1]--;
                    if(ar[n])ar[n]--;
                    
                    }
                    
                    else if (i == n){
                        ar[i] = 0;
                        if(ar[1])ar[1]--;
                        if(ar[i - 1])ar[i-1]--;
                    }
                    else{
                        ar[i] = 0;
                        if(ar[i + 1])ar[i + 1]--;
                        if(ar[i - 1])ar[i - 1]--;
                    }
                    c[i] = false;
                    achou = true;
                    print(ar)
                    print(c)
                    break;
                    
                }
            }
        }
    }
    cout << res << '\n';
    return 0;
}
