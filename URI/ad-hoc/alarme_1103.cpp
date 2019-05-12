#include <bits/stdc++.h>

using namespace std;

int main(){
    while (true){
        int a, b, c, d;
        cin >> a >>b >> c >> d;
        if (a + b + c + d == 0)
            break;
        
        int res = c*60 + d - a*60 - b;
        if (res <= 0)
            res += 24*60;
        cout << res << '\n'; 
        
    }
    return 0;
}
