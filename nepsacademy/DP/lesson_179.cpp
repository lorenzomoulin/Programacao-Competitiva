#include <bits/stdc++.h>

#define rep(i, a, b)    for(int i = a; i < (b); ++i)
#define pb push_back
using namespace std;

int lis(vector<int> &a){
    multiset<int> s;
    multiset<int>::iterator it;
    rep(i, 0, a.size()){
        s.insert(a[i]);
        it = s.upper_bound(a[i]);
        if(it != s.end())
            s.erase(it);
    }
    return s.size();
}

int main(){
    int n; 
    cin >> n;
    vector<int> a;
    rep(i, 0, n){
    
        int b; cin >> b; a.pb(b);
    }
    cout << lis(a) << "\n";
    return 0;
}
