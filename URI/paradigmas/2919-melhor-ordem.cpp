#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int lis(int arr[], int n){
    multiset<int> s;
    multiset<int>::iterator it;
    rep(i, 0, n){
        s.insert(arr[i]);
        
        it = ++s.lower_bound(arr[i]);      
        if (it != s.end())
            s.erase(it);  
    }
    return sz(s);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin >> n){
        int a[n];
        rep(i, 0, n)
            cin >> a[i];
        cout << lis(a, n) << '\n';
    }
    return 0;
}   
