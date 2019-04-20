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
    int n, m;
    cin >> n >> m;
    int a[n][m];
    int temp;
    rep(i, 0, n)
        rep(j, 0, m)
            cin >> a[i][j];
    int idx[n];
    temp = a[0][0];
    
    rep(i, 1, n)
        temp = (temp xor  a[i][0]);
    //cout << temp << endl;
    if (temp > 0){
        cout << "TAK\n1";
        rep(i, 1, n){
            cout << " 1";        
        }
        cout << "\n";
        return 0;
    }
   
        
    bool dif = false;
    memset(idx, 1, sizeof idx);
    rep(i, 0, n)
        idx[i] = 1;
    //cout << endl; 
    rep(i, 0, n){
        rep(j, 0, m){
            if (a[i][j] != a[i][0]){
                //cout << i << endl;
                
                idx[i] = j + 1;
                dif = true;
                break;
            }
            if(dif)
                break;
        }
    }
    
    if (dif){
        cout << "TAK\n" << idx[0];
        rep(i, 1, n){
            cout << " " << idx[i];        
        }
        cout << "\n";
        return 0;
    }
    else {
        cout << "NIE\n";
    }
    
            
    return 0;
}
