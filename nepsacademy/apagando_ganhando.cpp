#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i  <(b); ++i)
using namespace std;

bool comp(int a, int b){ return a > b;}

int main(){
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    rep(i, 0, n)
        cin >> a[i];
    make_heap(a.begin(), a.end(),  comp);

    rep(i, 0, d){
        pop_heap(a.begin(), a.end());
        
        a.pop_back();
        rep(i, 0, a.size())
        cout <<  a[i] << endl;
        cout << endl;
    }
    
    for(auto &b: a )
        cout << b << endl;
    return 0;
}
