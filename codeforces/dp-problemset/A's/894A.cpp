#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(s) (int)s.size()
using namespace std;

int main(){
    string s;
    cin >> s;
    int res = 0;
    rep(i, 0, sz(s) - 2){
       if(s[i] == 'Q'){
            rep(j, i + 1, sz(s) - 1){
                if(s[j] == 'A'){
                    rep(k, j + 1, sz(s)){
                        if (s[k] == 'Q')
                            res++;
                    }
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}
