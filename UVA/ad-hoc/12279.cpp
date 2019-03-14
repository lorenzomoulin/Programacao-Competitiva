#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int  cases = 1;
    
    while(true){
        
        int n;
        cin >> n;
        if (!n) break;
        int x= 0, y = 0;
        for (int i = 0; i < n; i++){
            int a;
            cin >> a;
            if (a)
                x++;
            else
                y++;
        }
        cout << "Case " << cases << ": " <<  x - y << endl;
        cases++;
    }
    return 0;
}
