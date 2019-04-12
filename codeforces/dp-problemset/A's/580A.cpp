#include <bits/stdc++.h>
#define rep(i, a, b) for(int i =a ; i < (b); ++i)
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int atual = 1, maximum = 0;
    rep(i, 0, n){
        cin >> a[i];
        
    
    }
     
    rep(i, 1, n){
        if (a[i] >= a[i-1])
            atual++;
        else{
            if(atual > maximum)
                maximum = atual;
            atual = 1;
            
        }
        
        
    }
    if (atual > maximum )
        maximum = atual;
    cout << maximum << endl;
    return 0;
}
