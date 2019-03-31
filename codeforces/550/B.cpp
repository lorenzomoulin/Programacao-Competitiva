#include <bits/stdc++.h>

using namespace std;



int main(){
    int n;
    cin >> n;
    int a[n];
    bool deleted[n];
    
    //delete odd
    int res_odd = 0;
    bool odd;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    memset(deleted, false, sizeof deleted);
    bool acabou = true;
    sort(a, a + n, greater<int>());
    for(int i = 0; i < n; i++){
        if (a[i] % 2){
            deleted[i] = true;
            odd = true;
            acabou = false;
            //res_odd++;
            break;
        }
    }
    

    for (int i = 0; i < n && !acabou; i++){
        acabou = true;
        if(odd){
            for (int j = 0; j < n; j++){
                if(a[j] % 2 == 0 && !deleted[j]){
                    deleted[j] = true;
                    odd = false;
                    acabou = false;
                    //res_odd++;
                    break;
                }
               
                    
            }
        }
        else{
            for (int j = 0; j < n; j++){
                if(a[j] % 2 && !deleted[j]){
                    deleted[j] = true;
                    odd = true;
                    acabou = false;
                    //res_odd++;
                    break;
                }
                
            }
        }
   
    }
    for (int i = 0; i < n; i++){
        if(!deleted[i])
            res_odd += a[i];
    }


    
    //delete even
    memset(deleted, false, sizeof deleted);
    int res_even = 0;
    acabou = true;
    for(int i = 0; i < n; i++){
        if (a[i] % 2 == 0){
            deleted[i] = true;
            odd = false;
            acabou = false;
            //res_even++;
            break;
        }
    }

    
    for (int i = 0; i < n && !acabou; i++){
        acabou = true;
        if(odd){
            for (int j = 0; j < n; j++){
                if(a[j] % 2 == 0 && !deleted[j]){
                    deleted[j] = true;
                    odd = false;
                    acabou = false;
                    //res_even++;
                    break;
                }
                
                    
            }
        }
        else{
            for (int j = 0; j < n; j++){
                if(a[j] % 2 && !deleted[j]){
                    deleted[j] = true;
                    odd = true;
                    acabou = false;
                    //res_even++;
                    break;
                }
              
            }
        }

     }
     
    for (int i = 0; i < n; i++){
        if(!deleted[i])
            res_even += a[i];
    }
   
    
    cout << min(res_odd, res_even) << endl;    
    return 0;
}
