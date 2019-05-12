#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n;
    int c[n];
    for(int i = 0; i < n; i++)
        cin >> c[i];
    cin >> k;
    for(int i = 0; i < n; i++){
        int *l, *r;
        
        
        
        if(binary_search(c, c + i, k - c[i])){
            l = lower_bound(c, c + i, k - c[i]);
            if (l != c + i){
                cout << min(c[l - c], c[i]) << " " << max(c[l - c], c[i]) << "\n"; 
                return 0;
            }
        }
        if(binary_search(c + i + 1, c + n, k - c[i])){
            r = lower_bound(c + i + 1, c + n, k - c[i]);
            if(r != c + n){
                cout << min(c[r - c], c[i]) << " " << max(c[r - c], c[i]) << "\n"; 
                return 0;
            }
        }
    }
    return 0;
}
