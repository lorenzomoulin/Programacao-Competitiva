#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define debug(x) cout << #x << ": " << x << "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    string t, s, slinha, temp = "";
    cin >> t;
    //temp = t;
    int pos = -1, cont = 0, cont_esq =0 , cont_dir = 0;
    rep(i, 0, sz(t)){
        if(t[i] != 'a')
            temp += t[i], cont++, cont_dir++;
        else
            pos = i, cont_esq += cont_dir, cont_dir = 0;
    }
    //ok
    if(cont_dir < cont_esq){
        cout << ":(\n";
        return 0;
    }
    if (pos == sz(t) - 1 && cont > 0){
        cout << ":(\n";
        return 0;
    }
    //cout << temp << endl;
    if (sz(temp) % 2 == 0){
        
        rep(i, 0, sz(temp) / 2){
            //debug(temp[i]);
            //debug(temp[i + sz(temp)/2]);
            if (temp[i] != temp[i + sz(temp)/2]){
                
                cout << ":(\n";
                
                return 0;
            }
        }
        int already_printed = 0;
        rep(i, 0, sz(t)){
            if (already_printed == cont/2){
                while(t[i] == 'a'){
                    cout << 'a';
                    i++;
                }
                cout << "\n";
                return 0;
            }
                
            if (t[i] != 'a'){
                already_printed++;            
            }
            cout << t[i];
        }
        cout << "\n";
    }
    else {
        cout << ":(\n";
        
    }
    
    return 0;
}
