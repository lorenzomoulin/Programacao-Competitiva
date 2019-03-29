#include <iostream>

using namespace std;

int main(){
    int t, cases = 1;
    cin >> t;
    
    while(t--){
        int l,w,h;
        cin >> l >> h >> w;
        if (l <= 20 && w <= 20 && h <= 20)
            cout << "Case " << cases << ": good\n";
        else 
            cout << "Case " << cases << ": bad\n";
        cases++;
    }
    return 0;
}
