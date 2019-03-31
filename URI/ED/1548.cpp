#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n], b[n];
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            a[i] = b[i] = temp;
        }
        int troca = 0;
        sort(a, a + n, greater<int>());
        for(int i  =0 ; i < n; i++){
            if(a[i] != b[i])
                troca++;
        }
        
        cout << n  -troca << endl;
    }
    return 0;
}
