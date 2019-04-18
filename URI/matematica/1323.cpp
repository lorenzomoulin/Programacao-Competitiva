#include <bits/stdc++.h>

using namespace std;

int main(){
    while (true){
        int n;
        cin >> n;
        if (!n)
            break;
        int res = n*(2*n + 1)*(n + 1)/6;
        cout << res << "\n";
    }
    return 0;
}
