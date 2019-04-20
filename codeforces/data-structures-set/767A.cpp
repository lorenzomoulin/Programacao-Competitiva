#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
using namespace std;

typedef pair<int, int> ii;

bool comp(ii a, ii b){
    return a.first < b.first;
}

int main(){
    int n;
    cin >> n;
    ii a[n];
    rep(i, 0, n){
        int b;
        cin >> b;
        a[i] = ii(b, i);
        
    }
    make_heap(a, a + n, comp);
    int qtd = 0;
    rep(i, 0, n){
        if (i >= a[0].second){
            cout << a[0].first;
            pop_heap(a, a + n - qtd);
            qtd++;
            while(a[0].second <= i && qtd < n){        
                cout <<  " " << a[0].first;
                pop_heap(a, a + n - qtd);
                qtd++;
            }
            cout << "\n";
        }
        else {
            cout << "\n";
        } 
    }
    
    return 0;
}
