#include <bits/stdc++.h>

using namespace std;


int main(){
    bitset<2000> bs;
    string s;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        bs.reset();
        cin >> s;
        for (auto &a : s){
            bs = (bs << 3);
            bs = (bs << 1);
            bs |= bitset<2000>(a - '0');
            cout << bs << "\n";
        }
        int res = 0;
        for (int k = 0; k < 2000; ++k){
            if (bs[k])
                res++;
        }
        cout << res << "\n";
        cout << bs << "\n";
    }
    
    return 0;
}
