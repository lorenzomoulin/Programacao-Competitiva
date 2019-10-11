#include <bits/stdc++.h>

using namespace std;

int main(){
    long long a[4] = {2, 4, 6, 8};
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 19; ++j)
            a[i] *= a[i];
        cout << a[i] % 100 << '\n';
    }
    return 0;
}
