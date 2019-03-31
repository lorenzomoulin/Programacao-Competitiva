#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
    int cases = 1;
    while(true){
        int n, q;
        cin >> n >> q;
        if (!n && !q)
            break;
        cout << "CASE# " << cases << ":\n";
        int m[n];
        FOR(i, n){
            cin >> m[i];
        }
        sort(m, m + n);
        FOR(i, q){
            int query;
            cin >> query;
            bool flag = false;
            FOR(j, n){
                if(m[j] == query){
                    cout << query << " found at " << j + 1 << endl;
                    flag = true;
                    break;
                }
                
            }
            if (!flag)
                cout << query << " not found\n";
        }
        cases++;
    }
    return 0;
}
