/*#include <bits/stdc++.h>

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
    
    
}*/

#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); i++)
using namespace std;

int main(){
    while(true){
        int n;
        scanf("%d", &n);
        if(!n )
            break;
        int a[n], table[2000001];
        memset(table, 0, sizeof table);
        rep(i, 0 , n){
            scanf("%d", &a[i]);
            table[a[i]]++;
            
        }
        //rep(i, 1, 6){
           // cout << table[i] << " ";
        //}
       // cout << "\n";
        bool primeiro = true;
        rep(i, 1, 2000001){
            while(table[i] > 0 ){
                if (primeiro){
                    //cout << i;
                    primeiro = false;
                    printf("%d", i);
                    
                }
                else{
                    printf(" %d", i);
                    //cout << " " << i;
                }
                table[i]--;
            }
        }
        printf("\n");
        //cout << "\n";
    }
    return 0;
}
