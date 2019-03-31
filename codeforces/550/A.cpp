#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;cin >> t;
    while(t--){
        string a;
        cin >> a;    
        bool flag = true;
        sort(a.begin(), a.end());
        for(int i = 0; i < a.size() -1 ; i++){
            if(a[i + 1] - a[i] != 1){
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "Yes\n";
        else 
            cout << "No\n";
    }
    return 0;
}
