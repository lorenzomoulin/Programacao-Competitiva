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
    
    const int n = 5;
    int a[2*n + 9];
    rep(i,0 , 2*n)
        a[i] = i + 1;
    int sum[2*n + 9];
    memset(sum, 0, sizeof sum);
    while (next_permutation(a, a + 2*n)){
        
        bool valid = true;
        memset(sum, 0, sizeof sum);
        rep(i, 0, 2*n){
            rep(k, i, i + n){
                sum[i] += a[k % (2*n)]; 
            } 
        }
        /*rep(i, 0, 2*n){
            cout << sum[i] << ' ';
            
        }
        cout << '\n';*/
        rep(i, 0, 2*n){
            rep(j, i + 1, 2*n){
                if (abs(sum[i] - sum[j]) > 1){
                    valid = false;
                    break;
                }
            }
            if (!valid)
                break;
        }
        if (valid){
            rep(i, 0, 2*n){
                cout << a[i] << ' ';
                
            }
            cout << '\n';
        }
    }
        
    return 0;
}
