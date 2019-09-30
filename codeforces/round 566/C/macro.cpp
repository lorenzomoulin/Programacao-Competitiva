#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<string, string> pss;
struct word{
    string s;
    int qtvowel;
    char lvowel;
};

bool isvowel(char a){
    return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
}

int vowelnumber(string a){
    int va = 0;
    rep(i, 0, sz(a))
        if (isvowel(a[i]))
            va++;
    return va;
}

char lastvowel(string a){
    for (int i = sz(a) - 1; i >= 0; i--){
        if (isvowel(a[i])){
            return a[i];
        }
    }
}

bool cmp(word a, word b){
    if (a.qtvowel == b.qtvowel ){       
        return a.lvowel < b.lvowel;
    }
    return a.qtvowel < b.qtvowel;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string text[n];
    word in[n];
    rep(i, 0, n){
        cin >> text[i];
        in[i].s = text[i];
        in[i].qtvowel = vowelnumber(text[i]);
        in[i].lvowel = lastvowel(text[i]);
    }
    sort(in, in + n, cmp);
    
    vector<pss> fcol, scol;
    int res = 0;
    
    for(int i = 0; i < n - 1; i++){
        if (in[i].qtvowel == in[i + 1].qtvowel){
            if (in[i].lvowel == in[i + 1].lvowel){
                scol.push_back(pss(in[i].s, in[i + 1].s));
                i++;
            }
            else
                fcol.push_back(pss(in[i].s, in[i + 1].s)), i++;
        }
    }
    
    if (sz(scol) < sz(fcol))
        cout << sz(scol) << '\n';
    else {
        cout << (sz(fcol) + (sz(scol) - sz(fcol)) / 2) << '\n';
    }
    
    
    int i = 0, j =0 ;
    while (j < sz(scol) && i < sz(fcol)){
        cout << fcol[i].first << " " << scol[j].first << "\n" << fcol[i].second << " " << scol[j].second << '\n';
        i++, j++; 
        
    }
    while (j < sz(scol) - 1){
        cout << scol[j].first << " " << scol[j + 1].first << "\n" << scol[i].second << " " << scol[j + 1].second << '\n';
        j++;
    }
    return 0;
}
