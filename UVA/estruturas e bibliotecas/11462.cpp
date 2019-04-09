#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(true){
        int n;
        
        cin >> n;
        int a[n];
        if(!n)
            break;
        for(int i = 0; i < n; i++)
            cin >> a[i];
            
        sort(a, a + n);
        cout << a[0];
        for(int i = 1 ;i  < n; i++)
            cout <<" " <<  a[i];
        
        
        
            cout << endl;
        
    }
    return 0;
    
    
}
